#include "stdAfx.h"
#include "VakDAO.h"
#ifndef Databank_Offline
Connection* VakDAO::con=NULL;

bool VakDAO::removeVak(int id)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblVakken where vakID = ?");
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

vector<Vak*> VakDAO::getAll()
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	vector<Vak*> vakken;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return vakken;


		stmt = con -> createStatement();

		res = stmt -> executeQuery ("SELECT * FROM tblVakken");

		while (res -> next()) {
			Vak* vak = new Vak(res->getString(2), res->getDouble(3), res->getBoolean(4), res->getInt(5), res->getBoolean(6), res->getInt(1));
			vakken.push_back(vak); 
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


	return vakken;
}

Vak* VakDAO::getVak(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	Vak* vak= 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return vak;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblVakken where vakID = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
			vak = new Vak(res->getString(2), res->getDouble(3), res->getBoolean(4), res->getInt(5), res->getBoolean(6), res->getInt(1));
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


	return vak;
}

Vak* VakDAO::saveVak(Vak* vak)
{
	PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || vak == NULL)
			return 0;

		if(vak->getVakID()!=-1)
		{
			stringstream zoekopdracht;
			zoekopdracht<<"UPDATE tblVakken SET vakNaam = ?, vakKost = ? , vakID = ";
			zoekopdracht<<vak->getVakID();
			prep_stmt = con -> prepareStatement(zoekopdracht.str());
		}
		else
		{
			con->setAutoCommit(0);//zet auto commit af
			prep_stmt = con-> prepareStatement ("INSERT INTO tblVakken VALUES (NULL, ?,?)");
		}
		prep_stmt -> setString(1, vak->getNaam());
		prep_stmt -> setDouble(2, vak->getVakKost());


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


	if(vak->getVakID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");

		if(rs->next())
		{
			vak -> setVakID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}

	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return vak;
}

vector<Vak*> VakDAO::findVakByID(int ID)
{
	ResultSet *res = NULL;
	vector<Vak*> vakken;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return vakken;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblVakken where vakID = ?");
		prep_stmt -> setInt(1, ID);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Vak* vak = new Vak(res->getString(2), res->getDouble(3), res->getBoolean(4), res->getInt(5), res->getBoolean(6), res->getInt(1));
			vakken.push_back(vak); 
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
	return vakken;
}

#endif