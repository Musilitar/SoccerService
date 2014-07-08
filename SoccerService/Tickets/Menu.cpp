#include "stdafx.h"
#include "Menu.h"
#include <string>


Menu::Menu() //Default constructor needs no code since it only needs to be declared and then functions will show the menu's
{

}


Menu::~Menu(void)
{
}

void Menu::showMainMenu(){
	cout<<"Main Menu"<<endl;
	cout<<"----------"<<endl<<endl;
	cout<<"1. Ticket Kopen"<<endl;
	cout<<"2. Abbonement Bestellen"<<endl;
	cout<<"3. Inloggen/registreren"<<endl;
	cout<<endl;
	cout<<"9. Admin Panel"<<endl;
	cout<<endl;
	cout<<"0. Afsluiten"<<endl;
	cout<<endl<<"Geef uw keuze: ";
}

void Menu::toonAlleMatchen()
{
#ifndef Databank_Online
	//Matchen ophalen uit DAO
	vector<Match*> alleMatchen = OMatchDAO::getAlles();

	cout << "Selecteer een match:" << endl;
	cout << "--------------------" << endl;


	for(int i=0;i < alleMatchen.size();i++)
	{
		cout << alleMatchen[i]->toString();
		cout << endl;
	}

#endif


	//Haal matchen uit database.
#ifndef Databank_Offline
	vector<Match*> alleMatchen = MatchDAO::getAll();
	cout << "Selecteer een match:" << endl;
	cout << "--------------------" << endl;
	for(int i=0;i<alleMatchen.size();i++)
	{
		cout<<alleMatchen[i]->toString();
		cout<<endl;
	}
#endif
	cout<<endl<<"Geef uw keuze: ";
}

void Menu::getAllePloegen(){
	#ifndef Databank_Online
	//Matchen ophalen uit DAO
	vector<Stadion*> alleStadions = OStadionDAO::getAlles();

	cout << "Selecteer een Stadion/ploeg:" << endl;
	cout << "---------------------------" << endl;
	for(int i=0;i<alleStadions.size();i++)
	{
		cout << alleStadions[i]->toString();
		cout << endl;
	}
#endif


	//Haal matchen uit database.
#ifndef Databank_Offline
	vector<Stadion*> alleStadions = StadionDAO::getAll();
	cout << "Selecteer een Stadion/ploeg:" << endl;
	cout << "---------------------------" << endl;
	for(int i=0;i<alleStadions.size();i++)
	{
		cout<<alleStadions[i]->toString();
		cout<<endl;
	}
#endif
	cout<<endl<<"Geef uw keuze: ";
}

void Menu::getAlleTegenstanders(){
		#ifndef Databank_Online
	//Matchen ophalen uit DAO
	vector<Tegenstanders*> alleTegenstanders = OTegenstandersDAO::getAlles();

	cout << "Selecteer een Tegenstander:" << endl;
	cout << "---------------------------" << endl;
	for(int i=0;i<alleTegenstanders.size();i++)
	{
		cout << alleTegenstanders[i]->toString();
		cout << endl;
	}
#endif


	//Haal matchen uit database.
#ifndef Databank_Offline
	vector<Tegenstanders*> alleTegenstanders = TegenstandersDAO::getAll();
	cout << "Selecteer een Tegenstander:" << endl;
	cout << "--------------------------" << endl;
	for(int i=0;i<alleTegenstanders.size();i++)
	{
		cout<<alleTegenstanders[i]->toString();
		cout<<endl;
	}
#endif
	cout<<endl<<"Geef uw keuze: ";
}

void Menu::toonMogelijkeAbbonementen(bool vorigJaarAbbo, bool SupportersClub){

	if(vorigJaarAbbo){
		cout<<endl;
		cout << "1. Abbonement Heel Seizoen" << endl;
		cout << "2. Abbonement Play-Off 1" << endl;
	}else if(SupportersClub){
		cout<<endl;
		cout << "1. Abbonement Heel Seizoen" << endl;
	}else if(vorigJaarAbbo && SupportersClub){
		cout<<endl;
		cout << "1. Abbonement Heel Seizoen" << endl;
		cout << "2. Abbonement Play-Off 1" << endl;
	}
}

