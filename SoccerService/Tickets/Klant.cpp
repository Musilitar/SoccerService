#include "stdafx.h"
#include "Klant.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Klant::Klant(void)
{
	setKlantID(0); 
	setKlantType(1);
	setKlantVnaam("");
	setKlantFnaam("");
	setKlantStraat("");
	setKlantPostcode("");
	setKlantGemeente("");
	setKlantLand(""); 
	setKlantTelefoon("");
	setKlantEmail("");
	setKlantBedrijfsnaam("");
	setKlantBTW("");
	setKlantRijksregister("");
	setKlantGnaam("");
	setKlantWachtwoord("");
}

Klant::Klant(int ID){setKlantID(ID);}


Klant::Klant(int type, string vnaam, string fnaam, string straat, string postcode, string gemeente, string land, string telefoon, string email, string bedrijfsnaam, string btw, string rijksregister, string gnaam, string wachtwoord, int ID)
{
	setKlantID(ID);
	setKlantType(type);
	setKlantVnaam(vnaam);
	setKlantFnaam(fnaam);
	setKlantStraat(straat);
	setKlantPostcode(postcode);
	setKlantGemeente(gemeente);
	setKlantLand(land); 
	setKlantTelefoon(telefoon);
	setKlantEmail(email);
	setKlantBedrijfsnaam(bedrijfsnaam);
	setKlantBTW(btw);
	setKlantRijksregister(rijksregister);
	setKlantGnaam(gnaam);
	setKlantWachtwoord(wachtwoord);
	//setKlantSupportersClub(supporter);
	//setKlantVorigJaarAbbo(vorigjaar_abbo);
}

Klant::~Klant(void)
{
}

int Klant::getKlantID()
{
	return myKlantID;
}
int Klant::getKlantType()
{
	return myKlantType;
}
string Klant::getKlantPostcode()
{
	return myKlantPostcode;
}
string Klant::getKlantVnaam()
{
	return myKlantVnaam; 
}
string Klant::getKlantFnaam()
{
	return myKlantFnaam;
}
string Klant::getKlantStraat()
{
	return myKlantStraat;
}
string Klant::getKlantGemeente()
{
	return myKlantGemeente;
}
string Klant::getKlantLand()
{
	return myKlantLand;
}
string Klant::getKlantTelefoon()
{
	return myKlantTelefoon;
}
string Klant::getKlantEmail()
{
	return myKlantEmail;
}
string Klant::getKlantBedrijfsnaam()
{
	return myKlantBedrijfsnaam;
}
string Klant::getKlantBTW()
{
	return myKlantBTW;
}
string Klant::getKlantRijksregister()
{
	return myKlantRijksregister;
}
string Klant::getKlantGnaam()
{
	return myKlantGnaam;
}
string Klant::getKlantWachtwoord()
{
	return myKlantWachtwoord;
}
bool Klant::getKlantVorigJaarAbbo(){
	return myKlantVorigJaarAbbonement;
}
bool Klant::getKlantSupportersClub(){
	return myKlantSupportersClub;
}



