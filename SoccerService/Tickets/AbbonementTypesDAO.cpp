#include "stdAfx.h"
#include "AbbonementTypesDAO.h"
#ifndef Databank_Offline
Connection* AbbonementTypesDAO::con=NULL;

bool AbbonementTypesDAO::removeAbbonementTypes(int id)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblAbbonementTypes where abbonementTypeID = ?");
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

vector<AbbonementTypes*> AbbonementTypesDAO::getAll()
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	vector<AbbonementTypes*> abbonementenTypes;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return abbonementenTypes;


		stmt = con -> createStatement();

		res = stmt -> executeQuery ("SELECT * FROM tblAbbonementTypes");

		while (res -> next()) {
			AbbonementTypes* abbonementTypes = new AbbonementTypes(res->getString(2), res->getString(3),res->getInt(1));
			abbonementenTypes.push_back(abbonementTypes); 
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


	return abbonementenTypes;
}

AbbonementTypes* AbbonementTypesDAO::getAbbonementTypes(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	AbbonementTypes* abbonementTypes= 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return abbonementTypes;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblAbbonementTypes where abbonementTypeID = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
			abbonementTypes = new AbbonementTypes(res->getString(2), res->getString(3),res->getInt(1));

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


	return abbonementTypes;
}

AbbonementTypes* AbbonementTypesDAO::maakAbbonementTypes(AbbonementTypes* abbonementTypes)
{
		PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || abbonementTypes == NULL)
			return 0;

		if(abbonementTypes->getAbbonementTypeID()!=-1)
		{
			stringstream zoekopdracht;
			zoekopdracht<<"UPDATE tblAbbonementTypes SET abbonementTypeDatumTot = ?, abbonementTypeDatumVanaf = ? where abbonementTypeID = ";
			zoekopdracht<<abbonementTypes->getAbbonementTypeID();
			prep_stmt = con -> prepareStatement(zoekopdracht.str());
		}
		else
		{
			con->setAutoCommit(0);//zet auto commit af
			prep_stmt = con-> prepareStatement ("INSERT INTO tblAbbonementTypes VALUES (NULL,?,?)");
		}

		prep_stmt -> setString(1, abbonementTypes->getAbbonementTypeDatumVanaf());
		prep_stmt -> setString(2, abbonementTypes->getAbbonementTypeDatumTot());

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

	
	if(abbonementTypes->getAbbonementTypeID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");
		
		if(rs->next())
		{
			abbonementTypes -> setAbbonementTypeID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}
	
	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return abbonementTypes;
}

vector<AbbonementTypes*> AbbonementTypesDAO::findAbbonementTypesByID(int ID)
{
	ResultSet *res = NULL;
	vector<AbbonementTypes*> abbonementenTypes;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return abbonementenTypes;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblAbbonementTypes where abbonementTypeID = ?");
		prep_stmt -> setInt(1, ID);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			AbbonementTypes* abbonementTypes = new AbbonementTypes(res->getString(2), res->getString(3),res->getInt(1));
			abbonementenTypes.push_back(abbonementTypes); 
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
	return abbonementenTypes;
}

#endif