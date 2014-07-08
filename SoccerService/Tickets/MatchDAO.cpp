#include "stdafx.h"
#include "MatchDAO.h"
#ifndef Databank_Offline
Connection* MatchDAO::con=NULL;

bool MatchDAO::removeMatch(int id)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblMatchen where match_id = ?");
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

vector<Match*> MatchDAO::getAll()
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	vector<Match*> matchen;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return matchen;


		stmt = con -> createStatement();

		res = stmt -> executeQuery ("SELECT * FROM tblMatchen;");

		while (res -> next()) {
			Match* match = new Match(res->getString(2),res->getInt(3), res->getInt(4), res->getInt(1));
			matchen.push_back(match); 
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


	return matchen;
}

Match* MatchDAO::getMatch(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	Match* match= 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return match;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblMatchen where match_id = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
		 match = new Match(res->getString(2),res->getInt(3), res->getInt(4), res->getInt(1));

		}
		stmt->close();
		delete stmt;
		delete res;

		con ->close();
	} catch (SQLException &e) {
		cout<<"PROBLEM: "<<e.what()<<endl;
		//con ->close();

		if(stmt != NULL)
			delete stmt;
		if(res != NULL)
			delete res;
	}


	return match;
}

Match* MatchDAO::saveMatch(Match* match)
{
		PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || match == NULL)
			return 0;

		if(match->getMatchID()!=-1)
		{
			stringstream zoekopdracht;
			zoekopdracht<<"UPDATE tblMatchen SET matchDatum = ?, StadionstadionID = ?, tblTegenstanderstegenstanderID =?, match_id = ";
			zoekopdracht<<match->getMatchID();
			prep_stmt = con -> prepareStatement(zoekopdracht.str());
		}
		else
		{
			con->setAutoCommit(0);//zet auto commit af
			prep_stmt = con-> prepareStatement ("INSERT INTO tblMatchen VALUES (NULL, ?, ?, ?)");
		}

		prep_stmt -> setString(1, match->getMatchDatum());
		prep_stmt -> setInt(2, match->getStadionID());
		prep_stmt -> setInt(3, match->getTegenstanderID());

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

	
	if(match->getMatchID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");
		
		if(rs->next())
		{
			match -> setMatchID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}
	
	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return match;
}

vector<Match*> MatchDAO::findMatchByID(int ID)
{
	ResultSet *res = NULL;
	vector<Match*> matchen;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return matchen;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblMatchen where match_id = ?");
		prep_stmt -> setInt(1, ID);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Match* match = new Match(res->getString(2),res->getInt(3), res->getInt(4), res->getInt(1));
			matchen.push_back(match); 
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
	return matchen;
}

#endif