void Klant::setKlantID(int id)
{
	this -> myKlantID = id;
}
void Klant::setKlantType(int type)
{
	this -> myKlantType = type;
}
void Klant::setKlantPostcode(string postcode)
{
	this -> myKlantPostcode = postcode;
}
void Klant::setKlantVnaam(string vnaam)
{
	this -> myKlantVnaam = vnaam; 
}
void Klant::setKlantFnaam(string fnaam)
{
	this -> myKlantFnaam = fnaam;
}
void Klant::setKlantStraat(string straat)
{
	this -> myKlantStraat = straat;
}
void Klant::setKlantGemeente(string gemeente)
{
	this -> myKlantGemeente = gemeente;
}
void Klant::setKlantLand(string land)
{
	this -> myKlantLand = land;
}
void Klant::setKlantTelefoon(string telefoon)
{
	this -> myKlantTelefoon = telefoon;
}
void Klant::setKlantEmail(string email)
{
	this -> myKlantEmail = email;
}
void Klant::setKlantBedrijfsnaam(string bedrijfsnaam)
{
	this -> myKlantBedrijfsnaam = bedrijfsnaam;
}
void Klant::setKlantBTW(string btw)
{
	this -> myKlantBTW = btw;
}
void Klant::setKlantRijksregister(string rijksregister)
{
	this -> myKlantRijksregister = rijksregister;
}
void Klant::setKlantGnaam(string gnaam)
{
	this -> myKlantGnaam = gnaam;
}
void Klant::setKlantWachtwoord(string wachtwoord)
{
	this -> myKlantWachtwoord = wachtwoord;
}
void Klant::setKlantVorigJaarAbbo(bool vorigjaarabbo){
	this -> myKlantVorigJaarAbbonement = vorigjaarabbo;
}
void Klant::setKlantSupportersClub(bool supportersclub){
	this -> myKlantSupportersClub = supportersclub;
}

#ifndef Databank_Online
bool Klant::checkLogin(string gnaam, string wachtwoord, int id)
{
	Klant* temp = OKlantDAO::getKlant(id);
	if(gnaam == temp->getKlantGnaam() && wachtwoord == temp->getKlantWachtwoord()){return true;}
	else if(temp == 0){return false;}
	else{return false;}
}
#endif

#ifndef Databank_Offline
bool Klant::checkLogin(string gnaam, string wachtwoord, int id)
{
	Klant* temp = KlantDAO::getKlant(id);
	if(gnaam == temp->getKlantGnaam() && wachtwoord == temp->getKlantWachtwoord()){return true;}
	else if(temp->getKlantID() == 0){return false;}
	else{return false;}

}
#endif

string Klant::toString()
{
	stringstream ss;

	if(myKlantType == 0)
	{
		ss << "1. Gebruikersnaam: " << getKlantGnaam() << endl;
		ss << "2. Wachtwoord: " << getKlantWachtwoord() << endl;
		ss << "3. Voornaam: " << getKlantVnaam() << endl;
		ss << "4. Achternaam: " << getKlantFnaam() << endl;
		ss << "5. Straat: " << getKlantStraat() << endl;
		ss << "6. Postcode: " << getKlantPostcode() << endl;
		ss << "7. Gemeente: " << getKlantGemeente() << endl;
		ss << "8. Land: " << getKlantLand() << endl;
		ss << "9. Telefoonnummer: " << getKlantTelefoon() << endl;
		ss << "10. E-mailadres: " << getKlantEmail() << endl;
		ss << "11. Rijksregisternummer: " << getKlantRijksregister() << endl;
		ss << endl;
	}

	else if(myKlantType == 1)
	{
		ss << "1. Gebruikersnaam: " << getKlantGnaam() << endl;
		ss << "2. Wachtwoord: " << getKlantWachtwoord() << endl;
		ss << "3. Voornaam: " << getKlantVnaam() << endl;
		ss << "4. Achternaam: " << getKlantFnaam() << endl;
		ss << "5. Straat: " << getKlantStraat() << endl;
		ss << "6. Postcode: " << getKlantPostcode() << endl;
		ss << "7. Gemeente: " << getKlantGemeente() << endl;
		ss << "8. Land: " << getKlantLand() << endl;
		ss << "9. Telefoonnummer: " << getKlantTelefoon() << endl;
		ss << "10. E-mailadres: " << getKlantEmail() << endl;
		ss << "11. Bedrijfsnaam: " << getKlantBedrijfsnaam() << endl;
		ss << "12. BTW-nummer: " << getKlantBTW() << endl;
		ss << "13. Rijksregisternummer: " << getKlantRijksregister() << endl;
		ss << endl;
	}
	else if(myKlantType > 1)
	{
		ss << "1. Gebruikersnaam: " << getKlantGnaam() << endl;
		ss << "2. Wachtwoord: " << getKlantWachtwoord() << endl;
		ss << "3. Voornaam: " << getKlantVnaam() << endl;
		ss << "4. Achternaam: " << getKlantFnaam() << endl;
		ss << "5. Straat: " << getKlantStraat() << endl;
		ss << "6. Postcode: " << getKlantPostcode() << endl;
		ss << "7. Gemeente: " << getKlantGemeente() << endl;
		ss << "8. Land: " << getKlantLand() << endl;
		ss << "9. Telefoonnummer: " << getKlantTelefoon() << endl;
		ss << "10. E-mailadres: " << getKlantEmail() << endl;
		ss << "11. Bedrijfsnaam: " << getKlantBedrijfsnaam() << endl;
		ss << "12. BTW-nummer: " << getKlantBTW() << endl;
		ss << "13. Rijksregisternummer: " << getKlantRijksregister() << endl;
		ss << endl;
	}
	return ss.str();
}