#ifndef Databank_Offline
// ONLINE DAO
Klant* Menu::registreerForm(Klant* myKlant)
{
	vector<Klant*> alleKlanten = KlantDAO::getAll();
	int type;
	string vnaam, fnaam, straat, gemeente, land, email, telefoon, postcode, btw, bedrijfsnaam, gnaam, wachtwoord, rijksregister;
	cout << "Type (0 = particulier, 1 = bedrijf): ";
	while (!(cin >> type) || (type < 0 || type > 1))
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Foutieve invoer. Probeer opnieuw: ";
	}
	cin.ignore(1000,'\n');
	if(type == 0){
		cout << "Rijksregisternummer (enkel cijfers): ";
		cin >> rijksregister;
		cin.ignore(1,'\n');
		cout << "Voornaam: ";
		getline(cin, vnaam);
		cout << "Achternaam: ";
		getline(cin, fnaam);
		cout << "Straat: ";
		getline(cin, straat);
		cout << "Postcode: ";
		getline(cin,postcode);
		cout << "Gemeente: ";
		getline(cin, gemeente);
		cout << "Land: ";
		getline(cin, land);
		cout << "Telefoonnummer: ";
		getline(cin, telefoon);
		cout << "E-mailadres: ";
		getline(cin, email);
		cout << "Gebruikersnaam: ";
		getline(cin, gnaam);
		cout << "Wachtwoord: ";
		getline(cin, wachtwoord);
		myKlant = new Klant(type, vnaam, fnaam, straat, postcode, gemeente, land, telefoon, email, bedrijfsnaam, btw, rijksregister, gnaam, wachtwoord);
		KlantDAO::saveKlant(myKlant);
		return myKlant;
	}
	else if(type == 1){
		cout << "Rijksregisternummer (enkel cijfers): ";
		getline(cin,rijksregister);
		cout << "Voornaam: ";
		getline(cin, vnaam);
		cout << "Achternaam: ";
		getline(cin, fnaam);
		cout << "Straat: ";
		getline(cin, straat);
		cout << "Postcode: ";
		getline(cin,postcode);
		cout << "Gemeente: ";
		getline(cin, gemeente);
		cout << "Land: ";
		getline(cin, land);
		cout << "Telefoonnummer: ";
		getline(cin, telefoon);
		cout << "E-mailadres: ";
		getline(cin, email);
		cout << "Bedrijfsnaam: ";
		getline(cin, bedrijfsnaam);
		cout << "BTW-nummer: ";
		getline(cin, btw);
		cout << "Gebruikersnaam: ";
		getline(cin, gnaam);
		cout << "Wachtwoord: ";
		getline(cin, wachtwoord);
		myKlant = new Klant(type, vnaam, fnaam, straat, postcode, gemeente, land, telefoon, email, bedrijfsnaam, btw, rijksregister, gnaam, wachtwoord);
		KlantDAO::saveKlant(myKlant);
		return myKlant;
	}
	else{
		cout << "Ongeldig type.";
	}
}
#endif
//OFFLINE DAO
#ifndef Databank_Online
Klant* Menu::registreerForm(Klant* myKlant)
{
	vector<Klant*> alleKlanten = OKlantDAO::getAlles();
	int type;
	string vnaam, fnaam, straat, gemeente, land, email, telefoon, postcode, btw, bedrijfsnaam, gnaam, wachtwoord, rijksregister;
	cout << "Type (0 = particulier, 1 = bedrijf): ";
	while (!(cin >> type) || (type < 0 || type > 1))
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Foutieve invoer. Probeer opnieuw: ";
	}

	cin.ignore(1000,'\n');
	if(type == 0){
		cout << "Rijksregisternummer (enkel cijfers): ";
		getline(cin,rijksregister);
		myKlant->setKlantRijksregister(rijksregister);
		cout << "Voornaam: ";
		getline(cin, vnaam);
		myKlant->setKlantVnaam(vnaam);
		cout << "Achternaam: ";
		getline(cin, fnaam);
		myKlant->setKlantFnaam(fnaam);
		cout << "Straat: ";
		getline(cin, straat);
		myKlant->setKlantStraat(straat);
		cout << "Postcode: ";
		getline(cin,postcode);
		myKlant->setKlantPostcode(postcode);
		cout << "Gemeente: ";
		getline(cin, gemeente);
		myKlant->setKlantGemeente(gemeente);
		cout << "Land: ";
		getline(cin, land);
		myKlant->setKlantLand(land);
		cout << "Telefoonnummer: ";
		getline(cin, telefoon);
		myKlant->setKlantTelefoon(telefoon);
		cout << "E-mailadres: ";
		getline(cin, email);
		myKlant->setKlantEmail(email);
		cout << "Gebruikersnaam: ";
		getline(cin, gnaam);
		myKlant->setKlantGnaam(gnaam);
		cout << "Wachtwoord: ";
		getline(cin, wachtwoord);
		myKlant->setKlantWachtwoord(wachtwoord);

		OKlantDAO::bewaarKlant(myKlant);
		return myKlant;
	}
	else if(type == 1){
		cout << "Rijksregisternummer (enkel cijfers): ";
		getline(cin,rijksregister);
		myKlant->setKlantRijksregister(rijksregister);
		cout << "Voornaam: ";
		getline(cin, vnaam);
		myKlant->setKlantVnaam(vnaam);
		cout << "Achternaam: ";
		getline(cin, fnaam);
		myKlant->setKlantFnaam(fnaam);
		cout << "Straat: ";
		getline(cin, straat);
		myKlant->setKlantStraat(straat);
		cout << "Postcode: ";
		getline(cin,postcode);
		myKlant->setKlantPostcode(postcode);
		cout << "Gemeente: ";
		getline(cin, gemeente);
		myKlant->setKlantGemeente(gemeente);
		cout << "Land: ";
		getline(cin, land);
		myKlant->setKlantLand(land);
		cout << "Telefoonnummer: ";
		getline(cin, telefoon);
		myKlant->setKlantTelefoon(telefoon);
		cout << "E-mailadres: ";
		getline(cin, email);
		myKlant->setKlantEmail(email);
		cout << "Bedrijfsnaam: ";
		getline(cin, bedrijfsnaam);
		myKlant->setKlantBedrijfsnaam(bedrijfsnaam);
		cout << "BTW-nummer: ";
		getline(cin, btw);
		myKlant->setKlantBTW(btw);
		cout << "Gebruikersnaam: ";
		getline(cin, gnaam);
		myKlant->setKlantGnaam(gnaam);
		cout << "Wachtwoord: ";
		getline(cin, wachtwoord);
		myKlant->setKlantWachtwoord(wachtwoord);

		OKlantDAO::bewaarKlant(myKlant);
		return myKlant;


	}
	else{
		cout << "Ongeldig type.";
	}
}
#endif

