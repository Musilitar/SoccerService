#include "stdAfx.h"
#include "TicketDAO.h"
#ifndef Databank_Offline
Connection* TicketDAO::con=NULL;

bool TicketDAO::removeTicket(int id)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblTickets where ticketID = ?");
		prep_stmt -> setInt(1, id);

		if (prep_stmt -> executeUpdate() == 0)
			return false;

		con -> commit();
		prep_stmt->close();
		delete prep_stmt;
	} 
	catch (SQLException &e) 
	{
		cout<<"PROBLEM: "<<e.what()<<endl;
		if (prep_stmt != NULL)
			delete prep_stmt;
		return false;
	}

	return true;
}

vector<Ticket*> TicketDAO::getAll()
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	vector<Ticket*> ticketen;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return ticketen;


		stmt = con -> createStatement();

		res = stmt -> executeQuery ("SELECT * FROM tblTickets");

		while (res -> next()) {
			Ticket* ticket = new Ticket(res->getInt(2), res->getInt(3), res->getInt(4), res->getInt(5), res->getInt(6),res->getInt(1));
			ticketen.push_back(ticket); 
		}
		stmt->close();
		delete stmt;
		delete res;
		//con ->close();
	} catch (SQLException &e) {
		cout<<"PROBLEM: "<<e.what()<<endl;
		con ->close();

		if(stmt != NULL)
			delete stmt;
		if(res != NULL)
			delete res;
	}


	return ticketen;
}

Ticket* TicketDAO::getTicket(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	Ticket* ticket= 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return ticket;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblTickets where ticketID = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
			ticket = new Ticket(res->getInt(2), res->getInt(3), res->getInt(4), res->getInt(5), res->getInt(6),res->getInt(1));

		}
		stmt->close();
		delete stmt;
		delete res;

		//con ->close();
	} catch (SQLException &e) {
		cout<<"PROBLEM: "<<e.what()<<endl;
		con ->close();

		if(stmt != NULL)
			delete stmt;
		if(res != NULL)
			delete res;
	}


	return ticket;
}

Ticket* TicketDAO::saveTicket(Ticket* ticket)
{
		PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || ticket == NULL)
			return 0;

		if(ticket->getTicketID()!=-1)
		{
			stringstream zoekopdracht;
			zoekopdracht<<"UPDATE tblTickets SET tblMatchenmatch_id = ? , tblVakkenvakID = ?, tblZitjeszitjesID = ?, tblKlantenklantID = ?, tblStadionstadionID = ? where ticketID = ";
			zoekopdracht<<ticket->getTicketID();
			prep_stmt = con -> prepareStatement(zoekopdracht.str());
		}
		else
		{
			con->setAutoCommit(0);//zet auto commit af
			prep_stmt = con-> prepareStatement ("INSERT INTO tblTickets VALUES (NULL, ?,?,?,?,?)");
		}

		prep_stmt -> setInt(1, ticket->getStadionID());
		prep_stmt -> setInt(2, ticket->getKlantID());
		prep_stmt -> setInt(3, ticket->getZitjeID());
		prep_stmt -> setInt(4, ticket->getVakID());
		prep_stmt -> setInt(5, ticket->getMatchID());

		int updatecount = prep_stmt->executeUpdate();
		
		//cout<<"Er zijn "<<updatecount<<" aantal rijen aangepast.";
		//con -> commit();
		prep_stmt->close();
		delete prep_stmt;
	} 
	catch (SQLException &e) 
	{
		cout<<"PROBLEM: "<<e.what()<<endl;
		if (prep_stmt !=NULL)
			delete prep_stmt;
		return 0;
	}

	
	if(ticket->getTicketID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");
		
		if(rs->next())
		{
			ticket -> setTicketID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}
	
	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return ticket;
}

vector<Ticket*> TicketDAO::findTicketByID(int ID)
{
	ResultSet *res = NULL;
	vector<Ticket*> ticketen;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return ticketen;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblTickets where ticketID = ?");
		prep_stmt -> setInt(1, ID);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Ticket* ticket = new Ticket(res->getInt(2), res->getInt(3), res->getInt(4), res->getInt(5), res->getInt(6),res->getInt(1));
			ticketen.push_back(ticket); 
		}
		prep_stmt->close();
		delete prep_stmt;
		delete res;
		//con ->close();
	} 
	catch (SQLException &e) 
	{
		cout<<"PROBLEM: "<<e.what()<<endl;
		con ->close();

		if(prep_stmt != NULL)
			delete prep_stmt;
		if(res != NULL)
			delete res;
	}
	return ticketen;
}
vector <Ticket*> TicketDAO::findTicketByKlantID(int klantid)
{
	ResultSet *res = NULL;
	vector<Ticket*> ticketen;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return ticketen;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblTickets where tblKlantenklantID = ?");
		prep_stmt -> setInt(1, klantid);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Ticket* ticket = new Ticket(res->getInt(2), res->getInt(3), res->getInt(4), res->getInt(5), res->getInt(6),res->getInt(1));
			ticketen.push_back(ticket); 
		}
		prep_stmt->close();
		delete prep_stmt;
		delete res;
		//con ->close();
	} 
	catch (SQLException &e) 
	{
		cout<<"PROBLEM: "<<e.what()<<endl;
		con ->close();

		if(prep_stmt != NULL)
			delete prep_stmt;
		if(res != NULL)
			delete res;
	}
	return ticketen;
}
#endif