bool Klant::getVorigJaarAbbo(){
	return true;
}

bool Klant::getSupportersClub(){
	return false;
}
bool Klant::betaal()
{
	char keuze_betalingsmiddel;
	string kaartnr,verificatiecode,vervaldatum,kaarthouder;

	cout<<endl<<"Wilt u betalen met (V)ISA, (M)astercard, (B)ancontact of (C)ash?"<<endl;
	cin>>keuze_betalingsmiddel;

	switch (toupper(keuze_betalingsmiddel))
	{
	case 'V':{
		cin.clear();
		cin.ignore(80, '\n');
		cout<<"Wat is uw Kaartnummer?"<<endl;
		getline(cin, kaartnr);
		cout<<"Wie is de kaarthouder?"<<endl;
		getline(cin, kaarthouder);
		cout<<"Verificatiecode?"<<endl;
		getline(cin, verificatiecode);
		cout<<"Vervaldatum?"<<endl;
		getline(cin, vervaldatum);
		break;
			 }
	case 'M':{
		cin.clear();
		cin.ignore(80, '\n');
		cout<<"Wat is uw Kaartnummer?"<<endl;
		getline(cin, kaartnr);
		cout<<"Wie is de kaarthouder?"<<endl;
		getline(cin, kaarthouder);
		cout<<"Verificatiecode?"<<endl;
		getline(cin, verificatiecode);
		cout<<"Vervaldatum?"<<endl;
		getline(cin, vervaldatum);
		break;
			 }
	case 'B':{
		cin.clear();
		cin.ignore(80, '\n');
		cout<<"Wat is uw Kaartnummer?"<<endl;
		getline(cin, kaartnr);
		cout<<"Vervaldatum?"<<endl;
		getline(cin, vervaldatum);
		break;
			 }
	case 'C':{
		cout << "U kan met uw voucher aan de kassa betalen." << endl;
		break;
			 }
	default:
		break;
	}

	cout<<"Betaald!"<<endl;

	return true;
}

