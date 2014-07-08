#include "stdAfx.h"
#include "ZitjeDAO.h"
#ifndef Databank_Offline
Connection* ZitjeDAO::con=NULL;

bool ZitjeDAO::removeZitje(int id)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblZitjes where zitjesID = ?");
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

bool ZitjeDAO::removeZitjesMatch(int matchid)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblZitjes where tblMatchenmatch_id = ?");
		prep_stmt -> setInt(1, matchid);

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

vector<Zitje*> ZitjeDAO::getAll()
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	vector<Zitje*> zitjes;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return zitjes;


		stmt = con -> createStatement();

		res = stmt -> executeQuery ("SELECT * FROM tblZitjes");

		while (res -> next()) {
			Zitje* zitje = new Zitje(res->getInt(5),res->getInt(3),res->getInt(2),res->getInt(4),res->getInt(1));
			zitjes.push_back(zitje); 
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


	return zitjes;
}

Zitje* ZitjeDAO::getZitje(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	Zitje* zitje= 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return zitje;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblZitjes where zitjesID = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
			zitje = new Zitje(res->getInt(5),res->getInt(3),res->getInt(2),res->getInt(4),res->getInt(1));

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


	return zitje;
}

Zitje* ZitjeDAO::updateZitje(int match, int vak, int klant ,Zitje* zitje)
{
		PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || zitje == NULL)
			return 0;

		
			prep_stmt = con-> prepareStatement("UPDATE tblZitjes SET tblKlantenklantID = ? WHERE tblMatchenmatch_id = ? AND tblVakkenvakID = ? AND zitjesID = ?");
			prep_stmt -> setInt(1, klant);
			prep_stmt -> setInt(2, match);
			prep_stmt -> setInt(3, vak);
			prep_stmt -> setInt(4, zitje->getZitjeID());
			prep_stmt -> executeQuery();
		
		
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

	
	if(zitje->getZitjeID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");
		
		if(rs->next())
		{
			zitje -> setZitjeID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}
	
	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return zitje;
}

Zitje* ZitjeDAO::findZitjeByID(int ID)
{
	ResultSet *res = NULL;
	Zitje* zitjes = 0;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return zitjes;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblZitjes where zitjesID = ?");
		prep_stmt -> setInt(1, ID);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Zitje* zitje = new Zitje(res->getInt(5),res->getInt(3),res->getInt(2),res->getInt(4),res->getInt(1));
			zitjes = zitje;
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
	return zitjes;
}

Zitje* ZitjeDAO::maakZitje(Zitje* zitje){
	PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || zitje == NULL)
			return 0;

		if(zitje->getZitjeID()!=-1)
		{
			stringstream zoekopdracht;
			zoekopdracht<<"UPDATE tblZitjes SET zitjeNr = ? , tblMatchenmatch_id = ?, tblKlantenklantID = ?, tblVakkenvakID = ? where zitjesID = ";
			zoekopdracht<<zitje->getZitjeID();
			prep_stmt = con -> prepareStatement(zoekopdracht.str());
		}
		else
		{
			con->setAutoCommit(0);//zet auto commit af
			prep_stmt = con-> prepareStatement ("INSERT INTO tblZitjes VALUES (NULL, ?,?,NULL,?)");
		}

		prep_stmt -> setInt(1, zitje->getZitjeNr());
		prep_stmt -> setInt(2, zitje->getMatchID());
		prep_stmt -> setInt(3, zitje->getVakID());

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

	
	if(zitje->getZitjeID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");
		
		if(rs->next())
		{
			zitje -> setZitjeID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}
	
	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return zitje;
}


Zitje* ZitjeDAO::eersteVrijeStoel(int match,int vak)
{
	ResultSet *res = NULL;
	Zitje* zitjes = 0;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return zitjes;



		prep_stmt = con-> prepareStatement("SELECT zitjesID FROM tblZitjes WHERE tblMatchenmatch_id = ? AND tblVakkenvakID = ? AND tblKlantenklantID IS NULL LIMIT 1");
		prep_stmt -> setInt(1, match);
		prep_stmt -> setInt(2, vak);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Zitje* zitje = new Zitje(res->getInt(1));
			zitjes = zitje;
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
	return zitjes;
}

#endif