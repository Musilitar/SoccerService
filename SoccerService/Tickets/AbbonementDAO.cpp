#include "stdAfx.h"
#include "AbbonementDAO.h"
#ifndef Databank_Offline
Connection* AbbonementDAO::con=NULL;

bool AbbonementDAO::removeAbbonement(int id)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblAbbonement where abbonementID = ?");
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

vector<Abbonement*> AbbonementDAO::getAll()
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	vector<Abbonement*> abbonementen;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return abbonementen;


		stmt = con -> createStatement();

		res = stmt -> executeQuery ("SELECT DISTINCT a.abbonementID, k.klantID, v.vakID, t.abbonmentTypeID FROM tblAbbonement a, tblAbbonmentTypes t, tblKlanten k, tblVakken v WHERE a.tblAbbonementTypesabbonementTypeID = t.abbonementTypeID AND a.tblKlantenklantID = k.klantID AND a.tblVakkenvakID = v.vakID");

		while (res -> next()) {
			Abbonement* abbonement = new Abbonement(res->getInt(2), res->getInt(3), res->getInt(4),res->getInt(1));
			abbonementen.push_back(abbonement); 
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


	return abbonementen;
}

Abbonement* AbbonementDAO::getAbbonement(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	Abbonement* abbonementen = 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return abbonementen;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblAbbonement WHERE abbonementID = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
			Abbonement* abbonement = new Abbonement(res->getInt(2), res->getInt(3), res->getInt(4), res->getInt(1));
			abbonementen = abbonement;
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


	return abbonementen;
}

Abbonement* AbbonementDAO::maakAbbonement(Abbonement* abbonement)
{
		PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || abbonement == NULL)
			return 0;

		if(abbonement->getAbbonementID()!=-1)
		{
			stringstream zoekopdracht;
			zoekopdracht<<"UPDATE tblAbbonement SET tblAbbonementTypeabbonementTypeID = ? , tblVakkenvakID = ?, tblKlantenklantID = ? where abbonementID = ";
			zoekopdracht<<abbonement->getAbbonementID();
			prep_stmt = con -> prepareStatement(zoekopdracht.str());
		}
		else
		{
			con->setAutoCommit(0);//zet auto commit af
			prep_stmt = con-> prepareStatement ("INSERT INTO tblAbbonement VALUES (NULL, ?,?,?)");
		}

		prep_stmt -> setInt(1, abbonement->getAbbonementKlantID());
		prep_stmt -> setInt(2, abbonement->getAbbonementVakID());
		prep_stmt -> setInt(3, abbonement->getAbbonementTypeID());

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

	
	if(abbonement->getAbbonementID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");
		
		if(rs->next())
		{
			abbonement -> setAbbonementID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}
	
	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return abbonement;
}
Abbonement* AbbonementDAO::findAbbonementByKlantID(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	Abbonement* abbonement = 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return abbonement;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblAbbonement WHERE tblKlantenklantID = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
			abbonement = new Abbonement(res->getInt(2), res->getInt(3), res->getInt(4), res->getInt(1));
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


	return abbonement;
}
#endif