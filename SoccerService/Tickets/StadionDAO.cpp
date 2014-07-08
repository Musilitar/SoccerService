#include "stdAfx.h"
#include "StadionDAO.h"
#ifndef Databank_Offline
Connection* StadionDAO::con=NULL;

bool StadionDAO::removeStadion(int id)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblStadion where stadionID = ?");
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

vector<Stadion*> StadionDAO::getAll()
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	vector<Stadion*> stadions;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return stadions;


		stmt = con -> createStatement();

		res = stmt -> executeQuery ("SELECT * FROM tblStadion");

		while (res -> next()) {
			Stadion* stadion = new Stadion(res->getString(2), res->getString(3), res->getString(4), res->getString(5), res->getInt(1));
			stadions.push_back(stadion); 
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


	return stadions;
}

Stadion* StadionDAO::getStadion(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	Stadion* stadion= 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return stadion;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblStadion where stadionID = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
			stadion = new Stadion(res->getString(2), res->getString(3), res->getString(4), res->getString(5), res->getInt(1));

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


	return stadion;
}

Stadion* StadionDAO::saveStadion(Stadion* stadion)
{
		PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || stadion == NULL)
			return 0;

		if(stadion->getStadionID()!=-1)
		{
			stringstream zoekopdracht;
			zoekopdracht<<"UPDATE tblStadion SET stadionTelefoon = ? , stadionAddress = ?, stadionManager = ?, stadionName = ? where ticketID = ";
			zoekopdracht<<stadion->getStadionID();
			prep_stmt = con -> prepareStatement(zoekopdracht.str());
		}
		else
		{
			con->setAutoCommit(0);//zet auto commit af
			prep_stmt = con-> prepareStatement ("INSERT INTO tblTicket VALUES (NULL, ?,?,?,?)");
		}

		prep_stmt -> setString(1, stadion->getStadionName());
		prep_stmt -> setString(2, stadion->getStadionManager());
		prep_stmt -> setString(3, stadion->getStadionAddress());
		prep_stmt -> setString(4, stadion->getStadionTelefoon());

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

	
	if(stadion->getStadionID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");
		
		if(rs->next())
		{
			stadion -> setStadionID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}
	
	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return stadion;
}

vector<Stadion*> StadionDAO::findStadionByID(int ID)
{
	ResultSet *res = NULL;
	vector<Stadion*> stadions;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return stadions;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblStadion where stadionID = ?");
		prep_stmt -> setInt(1, ID);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Stadion* stadion = new Stadion(res->getString(2), res->getString(3), res->getString(4), res->getString(5), res->getInt(1));
			stadions.push_back(stadion); 
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
	return stadions;
}

#endif