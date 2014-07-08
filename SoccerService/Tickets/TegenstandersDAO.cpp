#include "stdAfx.h"

#include "TegenstandersDAO.h"
#ifndef Databank_Offline
Connection* TegenstandersDAO::con=NULL;

bool TegenstandersDAO::removeTegenstanders(int id)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblTegenstanders where tegenstandersID = ?");
		prep_stmt -> setInt(1, id);

		if (prep_stmt -> executeUpdate() == 0)
			return false;

		//con -> commit();
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

vector<Tegenstanders*> TegenstandersDAO::getAll()
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	vector<Tegenstanders*> tegenstandersen;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return tegenstandersen;


		stmt = con -> createStatement();

		res = stmt -> executeQuery ("SELECT * FROM tblTegenstanders");

		while (res -> next()) {
			Tegenstanders* tegenstanders = new Tegenstanders(res->getString(2), res->getInt(1));
			tegenstandersen.push_back(tegenstanders); 
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


	return tegenstandersen;
}

Tegenstanders* TegenstandersDAO::getTegenstanders(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	Tegenstanders* tegenstanders= 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return tegenstanders;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblTegenstanders where tegenstanderID = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
			tegenstanders = new Tegenstanders(res->getString(2), res->getInt(1));

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


	return tegenstanders;
}

Tegenstanders* TegenstandersDAO::maakTegenstanders(Tegenstanders* tegenstanders)
{
		PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || tegenstanders == NULL)
			return 0;

		if(tegenstanders->getTegenstanderID()!=-1)
		{
			stringstream zoekopdracht;
			zoekopdracht<<"UPDATE tblTegenstanders SET  tegenstanderNaam = ? where tegenstanderID = ";
			zoekopdracht<<tegenstanders->getTegenstanderID();
			prep_stmt = con -> prepareStatement(zoekopdracht.str());
		}
		else
		{
			con->setAutoCommit(0);//zet auto commit af
			prep_stmt = con-> prepareStatement ("INSERT INTO tblTegenstanders VALUES (?,NULL)");
		}

		prep_stmt -> setString(1, tegenstanders->getTegenstanderNaam());

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

	
	if(tegenstanders->getTegenstanderID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");
		
		if(rs->next())
		{
			tegenstanders -> setTegenstanderID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}
	
	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return tegenstanders;
}

Tegenstanders* TegenstandersDAO::findTegenstandersByID(int ID)
{
	ResultSet *res = NULL;
	Tegenstanders* tegenstanders = 0;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return tegenstanders;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblTegenstanders where tegenstanderID = ?");
		prep_stmt -> setInt(1, ID);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Tegenstanders* tegenstander = new Tegenstanders(res->getString(2), res->getInt(1));
			tegenstanders = tegenstander;
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
	return tegenstanders;
}

#endif