string Klant::toonTickets()
{
	stringstream ss;
#ifndef Databank_Offline
	vector <Ticket*> tickets = TicketDAO::findTicketByKlantID(getKlantID());
#else
	vector <Ticket*> tickets = OTicketDAO::vindTicketDoorID(getKlantID());
#endif
	for(int i=0; i<tickets.size(); i++)
	{
#ifndef Databank_Offline
		Match* match = MatchDAO::getMatch(tickets[i]->getMatchID());
		Tegenstanders* tegenstander = TegenstandersDAO::getTegenstanders(match->getTegenstanderID());
		Stadion*stadion = StadionDAO::getStadion(match->getStadionID());
		Vak* vak = VakDAO::getVak(tickets[i]->getVakID());
		Zitje* zitje = ZitjeDAO::getZitje(tickets[i]->getZitjeID());
#else
		Match* match = OMatchDAO::getMatch(tickets[i]->getMatchID());
		Tegenstanders* tegenstander = OTegenstandersDAO::getTegenstanders(match->getTegenstanderID());
		Stadion*stadion = OStadionDAO::getStadion(match->getStadionID());
		Vak* vak = OVakDAO::getVak(tickets[i]->getVakID());
		Zitje* zitje = OZitjeDAO::getZitje(tickets[i]->getZitjeID());
#endif
		ss << stadion ->getStadionName() << " VS. " << tegenstander ->getTegenstanderNaam() << " - " << match ->getMatchDatum() << endl; 
		ss << "------------------------------------------------" << endl;
		ss << "Klant " << getKlantID() << " - " << getKlantVnaam() << " " << getKlantFnaam() << endl; 
		ss << "Vak " << vak->getVakID() << " Stoel: " << zitje->getZitjeNr() << endl; 
		ss <<  vak ->getVakKost() << " euro" << endl; 
		ss << endl;
	}
	return ss.str();
}



void Klant::printTickets()
{
	ofstream myfile;
	myfile.open ("tickets.txt");
#ifndef Databank_Offline
	vector <Ticket*> tickets = TicketDAO::findTicketByKlantID(getKlantID());
#else
	vector <Ticket*> tickets = OTicketDAO::vindTicketDoorID(getKlantID());
#endif

	for(int i=0; i<tickets.size(); i++)
	{
#ifndef Databank_Offline
		Match* match = MatchDAO::getMatch(tickets[i]->getMatchID());
		Tegenstanders* tegenstander = TegenstandersDAO::getTegenstanders(match->getTegenstanderID());
		Stadion*stadion = StadionDAO::getStadion(match->getStadionID());
		Vak* vak = VakDAO::getVak(tickets[i]->getVakID());
		Zitje* zitje = ZitjeDAO::getZitje(tickets[i]->getZitjeID());
#else
		Match* match = OMatchDAO::getMatch(tickets[i]->getMatchID());
		Tegenstanders* tegenstander = OTegenstandersDAO::getTegenstanders(match->getTegenstanderID());
		Stadion*stadion = OStadionDAO::getStadion(match->getStadionID());
		Vak* vak = OVakDAO::getVak(tickets[i]->getVakID());
		Zitje* zitje = OZitjeDAO::getZitje(tickets[i]->getZitjeID());
#endif
		myfile << stadion ->getStadionName() << " VS. " << tegenstander ->getTegenstanderNaam() << " - " << match ->getMatchDatum() << endl; 
		myfile << "Klant " << getKlantID() << " - " << getKlantVnaam() << " " << getKlantFnaam() << endl; 
		myfile << "Vak " << vak->getVakID() << " Stoel: " << zitje->getZitjeNr() << endl; 
		myfile <<  vak ->getVakKost() << " euro" << endl; 
		myfile << endl;
	}
	myfile.close();
}