void Menu::showKlantMenu()
{
	cout<<"Klant Menu"<<endl;
	cout<<"----------"<<endl<<endl;
	cout<<"1. Klant Gegevens Bekijken en aanpassen"<<endl;
	cout<<"2. Ticket Bekijken"<<endl;
	cout<<"3. Abbonement Bekijken"<<endl;
	cout<<"4. Toon factuur Tickets van een match"<<endl;
	cout<<endl;
	cout<<"0. Terug naar hoofdmenu"<<endl;
	cout<<endl<<"Geef uw keuze: ";
}

void Menu::showAdminMenu(int klant_type){ //NAKIJKEN

	if(klant_type==2){ //kassier
		cout<<"Admin Menu"<<endl;
		cout<<"----------"<<endl<<endl;
		cout<<"1. Klanten beheer"<<endl;
		cout<<"2. Ticket beheer"<<endl;
		cout<<endl;
		cout<<"0. Terug naar hoofdmenu"<<endl;
		cout<<endl<<"Geef uw keuze: ";
	}else if(klant_type==3){ //full admin
		cout<<endl<<endl;
		cout<<"Admin Menu"<<endl;
		cout<<"----------"<<endl<<endl;
		cout<<"1. Klanten beheer"<<endl;
		cout<<"2. Ticket beheer"<<endl;
		cout<<"3. Abbonementen beheer"<<endl;
		cout<<"4. Matchen beheer"<<endl;
		cout<<"5. Blacklist beheer"<<endl;
		cout<<endl;
		cout<<"0. Terug naar hoofdmenu"<<endl;
		cout<<endl<<"Geef uw keuze: ";}
}

void Menu::showTicketAdminMenu(){
	cout<<endl<<endl;
	cout<<"Ticketbeheer Menu"<<endl;
	cout<<"-----------------"<<endl<<endl;
	cout<<"1. Ticket opzoeken"<<endl;
	cout<<"2. Ticket annuleren"<<endl;
	cout<<"3. Scan Ticket"<<endl;
	cout<<endl;
	cout<<"0. Terug naar hoofdmenu"<<endl;
	cout<<endl<<"Geef uw keuze: ";
}

void Menu::showAbbonementAdminMenu(){
	cout<<endl<<endl;
	cout<<"Abbonementbeheer Menu"<<endl;
	cout<<"-----------------"<<endl<<endl;
	cout<<"1. Abbonement opzoeken"<<endl;
	cout<<"2. Abbonement annuleren"<<endl;
	cout<<endl;
	cout<<"0. Terug naar hoofdmenu"<<endl;
	cout<<endl<<"Geef uw keuze: ";
}

