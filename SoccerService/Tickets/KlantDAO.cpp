#include "stdafx.h"
#include "KlantDAO.h"
#ifndef Databank_Offline
Connection* KlantDAO::con=NULL;

bool KlantDAO::removeKlant(int id)
{
	PreparedStatement *prep_stmt = NULL;

	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL)
			return false;

		prep_stmt = con-> prepareStatement ("Delete FROM tblKlanten where klantID = ?");
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

vector<Klant*> KlantDAO::getAll()
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	vector<Klant*> klanten;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return klanten;


		stmt = con -> createStatement();

		res = stmt -> executeQuery ("SELECT * FROM tblKlanten");

		while (res -> next()) {
			Klant* klant = new Klant(res->getInt(10),res->getString(2),res->getString(3), res->getString(4), res->getString(5), res->getString(6), res->getString(7), res->getString(8),res->getString(9), res->getString(11), res->getString(12), res->getString(13), res->getString(14), res->getString(15), res->getInt(1));
			klanten.push_back(klant); 
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


	return klanten;
}

Klant* KlantDAO::getKlant(int ID)
{
	ResultSet *res = NULL;
	Statement *stmt = NULL;
	Klant* klanten= 0;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return klanten;


		stmt = con -> createStatement();

		stringstream zoekopdracht;
		zoekopdracht<<"SELECT * FROM tblKlanten where klantID = ";
		zoekopdracht<<ID;
		res = stmt -> executeQuery (zoekopdracht.str());

		while (res -> next()) {
			Klant* klant = new Klant(res->getInt(10),res->getString(2),res->getString(3), res->getString(4), res->getString(5), res->getString(6), res->getString(7), res->getString(8),res->getString(9), res->getString(11), res->getString(12), res->getString(13), res->getString(14), res->getString(15), res->getInt(1));
			klanten = klant;
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


	return klanten;
}

Klant* KlantDAO::saveKlant(Klant* klant)
{
		PreparedStatement *prep_stmt = NULL;
	try {
		if(con == NULL || con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con == NULL || klant == NULL)
			return 0;

		if(klant->getKlantID()!=-1)
		{
			stringstream zoekopdracht;
			zoekopdracht<<"UPDATE tblKlanten SET klantVnaam = ?, klantAnaam = ?, klantStraat = ? , klantPostcode = ?, klantGemeente = ?, klantLand = ?, klantTelefoon = ?, klantEmailadres = ?, klantType = ?, klantBedrijfsnaam = ?, klantRijksregisternr = ?, klantBTWnr = ?, klantGnaam = ?, klantPasswd = ?, klantVorigJaarAbbo = ?, klantSupportersClub = ? where klantID = ";
			zoekopdracht<<klant->getKlantID();
			prep_stmt = con -> prepareStatement(zoekopdracht.str());
		}
		else
		{
			con->setAutoCommit(0);//zet auto commit af
			prep_stmt = con-> prepareStatement ("INSERT INTO tblKlanten VALUES (NULL, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
		}

		prep_stmt -> setString(1, klant->getKlantVnaam());
		prep_stmt -> setString(2, klant->getKlantFnaam());
		prep_stmt -> setString(3, klant->getKlantStraat());
		prep_stmt -> setString(4, klant->getKlantPostcode());
		prep_stmt -> setString(5, klant->getKlantGemeente());
		prep_stmt -> setString(6, klant->getKlantLand());
		prep_stmt -> setString(7, klant->getKlantTelefoon());
		prep_stmt -> setString(8, klant->getKlantEmail());
		prep_stmt -> setInt(9, klant->getKlantType());
		prep_stmt -> setString(10, klant->getKlantBedrijfsnaam());
		prep_stmt -> setString(11, klant->getKlantRijksregister());
		prep_stmt -> setString(12, klant->getKlantBTW());
		prep_stmt -> setString(13, klant->getKlantGnaam());
		prep_stmt -> setString(14, klant->getKlantWachtwoord());
		prep_stmt -> setInt(15, klant->getKlantVorigJaarAbbo());
		prep_stmt -> setInt(16, klant->getKlantSupportersClub());

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

	
	if(klant->getKlantID() == -1)
	{
		Statement* stmt = con -> createStatement();
		//ResultSet* rs = stmt->executeQuery("SELECT @@identity as id;");
		ResultSet* rs = stmt->executeQuery("SELECT LAST_INSERT_ID();");
		
		if(rs->next())
		{
			klant -> setKlantID(rs->getInt(1));
		}
		stmt->close();
		delete stmt;
		delete rs;
	}
	
	con->commit();
	con->setAutoCommit(1);//zet auto commit terug aan
	return klant;
}

Klant* KlantDAO::findKlantByID(int ID)
{
	ResultSet *res = NULL;
	Klant* klanten = 0;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return klanten;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblKlanten where klantID = ?");
		prep_stmt -> setInt(1, ID);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Klant* klant = new Klant(res->getInt(10),res->getString(2),res->getString(3), res->getString(4), res->getString(5), res->getString(6), res->getString(7), res->getString(8),res->getString(9), res->getString(11), res->getString(12), res->getString(13), res->getString(14), res->getString(15), res->getInt(1));
			klanten = klant; 
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
	return klanten;
}
int KlantDAO::findKlantByGnaam(string gnaam)
{
	ResultSet *res = NULL;
	Klant* klanten = new Klant();
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return klanten->getKlantID();



		prep_stmt = con-> prepareStatement("SELECT * FROM tblKlanten where klantGnaam = ?");
		prep_stmt -> setString(1, gnaam);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Klant* klant = new Klant(res->getInt(10),res->getString(2),res->getString(3), res->getString(4), res->getString(5), res->getString(6), res->getString(7), res->getString(8),res->getString(9), res->getString(11), res->getString(12), res->getString(13), res->getString(14), res->getString(15), res->getInt(1));
			klanten = klant;
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

	return klanten->getKlantID();
}
Klant* KlantDAO::findKlantByName(string vnaam, string anaam)
{
	ResultSet *res = NULL;
	Klant* klanten = 0;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return klanten;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblKlanten where klantVnaam = ? AND klantAnaam = ? ");
		prep_stmt -> setString(1, vnaam);
		prep_stmt -> setString(2, anaam);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Klant* klant = new Klant(res->getInt(10),res->getString(2),res->getString(3), res->getString(4), res->getString(5), res->getString(6), res->getString(7), res->getString(8),res->getString(9), res->getString(11), res->getString(12), res->getString(13), res->getString(14), res->getString(15), res->getInt(1));
			klanten = klant;
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

	return klanten;
}
Klant* KlantDAO::findKlantByRijksregisternr(string rijksregisternr)
{
	ResultSet *res = NULL;
	Klant* klanten = 0;
	PreparedStatement * prep_stmt = NULL;

	try {
		if(con == NULL ||con->isClosed())
			con =  DatabaseSingleton::getInstance()->getConnection();

		if (con==NULL)
			return klanten;



		prep_stmt = con-> prepareStatement("SELECT * FROM tblKlanten where klantRijksregisternr = ?");
		prep_stmt -> setString(1, rijksregisternr);
		res = prep_stmt -> executeQuery();

		while (res -> next()) {
			Klant* klant = new Klant(res->getInt(10),res->getString(2),res->getString(3), res->getString(4), res->getString(5), res->getString(6), res->getString(7), res->getString(8),res->getString(9), res->getString(11), res->getString(12), res->getString(13), res->getString(14), res->getString(15), res->getInt(1));
			klanten = klant;
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

	return klanten;
}
#endif