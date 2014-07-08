#pragma once
#include <string>

using namespace std;


class Klant
{
private:
	int myKlantID;
	int myKlantType;
	string myKlantVnaam;
	string myKlantFnaam;
	string myKlantStraat;
	string myKlantPostcode;
	string myKlantGemeente;
	string myKlantLand;
	string myKlantTelefoon;
	string myKlantEmail;
	string myKlantBedrijfsnaam;
	string myKlantBTW;
	string myKlantRijksregister;
	string myKlantGnaam;
	string myKlantWachtwoord;
	bool myKlantVorigJaarAbbonement;
	bool myKlantSupportersClub;

public:
	Klant();
	Klant(int);
	Klant(int, string, string, string, string, string, string, string, string, string, string, string, string, string, int = -1);
	~Klant();	
	int getKlantID();
	int getKlantType(); 
	string getKlantVnaam();
	string getKlantFnaam();
	string getKlantStraat();
	string getKlantPostcode();
	string getKlantGemeente(); 
	string getKlantLand();
	string getKlantTelefoon();
	string getKlantEmail();
	string getKlantBedrijfsnaam();
	string getKlantBTW();
	string getKlantRijksregister();
	string getKlantGnaam();
	string getKlantWachtwoord();
	bool getKlantVorigJaarAbbo();
	bool getKlantSupportersClub();

	void setKlantID(int); 
	void setKlantType(int);
	void setKlantVnaam(string);
	void setKlantFnaam(string);
	void setKlantStraat(string); 
	void setKlantPostcode(string);
	void setKlantGemeente(string);
	void setKlantLand(string); 
	void setKlantTelefoon (string); 
	void setKlantEmail (string);
	void setKlantBedrijfsnaam(string);
	void setKlantBTW(string);
	void setKlantRijksregister(string);
	void setKlantGnaam(string);
	void setKlantWachtwoord(string);
	void setKlantVorigJaarAbbo(bool);
	void setKlantSupportersClub(bool);

	void login(string,string);
	bool checkLogin(string, string, int = -1);
	string toString();
	string toonTickets();
	void printTickets();
	bool getVorigJaarAbbo();
	bool getSupportersClub();
	void pasAan(int, int);
	string toonAbbonementen();
	void printAbbonementen();
	bool betaal(); 
	bool checkAdmin(); 
	void banKlant(string,string);
	void unBan();
	void maakFactuurTicketsMatch(int);
	void printFactuurTicketsMatch(int);
	void maakFactuurAbbonement(int); 
	bool checkBan();
};

