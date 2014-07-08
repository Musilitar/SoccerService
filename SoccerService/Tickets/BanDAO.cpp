#include "stdAfx.h"
#include "Ban.h"
#ifndef Databank_Offline
Connection* BanDAO::con=NULL;

bool BanDAO::removeBan(int id)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblBan where banID = ?");
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

vector<Ban*> BanDAO::getAll()
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	vector<Ban*> bannen;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return bannen;


		stmt = con -> createStatement();

		res = stmt -> executeQuery ("SELECT * FROM tblBan");

		while (res -> next()) {
			Ban* ban = new Ban(res->getString(2), res->getString(3), res->getInt(4), res->getInt(1));
			bannen.push_back(ban); 
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


	return bannen;
}

Ban* BanDAO::getBan(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	Ban* ban= 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return ban;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblBan where banID = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
			ban = new Ban(res->getString(2), res->getString(3), res->getInt(4), res->getInt(1));

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


	return ban;
}

Ban* BanDAO::maakBan(Ban* ban)
{
		PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || ban == NULL)
			return 0;

		if(ban->getBanID()!=-1)
		{
			stringstream zoekopdracht;
			zoekopdracht<<"UPDATE tblBan SET tblKlantenklantID = ?, bannedTot = ?, bannedVanaf = ? where banID = ";
			zoekopdracht<<ban->getBanID();
			prep_stmt = con -> prepareStatement(zoekopdracht.str());
		}
		else
		{
			con->setAutoCommit(0);//zet auto commit af
			prep_stmt = con-> prepareStatement ("INSERT INTO tblBan VALUES (?,?,?,NULL)");
		}

		prep_stmt -> setString(1, ban->getBanVanaf());
		prep_stmt -> setString(2, ban->getBanTot());
		prep_stmt -> setInt(3, ban->getBanKlantID());

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

	
	if(ban->getBanID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");
		
		if(rs->next())
		{
			ban -> setBanID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}
	
	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return ban;
}

vector<Ban*> BanDAO::findBanByKlantID(int ID)
{
	ResultSet *res = NULL;
	vector<Ban*> bannen;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return bannen;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblBan where tblKlantenklantID = ?");
		prep_stmt -> setInt(1, ID);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Ban* ban = new Ban(res->getString(2), res->getString(3), res->getInt(4), res->getInt(1));
			bannen.push_back(ban); 
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
	return bannen;
}

#endif