void Klant::pasAan(int keuze, int type)
{
	cin.ignore(1,'\n');
	string invoer; 

	if(keuze == 1)
	{
		cout <<"Geef u gebruikersnaam in: "; 
		getline(cin,invoer);

		this->setKlantGnaam(invoer); 
	}
	else if(keuze == 2)
	{
		cout <<"Geef een wachtwoord in: "; 
		getline(cin,invoer); 

		this->setKlantWachtwoord(invoer);
	}
	else if(keuze == 3)
	{
		cout <<"Geef u voornaam in: "; 
		getline(cin,invoer);

		this->setKlantVnaam(invoer); 
	}
	else if(keuze == 4)
	{
		cout <<"Geef u achternaam in: "; 
		getline(cin,invoer);

		this->setKlantFnaam(invoer);
	}
	else if(keuze == 5)
	{
		cout <<"Geef de straatnaam in: "; 
		getline(cin,invoer);

		this->setKlantStraat(invoer);
	}
	else if(keuze == 6)
	{
		cout <<"Geef de postcode in: "; 
		getline(cin,invoer);

		this->setKlantPostcode(invoer);
	}
	else if(keuze == 7)
	{
		cout <<"Geef de gemeente in: "; 
		getline(cin,invoer);

		this->setKlantGemeente(invoer);
	}
	else if(keuze == 8)
	{
		cout <<"Geef het land in: "; 
		getline(cin,invoer);

		this->setKlantLand(invoer);
	}
	else if(keuze == 9)
	{
		cout <<"Geef het telefoonnummer in: "; 
		getline(cin,invoer);

		this->setKlantTelefoon(invoer);
	}
	else if(keuze == 10)
	{
		cout <<"Geef het e-mail adres in: "; 
		getline(cin,invoer);

		this->setKlantEmail(invoer);
	}
	else if(keuze == 11 && type < 1)
	{
		cout << "Geef het rijksregisternummer in: ";
		getline(cin, invoer);

		this->setKlantRijksregister(invoer);
	}
	else if(keuze == 11 && type >= 1)
	{
		cout << "Geef de bedrijfsnaam in: ";
		getline(cin, invoer);

		this->setKlantBedrijfsnaam(invoer);
	}
	else if(keuze == 12 && type >= 1)
	{
		cout << "Geef het BTW-nummer in: ";
		getline(cin, invoer);

		this->setKlantBTW(invoer);
	}
	else if(keuze == 13 && type >= 1)
	{
		cout << "Geef het rijksregisternummer in: ";
		getline(cin, invoer);

		this->setKlantRijksregister(invoer);
	}
	else
	{
		cout <<"Foutieve invoer. Probeer opnieuw."; 
		cin >> keuze; 
	}
}
string Klant::toonAbbonementen ()
{
#ifndef Databank_Offline
	Abbonement* A = AbbonementDAO::findAbbonementByKlantID(getKlantID());
#else
	Abbonement* A = OAbbonementDAO::getAbbonement(getKlantID());
#endif
	stringstream ss;

	ss << "Uw Abbonement" << endl;
	ss << "------------------------------" << endl;


	ss << "Abbonement " << A->getAbbonementID() << " - " << getKlantVnaam() << " " << getKlantFnaam() << endl;
	ss << "Klant: " << A->getAbbonementKlantID()  << endl;
	ss << "Vak: " << A->getAbbonementVakID() << endl;

	ss << endl;
	return ss.str();
}
void Klant::printAbbonementen()
{
	#ifndef Databank_Offline
	ofstream myfile;
	myfile.open ("abonnement.txt");
	Abbonement* A = AbbonementDAO::findAbbonementByKlantID(getKlantID());
	myfile << "Uw Abbonement" << endl;
	myfile << "------------------------------" << endl;


	myfile << "Abbonement " << A->getAbbonementID() << " - " << getKlantVnaam() << " " << getKlantFnaam() << endl;
	myfile << "Klant: " << A->getAbbonementKlantID()  << endl;
	myfile << "Vak: " << A->getAbbonementVakID() << endl;
	myfile.close();
#endif
}
void Klant::maakFactuurTicketsMatch(int matchID)
{

#ifndef Databank_Offline
	Match* newFactuurTicketsMatcht = MatchDAO::getMatch(matchID);
#else
	Match* newFactuurTicketsMatcht = OMatchDAO::getMatch(matchID); 
#endif
	int gevonden=0;
	Stadion* newFactuurTicketsStadion = new Stadion;
	Tegenstanders* tegenstander = new Tegenstanders;

#ifndef Databank_Offline
	vector<Ticket*> newFactuurTickets = TicketDAO::getAll();
#else
	vector<Ticket*> newFactuurTickets = OTicketDAO::getAlles();
#endif
	vector<Ticket*> gevondenTickets;
	for(int i=0;i<newFactuurTickets.size();i++){
		Ticket * tempT = newFactuurTickets.at(i);

		if((tempT->getKlantID()==getKlantID()) && (tempT->getMatchID()==matchID)){
			gevondenTickets.push_back(tempT);
			gevonden++;

			if(gevonden==1){
#ifndef Databank_Offline
				newFactuurTicketsStadion = StadionDAO::getStadion(tempT->getStadionID());
				tegenstander= TegenstandersDAO::getTegenstanders(newFactuurTicketsMatcht->getTegenstanderID());
#else
				newFactuurTicketsStadion = OStadionDAO::getStadion(tempT->getStadionID());
				tegenstander= OTegenstandersDAO::getTegenstanders(newFactuurTicketsMatcht->getTegenstanderID());
#endif
			}
		}
	}

	cout <<"            _____          _                                          " << endl;                    
	cout <<"           |  ___|_ _  ___| |_ _   _ _   _ _ __                       " << endl; 
	cout <<"           | |_ / _` |/ __| __| | | | | | | '__|                      " << endl; 
	cout <<"           |  _| (_| | (__| |_| |_| | |_| | |                         " << endl; 
	cout <<"           |_|  |__,_|____|___|___,_|___,_|_|                         " << endl;
	cout <<"--------------------------------------------------------------------" << endl;
	cout<<endl;
	cout<<"Klant Gegevens:"<<endl<<endl;
	cout<<"Naam: "<<getKlantFnaam()<<" "<<getKlantVnaam()<<endl;
	cout<<"RijksregisterNr: "<<getKlantRijksregister()<<endl;
	cout<<"Adres: "<<getKlantStraat()<<endl;
	cout<<getKlantPostcode()<<" "<<getKlantGemeente()<<endl;
	cout<<getKlantLand()<<endl;
	cout<<"Telefoonnummer: "<<getKlantTelefoon()<<endl;
	cout<<"Email: "<<getKlantEmail()<<endl;

	if(getKlantType()==1){
		cout<<endl;
		cout<<"Bedrijfsnaam: "<<getKlantBedrijfsnaam()<<endl;
		cout<<"BTW Nummer: "<<getKlantBTW()<<endl;
	}

	for(int i=0;i<gevondenTickets.size();i++){
		Ticket * gevondenT = gevondenTickets.at(i);
#ifndef Databank_Offline
		Vak* vak = VakDAO::getVak(gevondenT->getVakID());
		Zitje* zitje = ZitjeDAO::getZitje(gevondenT->getZitjeID());
#else
		Vak* vak = OVakDAO::getVak(gevondenT->getVakID());
		Zitje* zitje = OZitjeDAO::getZitje(gevondenT->getZitjeID());
#endif
		cout<<newFactuurTicketsStadion->getStadionName()<<" VS. "<<tegenstander->getTegenstanderNaam()<<" - "<<newFactuurTicketsMatcht->getMatchDatum()<< endl;
		cout<< "------------------------------------------------" << endl;
		cout<< "Vak: "<<vak->getVakID()<<" \t Stoel: "<<zitje->getZitjeNr()<< endl;
		cout<<vak->getVakKost()<<" euro" << endl;
		cout<< endl;
	}

	delete newFactuurTicketsStadion;
	delete tegenstander;
}
void Klant::printFactuurTicketsMatch(int matchID)
{
	ofstream myfile;
	myfile.open ("factuur.txt");
#ifndef Databank_Online
	Ticket* newFactuurTickets = OTicketDAO::getTicket(matchID);
	Match* newFactuurTicketsMatcht = OMatchDAO::getMatch(matchID); 
	Stadion* newFactuurTicketsStadion = OStadionDAO::getStadion(matchID); 
	Klant* newFactuurTicketsKlant = OKlantDAO::getKlant(matchID);
#else
	Match* newFactuurTicketsMatcht = MatchDAO::getMatch(matchID);
	int gevonden=0;
	Stadion* newFactuurTicketsStadion = new Stadion;
	Tegenstanders* tegenstander = new Tegenstanders;


	vector<Ticket*> newFactuurTickets = TicketDAO::getAll();
	vector<Ticket*> gevondenTickets;
	for(int i=0;i<newFactuurTickets.size();i++){
		Ticket * tempT = newFactuurTickets.at(i);

		if((tempT->getKlantID()==getKlantID()) && (tempT->getMatchID()==matchID)){
			gevondenTickets.push_back(tempT);
			gevonden++;

			if(gevonden==1){
				newFactuurTicketsStadion = StadionDAO::getStadion(tempT->getStadionID());
				tegenstander= TegenstandersDAO::getTegenstanders(newFactuurTicketsMatcht->getTegenstanderID());

			}
		}
	}

	myfile <<"            _____          _                                          " << endl;                    
	myfile <<"           |  ___|_ _  ___| |_ _   _ _   _ _ __                       " << endl; 
	myfile <<"           | |_ / _` |/ __| __| | | | | | | '__|                      " << endl; 
	myfile <<"           |  _| (_| | (__| |_| |_| | |_| | |                         " << endl; 
	myfile <<"           |_|  |__,_|____|___|___,_|___,_|_|                         " << endl;
	myfile <<"--------------------------------------------------------------------" << endl;
	myfile<<endl;
	myfile<<"Klant Gegevens:"<<endl<<endl;
	myfile<<"Naam: "<<getKlantFnaam()<<" "<<getKlantVnaam()<<endl;
	myfile<<"RijksregisterNr: "<<getKlantRijksregister()<<endl;
	myfile<<"Adres: "<<getKlantStraat()<<endl;
	myfile<<getKlantPostcode()<<" "<<getKlantGemeente()<<endl;
	myfile<<getKlantLand()<<endl;
	myfile<<"Telefoonnummer: "<<getKlantTelefoon()<<endl;
	myfile<<"Email: "<<getKlantEmail()<<endl;

	if(getKlantType()==1){
		myfile<<endl;
		myfile<<"Bedrijfsnaam: "<<getKlantBedrijfsnaam()<<endl;
		myfile<<"BTW Nummer: "<<getKlantBTW()<<endl;
	}

	for(int i=0;i<gevondenTickets.size();i++){
		Ticket * gevondenT = gevondenTickets.at(i);

		Vak* vak = VakDAO::getVak(gevondenT->getVakID());
		Zitje* zitje = ZitjeDAO::getZitje(gevondenT->getZitjeID());

		myfile<<newFactuurTicketsStadion->getStadionName()<<" VS. "<<tegenstander->getTegenstanderNaam()<<" - "<<newFactuurTicketsMatcht->getMatchDatum()<< endl;
		myfile<< "------------------------------------------------" << endl;
		myfile<< "Vak: "<<vak->getVakID()<<" \t Stoel: "<<zitje->getZitjeNr()<< endl;
		myfile<<vak->getVakKost()<<" euro" << endl;
		myfile<< endl;
	}
	delete newFactuurTicketsStadion;
	delete tegenstander;
#endif
	myfile.close();
}

void Klant::maakFactuurAbbonement(int abbonementID)
{
#ifndef Databank_Online
	Abbonement* newFactuur = OAbbonementDAO::getAbbonement(abbonementID);
#else
	//Abbonement* newFactuur = AbbonementDAO::getAbbonement(abbonementID);
#endif
}

bool Klant::checkBan(){
#ifndef Databank_Online
	vector<Ban*> foundBans = OBanDAO::vindBanDoorKlantID(getKlantID());

	if(foundBans.size()>0){
		return true;
	}else{
		return false;
	}
#else
	vector<Ban*> foundBans = BanDAO::findBanByKlantID(getKlantID());

	if(foundBans.size()>0){
		return true;
	}else{
		return false;
	}

#endif
}