void Menu::showMatchenAdminMenu(){
	cout<<endl<<endl;
	cout<<"Matchen Menu"<<endl;
	cout<<"------------"<<endl<<endl;
	cout<<"1. Match aanmaken"<<endl;
	cout<<"2. Match afsluiten"<<endl;
	cout<<endl;
	cout<<"0. Terug naar hoofdmenu"<<endl;
	cout<<endl<<"Geef uw keuze: ";
}

void Menu::showBlacklistAdminMenu(){
	cout<<endl<<endl;
	cout<<"Admin Menu"<<endl;
	cout<<"----------"<<endl<<endl;
	cout<<"1. Blacklist tonen"<<endl;
	cout<<"2. Blacklisting toevoegen"<<endl;
	cout<<"3. Blacklisting wegnemen"<<endl;
	cout<<endl;
	cout<<"0. Terug naar hoofdmenu"<<endl;
	cout<<endl<<"Geef uw keuze: ";
}

void Menu::showAdminKlantMenu(){
	cout<<endl<<endl;
	cout<<"Welk gegeven wilt u gebruiken om een klant op te zoeken?"<<endl;
	cout<<endl;
	cout<<"1. Achternaam en Voornaam"<<endl;
	cout<<"2. Klantnummer"<<endl;
	cout<<"3. Rijksregisternr"<<endl;
	cout<<endl;
	cout<<endl<<"Geef uw keuze: ";
}
void Menu::toonAlleVakken(int aantalTickets)
{
#ifndef Databank_Online
	//Vakken ophalen uit DAO
	vector<Vak*> alleVakken = OVakDAO::getAlles();

	cout << endl << "Selecteer een vak:" << endl;
	cout << "------------------" << endl;
	for(int i=0;i<alleVakken.size();i++){
		if (alleVakken[i]->getSoort()==0 || (alleVakken[i]->getBezettePlaatsen()+ aantalTickets <= alleVakken[i]->getCapaciteit())){
			cout<<alleVakken[i]->toString();
			}
		else {
			if(alleVakken[i]->getBezettePlaatsen()+ aantalTickets <= alleVakken[i]->getCapaciteit()){
			cout<<alleVakken[i]->toString();
			}
		}
	cout<<endl;
	}
#else
	vector<Vak*> alleVakken = VakDAO::getAll();
	cout << "Selecteer een vak:" << endl;
	cout << "-----------------" << endl;
	for(int i=0;i<alleVakken.size();i++){
		cout<<i+1<<". ";
		cout<<alleVakken[i]->toString();
		cout<<endl;
	}
#endif
	cout<<endl<<"Geef uw keuze: ";
}
void Menu::toonBans()
{
#ifndef Databank_Online
	//Bans ophalen uit DAO
	vector<Ban*> alleBannen = OBanDAO::getAlles();

	cout << "Selecteer een Ban:" << endl;
	cout << "--------------------" << endl;
	for(int i=0;i<alleBannen.size();i++)
	{
		cout << alleBannen[i]->toString();
		cout << endl;
	}
#endif


	//Haal Bannen uit database.
#ifndef Databank_Offline
	vector<Ban*> alleBannen = BanDAO::getAll();
	cout << "Selecteer een Ban:" << endl;
	cout << "--------------------" << endl;
	for(int i=0;i<alleBannen.size();i++)
	{
		cout<<alleBannen[i]->toString();
		cout<<endl;
	}
#endif
	cout<<endl<<"Geef uw keuze: ";
}
void Menu::maakFactuurTicket(int ticketID, int matchID, int klantID, int abbonementID)
{
	cout <<"            _____          _                                          " << endl;                    
	cout <<"           |  ___|_ _  ___| |_ _   _ _   _ _ __                       " << endl; 
	cout <<"           | |_ / _` |/ __| __| | | | | | | '__|                      " << endl; 
	cout <<"           |  _| (_| | (__| |_| |_| | |_| | |                         " << endl; 
	cout <<"           |_|  \__,_|\___|\__|\__,_|\__,_|_|                         " << endl; 

#ifndef Databank_Online
	Ticket* newFactuurTicket = OTicketDAO::getTicket(ticketID); 
	Match* newFactuurMatch = OMatchDAO::getMatch(matchID);
	Klant* newFactuurKlant = OKlantDAO::getKlant(klantID);  
	Abbonement* newFactuurAbbonement = OAbbonementDAO::getAbbonement(abbonementID);
#else
	Ticket* newFactuurTicket = TicketDAO::getTicket(ticketID); 
	Match* newFactuurMatch = MatchDAO::getMatch(matchID);
	Klant* newFactuurKlant = KlantDAO::getKlant(klantID);  
	Abbonement* newFactuurAbbonement = AbbonementDAO::getAbbonement(abbonementID);
#endif

}