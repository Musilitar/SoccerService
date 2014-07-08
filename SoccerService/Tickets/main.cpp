// Tickets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

//classes

#include "Menu.h"
#include "Match.h"
#include "Ticket.h"
#include "Stadion.h"
#include "Klant.h"
#include "Abbonement.h"
#include "Tegenstanders.h"
#include "Ban.h"
#include "AbbonementTypes.h"

bool SetWindow(int,int);
//MAIN

int _tmain(int argc, _TCHAR* argv[])
{

#ifndef Databank_Online
	OVakDAO::initialisatie();
	OZitjeDAO::initialisatie();
	OTicketDAO::initialisatie();
	OKlantDAO::initialisatie();
	OMatchDAO::initialisatie();
	OAbbonementDAO::initialisatie();
	OStadionDAO::initialisatie();
	OTegenstandersDAO::initialisatie();
	OAbbonementTypesDAO::initialisatie();
	OBanDAO::initialisatie();
#endif

	SetWindow(160,50);
	Menu * menu = new Menu; //Always start from the Main Menu!

	Klant * myKlant = new Klant; //Lege basis contructor
	int keuze,keuze_match,keuze_vak,keuze_menu_admin_abbonement,keuze_menu_admin_match,keuze_menu_admin_blacklist,keuze_klant_sub_menu,keuze_menu_admin_ticket,keuze_aanpassing_klant,keuze_menu_klant,keuze_menu_admin,keuze_abbo_type; //int variabele om ticket keuzes te bepalen

#ifndef Databank_Offline
	vector <Stadion*> stadion = StadionDAO::getAll();
	int stadionID = stadion[0] ->getStadionID();
#endif

#ifndef Databank_Online
	Stadion* tmp = OStadionDAO::getStadion(1);
	int stadionID =  tmp->getStadionID();
#endif

	char keuze_login;
	int aantalTickets, klantID;
	int vol=0;
	int mogelijk=0;
	string gebruikersnaam, wachtwoord;

	cout <<"    ______    ____   ______    __ __    ______  ______    ____    _   __   ______          _____    ______    ____    _    __    ____   ______    ______       " << endl;
	cout <<"   /_  __/   /  _/  / ____/   / //_/   / ____/ /_  __/   /  _/   / | / /  / ____/         / ___/   / ____/   / __ |  | |  / /   /  _/  / ____/   / ____/       " << endl;
	cout <<"    / /      / /   / /       / ,<     / __/     / /      / /    /  |/ /  / / __           |__ |   / __/     / /_/ /  | | / /    / /   / /       / __/          " << endl;
	cout <<"   / /     _/ /   / /___    / /| |   / /___    / /     _/ /    / /|  /  / /_/ /          ___/ /  / /___    / _, _/   | |/ /   _/ /   / /___    / /___          " << endl;
	cout <<"  /_/     /___/  /_____/   /_/ |_|  /_____/   /_/     /___/   /_/ |_/   |____/          /____/  /_____/   /_/ |_|    |___/   /___/   |____/   /_____/          " << endl;
	cout <<"     ______    ____    ____     ______    ____           ____                                                                                                " << endl;
	cout <<"    / ____/   / __ |  / __ |   / ____/   / __ |         / __ |                                                                                               " << endl;
	cout <<"   / / __    / /_/ / / / / /  / __/     / /_/ /        / /_/ /                                                                                               " << endl;
	cout <<"  / /_/ /   / _, _/ / /_/ /  / /___    / ____/         |__, /                                                                                                " << endl;
	cout <<"  |____/   /_/ |_|  |____/  /_____/   /_/             /____/                                                                                                 " << endl;
	cout <<"                                                                                                                                                             " << endl << endl << endl;

	do{
		menu->showMainMenu();
		while (!(cin >> keuze) || (keuze < 0 || keuze > 9))
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Foutieve invoer. Probeer opnieuw: ";
		}

		system("cls");

		switch (keuze) //Switch van Main Menu
		{
		case 1: {//---Ticket Bestellen---

			menu->toonAlleMatchen(); //---> Alle matchen tonen van club X waarvoor tickets gekocht kunnen worden en de mogelijkheid bieden om een selectie te kunnen maken.

#ifndef Databank_Online
			while (!(cin >> keuze_match) || keuze_match < 1 || keuze_match > OMatchDAO::matchen.size())
			{
				cin.clear();
				cin.ignore(80, '\n');
				cout << "Foutieve invoer. Probeer opnieuw: ";
			}

#endif
#ifndef Databank_Offline
			vector <Match*> allematchen = MatchDAO::getAll();
			while (!(cin >> keuze_match) || keuze_match < 1 || keuze_match > allematchen.size())
			{
				cin.clear();
				cin.ignore(80, '\n');
				cout << "Foutieve invoer. Probeer opnieuw: ";
			}
#endif
			system("cls");
			Match * myMatch = new Match(keuze_match); //Op basis van de match ID alles setten van de match



			cout<<"Wilt u inloggen (I) of bent u nieuw? (R)"<<endl;
			while (!(cin >> keuze_login) || (tolower(keuze_login) != 'i' && tolower(keuze_login) != 'r'))
			{
				cin.clear();
				cin.ignore(80, '\n');
				cout << "Foutieve invoer. Probeer opnieuw: ";
			}
			system("cls");
			if(tolower(keuze_login) == 'i'){
				do{
					cout<<"Gebruikersnaam: ";
					cin>>gebruikersnaam;
					cout<<"Wachtwoord: ";
					cin>>wachtwoord;
					system("cls");
#ifndef Databank_Online
					klantID = OKlantDAO::vindKlantDoorGnaam(gebruikersnaam);
					myKlant = OKlantDAO::getKlant(klantID);
					if(OKlantDAO::getKlant(klantID) == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID)){
						cout<<"Uw login is fout!"<<endl;
					}

				}while(OKlantDAO::getKlant(klantID) == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID));
				cout << "U bent ingelogd met ID: " << klantID << endl;
#endif
#ifndef Databank_Offline
				klantID = KlantDAO::findKlantByGnaam(gebruikersnaam);
				myKlant = KlantDAO::getKlant(klantID);
				if(klantID == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID)){
					cout<<"Uw login is fout!"<<endl;
				}

			}while(klantID == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID));
			cout << "U bent ingelogd met ID: " << klantID << endl;
#endif				

				}else if(tolower(keuze_login) == 'r'){
					myKlant = menu->registreerForm(myKlant);
					klantID = myKlant -> getKlantID();
					system("cls");
				}

				bool banned = false;

				banned = myKlant->checkBan();

				if(banned==true){

					cout<<endl<<endl<<"U bent verbannen op dit systeem. Neem contact op met de administrator."<<endl<<endl;

					break;
				}

				if(myKlant->getKlantType() == 0){ // NOG NA TE KIJKEN
					cout<<endl<<"Geef aantal tickets dat u wilt kopen (MAX 4): ";
					while (!(cin >> aantalTickets) || aantalTickets < 1 || aantalTickets > 4)
					{
						cin.clear();
						cin.ignore(80, '\n');
						cout << "Foutieve invoer. Probeer opnieuw: ";
					}
					system("cls");
				}else if(myKlant->getKlantType() == 1){
					cout<<endl<<"Geef aantal tickets dat u wilt kopen: ";
					while (!(cin >> aantalTickets) || aantalTickets < 1)
					{
						cin.clear();
						cin.ignore(80, '\n');
						cout << "Foutieve invoer. Probeer opnieuw: ";
					}
					system("cls");
				}
				else if(myKlant->getKlantType() > 1){
					cout <<endl<<"Een admin kan geen Tickets aankopen !" << endl;
					break;
				}

#ifndef Databank_Offline
				vector<Vak*> vakken = VakDAO::getAll();
				for(int j = 0; j < vakken.size(); j++)
				{
					cout << vakken[j] -> getVakID() << ". ";
					cout << vakken[j] ->getNaam() << endl;
					cout << "Prijs: " << vakken[j] -> getVakKost() << endl;
				}
				cout << "Kies uw vak: ";
				cin >> keuze_vak;
				system("cls");
				Vak* temp = VakDAO::getVak(keuze_vak);
				while(keuze_vak < 1 || keuze_vak > vakken.size())
				{
					cout << "Foute invoer, kies opnieuw: ";
					cin >> keuze_vak;
					system("cls");
					temp = VakDAO::getVak(keuze_vak);
				}

				myKlant->betaal();

				for (int i = 0; i < aantalTickets; i++){

					Zitje *  zitje = ZitjeDAO::eersteVrijeStoel(keuze_match,keuze_vak);
					ZitjeDAO::updateZitje(keuze_match,keuze_vak,klantID,zitje);

					Ticket* myTicket = new Ticket(stadionID, klantID, zitje->getZitjeID(), keuze_vak, keuze_match);
					Ticket* tempTicket = TicketDAO::saveTicket(myTicket);
					cout<<i+1<<"e ticket gekocht!" << endl;
					cout << "Info van ticket: " << endl;
					cout << tempTicket->toString();

				}
#else
				for(int j = 0; j < OVakDAO::vakken.size(); j++){
					Vak* temp = OVakDAO::vakken.at(j);
					if(temp->getBezettePlaatsen()+ aantalTickets <= temp->getCapaciteit()){
						cout << temp->getVakID() << ". ";
						cout << temp->getNaam() << endl;
						cout << "Prijs: " << temp->getVakKost() << endl;

					}
				}
				cout << "Kies uw vak: ";
				cin >> keuze_vak;
				system("cls");
				Vak* temp = OVakDAO::getVak(keuze_vak);
				while(temp == 0 || temp->getBezettePlaatsen()+ aantalTickets > temp->getCapaciteit() || keuze_vak < 1 || keuze_vak > OVakDAO::vakken.size()){
					cout << "Foute invoer, kies opnieuw: ";
					cin >> keuze_vak;
					system("cls");
					temp = OVakDAO::getVak(keuze_vak);
				}

				myKlant->betaal();

				for (int i = 0; i < aantalTickets; i++){
					int zitjeID = OZitjeDAO::reserveerVolgendeVrijeZitje(keuze_vak);
					cout << "Zitje ID: " << zitjeID << endl;


					//	/* ---- ITERATIE 2 ----- */
					Ticket* myTicket = new Ticket(stadionID, klantID, zitjeID, keuze_vak, keuze_match);
					Ticket* tempTicket = OTicketDAO::bewaarTicket(myTicket);
					cout<<i+1<<"e ticket gekocht!" << endl;
					cout << "Info van ticket: " << endl;
					cout << tempTicket->toString();


				}
#endif
				break;
				delete myMatch;
		}


		case 2: //---Abbo Bestellen---
			{
				/* ----ITERATIE 2 ---

				1. Login Code. Voor Login. Zie Ticket Kopen
				2. Nakijken datums/supportersclub --- Wordt achteraf ingepland
				4. mogelijke abbos tonen en 1 kiezen
				5. abbo bestellen

				*/

				do{
					cout<<"Gebruikersnaam: ";
					cin>>gebruikersnaam;
					cout<<"Wachtwoord: ";
					cin>>wachtwoord;
					system("cls");
#ifndef Databank_Online
					klantID = OKlantDAO::vindKlantDoorGnaam(gebruikersnaam);
					myKlant = OKlantDAO::getKlant(klantID);
					if(OKlantDAO::getKlant(klantID) == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID)){
						cout<<"Uw login is fout!"<<endl;
					}

				}while(OKlantDAO::getKlant(klantID) == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID));
				cout << "U bent ingelogd met ID: " << klantID << endl;
#endif
#ifndef Databank_Offline
				klantID = KlantDAO::findKlantByGnaam(gebruikersnaam);
				myKlant = KlantDAO::getKlant(klantID);
				if(klantID == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID)){
					cout<<"Uw login is fout!"<<endl;
				}

			}while(klantID == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID));
			cout << "U bent ingelogd met ID: " << klantID << endl;
#endif	

			bool banned = false;

			banned = myKlant->checkBan();

			if(banned==true){

				cout<<endl<<endl<<"U bent verbannen op dit systeem. Neem contact op met de administrator."<<endl<<endl;

				break;
			}

			//NOG NODIG?
			bool klantVorigJaarAbbo = myKlant->getKlantVorigJaarAbbo();
			bool klantSupportersClub = myKlant->getKlantSupportersClub();

			menu->toonMogelijkeAbbonementen(klantVorigJaarAbbo,klantSupportersClub); //===> alle abbonementen tonen die mogelijk zijn
			cin>>keuze_abbo_type;

			menu->toonAlleVakken(1);
			cin>>keuze_vak;
			system("cls");

			cout << Abbonement::maakAbbonement(klantID, keuze_vak, keuze_abbo_type);

			break;
	}
		case 3: { //---Account Inloggen---

			cout<<"Wilt u inloggen (I) of bent u nieuw? (R)"<<endl;
			while (!(cin >> keuze_login) || (tolower(keuze_login) != 'i' && tolower(keuze_login) != 'r'))
			{
				cin.clear();
				cin.ignore(80, '\n');
				cout << "Foutieve invoer. Probeer opnieuw: ";
			}
			system("cls");
			if(tolower(keuze_login) == 'i'){
				do{
					cout<<"Gebruikersnaam: ";
					cin>>gebruikersnaam;
					cout<<"Wachtwoord: ";
					cin>>wachtwoord;
					system("cls");

#ifndef Databank_Online
					klantID = OKlantDAO::vindKlantDoorGnaam(gebruikersnaam);
					myKlant = OKlantDAO::getKlant(klantID);
					if(OKlantDAO::getKlant(klantID) == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID)){
						cout<<"Uw login is fout!"<<endl << endl;
					}

				}while(OKlantDAO::getKlant(klantID) == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID));
				cout << "U bent ingelogd met ID: " << klantID << endl << endl;
#endif
#ifndef Databank_Offline
				klantID = KlantDAO::findKlantByGnaam(gebruikersnaam);
				myKlant = KlantDAO::getKlant(klantID);
				if(klantID == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID)){
					cout<<"Uw login is fout!"<<endl << endl;
				}

			}while(klantID == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID));
			cout << "U bent ingelogd met ID: " << klantID << endl << endl;
#endif		

				}else if(tolower(keuze_login) == 'r'){
					myKlant = menu->registreerForm(myKlant);
					klantID = myKlant -> getKlantID();
					system("cls");
				}

				do{

					menu->showKlantMenu();
					cin>>keuze_menu_klant;
					system("cls");
					switch (keuze_menu_klant)
					{
					case 1: { //Bekijken en aanpassen klantgegevens indien gewenst.
						// 1.2. toString tonen van Klant
						do{
#ifndef Databank_Online
							myKlant = OKlantDAO::getKlant(klantID);
#endif
							cout << "Hier zijn uw gegevens: " << endl<<endl;
							cout << myKlant->toString();

							// 1.3. Geef het ID van wat uw wilt aanpassen. Dit dan ook opvragen met een CIN. Aanpassen uitvoeren. En loopen terug naar 2.
							cout<<"Wat wilt u aanpassen? Geef 0 om terug te gaan naar het klantmenu"<<endl<<"Uw keuze: ";
							cin>>keuze_aanpassing_klant;
							system("cls");
							if(keuze_aanpassing_klant!=0){
								myKlant->pasAan(keuze_aanpassing_klant, myKlant->getKlantType()); //=========>>>>> Aanpassing opvragen aan de klant en doorvoeren naar de databank.
							}
#ifndef Databank_Offline				
							KlantDAO::saveKlant(myKlant);
#endif
						}while(keuze_aanpassing_klant!=0); // 1.4. Indien 0 ingegeven: Klaar tonen op hetscherm en main menu tonen.
						break;
							}
					case 2:{ //Ticket Bekijken
						cout<<myKlant->toonTickets(); //=======>>>> haalt ALLE tickets op van die klant. Dan telkens toString van klasse Ticket
						cout<<endl;
						cout<<"1. Tickets afprinten"<<endl;
						cout<<endl;
						cout<<"0. Terug naar vorig menu"<<endl;
						cout<<"Geef uw keuze: ";
						while (!(cin >> keuze_klant_sub_menu) ||  keuze_klant_sub_menu < 0 ||  keuze_klant_sub_menu > 1)
						{
							cin.clear();
							cin.ignore(80, '\n');
							cout << "Foutieve invoer. Probeer opnieuw: ";
						}
						system("cls");

						if(keuze_klant_sub_menu==0){
							break;
						}else if(keuze_klant_sub_menu==1){
							myKlant->printTickets();
							cout<<"Uw tickets worden nu geprint!"<<endl;
							break;
						}

						   }
					case 3:{ //Abbonement Bekijken
						cout << myKlant->toonAbbonementen(); //======>>>>haalt ALLE abbonemten op van die klant. Dan toString van klasse Abbonement
						cout<<endl;
						cout<<"1. Abbonementen afprinten"<<endl;
						cout<<endl;
						cout<<"0. Terug naar vorig menu"<<endl;
						cout<<"Geef uw keuze: ";
						while (!(cin >> keuze_klant_sub_menu) ||  keuze_klant_sub_menu < 0 ||  keuze_klant_sub_menu > 1)
						{
							cin.clear();
							cin.ignore(80, '\n');
							cout << "Foutieve invoer. Probeer opnieuw: ";
						}
						system("cls");
						if(keuze_klant_sub_menu==0){
							break;
						}else if(keuze_klant_sub_menu==1){
							myKlant->printAbbonementen();
							cout<<"Uw Abbonement wordt nu geprint!"<<endl;
							break;
						}
						   }
					case 4:{ //Factuur Ticket
						menu->toonAlleMatchen();
						cin>>keuze_match;
						system("cls");
						myKlant->maakFactuurTicketsMatch(keuze_match);
						cout << "1. Factuur afprinten"<<endl;
						cout << endl;
						cout << "0. Terug naar vorige menu"<< endl;
						cout << "Geef uw keuze: ";
						while (!(cin >> keuze_klant_sub_menu) ||  keuze_klant_sub_menu < 0 ||  keuze_klant_sub_menu > 1)
						{
							cin.clear();
							cin.ignore(80, '\n');
							cout << "Foutieve invoer. Probeer opnieuw: ";
						}
						system("cls");
						if(keuze_klant_sub_menu==0)
						{
							break;
						}
						else if(keuze_klant_sub_menu==1)
						{
							myKlant->printFactuurTicketsMatch(keuze_match);
							cout << "Uw factuur wordt nu afgeprint!"<<endl;
							break;
						}
						   }
					default:
						break;
					}



				}while(keuze_menu_klant!=0);

				break;
}
		case 9: //---Admin panel
			{
				int klant_type = 0;
				do{
					cout<<"Gebruikersnaam: ";
					cin>>gebruikersnaam;
					cout<<"Wachtwoord: ";
					cin>>wachtwoord;
					system("cls");
#ifndef Databank_Online
					klantID = OKlantDAO::vindKlantDoorGnaam(gebruikersnaam);
					myKlant = OKlantDAO::getKlant(klantID);
					klant_type = myKlant->getKlantType();
					if(OKlantDAO::getKlant(klantID) == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID) || (klant_type < 2 || klant_type > 3)){
						cout<<"Uw login is fout, of u bent niet bevoegd om het admin panel te gebruiken."<<endl;
					}

				}while(OKlantDAO::getKlant(klantID) == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID) || (klant_type < 2 || klant_type > 3));
				cout << "U bent ingelogd met ID: " << klantID << endl;
#endif
#ifndef Databank_Offline
				klantID = KlantDAO::findKlantByGnaam(gebruikersnaam);
				myKlant = KlantDAO::getKlant(klantID);
				klant_type = myKlant->getKlantType();
				if(klantID == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID) || (klant_type < 2 || klant_type > 3)){
					cout<<"Uw login is fout, of u bent niet bevoegd om het admin panel te gebruiken."<<endl;
				}
				/*if(!myKlant->checkAdmin()){ // ===>>> Kijkt na of de account een admin account heeft (d.w.z. een klant_type groter dan 1)
				cout<<"Toegang verboden voor onbevoegden."<<endl;
				}*/

				//}while((!myKlant->checkLogin(klantID, gebruikersnaam, wachtwoord))&&(!myKlant->checkAdmin()));
			}while(klantID == 0 || !myKlant->checkLogin(gebruikersnaam, wachtwoord, klantID) || (klant_type < 2 || klant_type > 3));
			cout << "U bent ingelogd met ID: " << klantID << endl;
#endif	




			do{
				//TODO: Inbouwen rank(e.g. Super admin/kassier/...)
				//
				menu->showAdminMenu(klant_type); //NAKIJKEN

				//menu->showAdminMenu();
				cin>>keuze_menu_admin;
				system("cls");
				switch (keuze_menu_admin)
				{
				case 1: { //Klant beheer
					//klant bekijken op basis van zijn achternaam en voornaam OF klantnummer OF rijksregisternr
					//indien er 1 of meedere klanten gevonden zijn, deze oplijsten met vraag welke mn wilt bewerken/bekijken.
					string vnaam = "A", anaam = "A", rijksregisternr;
					int keuze_opzoeking,keuze_na_opzoeking;
					int klantnr;

					Klant * myDummyKlant = new Klant;

					menu->showAdminKlantMenu();
					cin>>keuze_opzoeking;
					system("cls");
					cout<<endl;

					switch (keuze_opzoeking)
					{
					case 1: { //Opzoeken via achternaam en voornaam

						cout<<"Geef voornaam: ";
						cin>>vnaam;
						cout<<"Geef achternaam: ";
						cin>>anaam;
						system("cls");
						do{

#ifndef Databank_Online

							myDummyKlant = OKlantDAO::vindKlantDoorNaam(vnaam, anaam);
#else
							myDummyKlant = KlantDAO::findKlantByName(vnaam, anaam);
#endif

#ifndef Databank_Offline
							myDummyKlant = KlantDAO::findKlantByName(vnaam, anaam);

#endif
							while(myDummyKlant == 0){
								cout << "Deze klant bestaat niet, of heeft zijn gegevens niet volledig ingevuld." << endl;
								cout<<"Geef voornaam: ";
								cin>>vnaam;
								cout<<"Geef achternaam: ";
								cin>>anaam;
								system("cls");
#ifndef Databank_Offline
								myDummyKlant = KlantDAO::findKlantByName(vnaam, anaam);
#else
								myDummyKlant = OKlantDAO::vindKlantDoorNaam(vnaam, anaam);
#endif
							}
							cout <<endl<< "Hier zijn uw gegevens: " << endl<<endl;
							cout << myDummyKlant->toString();

							// 1.3. Geef het ID van wat uw wilt aanpassen. Dit dan ook opvragen met een CIN. Aanpassen uitvoeren. En loopen terug naar 2.
							cout<<"Wat wilt u aanpassen? Geef 0 om terug te gaan naar het hoofdmenu"<<endl<<"Uw keuze: ";
							cin>>keuze_aanpassing_klant;
							system("cls");
							if(keuze_aanpassing_klant!=0){
								myDummyKlant->pasAan(keuze_aanpassing_klant, myDummyKlant->getKlantType()); //Aanpassing opvragen aan de klant en doorvoeren naar de databank.
#ifndef Databank_Offline
								KlantDAO::saveKlant(myDummyKlant);
#endif
								vnaam = myDummyKlant ->getKlantVnaam();
								anaam = myDummyKlant ->getKlantFnaam();
							}
						}while(keuze_aanpassing_klant!=0 ); // 1.4. Indien 0 ingegeven: Klaar tonen op hetscherm en main menu tonen.

						break;

							}
					case 2: { //opzoeken via klantnummer
						cout<<"Geef klantnummer: ";
						cin>>klantnr;
						system("cls");
						do{
#ifndef Databank_Online
							myDummyKlant = OKlantDAO::getKlant(klantnr);
#else
							myDummyKlant = KlantDAO::findKlantByID(klantnr);
#endif
							while(myDummyKlant == 0){
								cout << "Deze klant bestaat niet. Geef een nieuw klantnummer in: ";
								cin >> klantnr;
								system("cls");
#ifndef Databank_Online
								myDummyKlant = OKlantDAO::getKlant(klantnr);
#else
								myDummyKlant = KlantDAO::findKlantByID(klantnr);
#endif
							}
							cout <<endl<< "Hier zijn uw gegevens: " << endl<<endl;
							cout << myDummyKlant->toString();

							// 1.3. Geef het ID van wat uw wilt aanpassen. Dit dan ook opvragen met een CIN. Aanpassen uitvoeren. En loopen terug naar 2.
							cout<<"Wat wilt u aanpassen? Geef 0 om terug te gaan naar het hoofdmenu"<<endl<<"Uw keuze: ";
							cin>>keuze_aanpassing_klant;
							system("cls");

							if(keuze_aanpassing_klant!=0){
								myDummyKlant->pasAan(keuze_aanpassing_klant, myDummyKlant->getKlantType()); //Aanpassing opvragen aan de klant en doorvoeren naar de databank.
#ifndef Databank_Offline
								KlantDAO::saveKlant(myDummyKlant);
#endif
							}
						}while(keuze_aanpassing_klant!=0); // 1.4. Indien 0 ingegeven: Klaar tonen op hetscherm en main menu tonen.

						break;
							}
					case 3: { //opzoeken via rijksregisternr
						cout<<"Geef rijksregisternr: ";
						cin>>rijksregisternr;
						system("cls");
						do{
#ifndef Databank_Offline
							myDummyKlant = KlantDAO::findKlantByRijksregisternr(rijksregisternr);

#else
							klantnr = OKlantDAO::getKlantViaRijksregisterNr(rijksregisternr);
							myDummyKlant = OKlantDAO::getKlant(klantnr);
#endif
							while(myDummyKlant == 0){
								cout << "Deze klant bestaat niet. Probeer opnieuw." << endl;
								cout<<"Geef rijksregisternr: ";
								cin>>rijksregisternr;
								system("cls");
#ifndef Databank_Offline
								myDummyKlant = KlantDAO::findKlantByRijksregisternr(rijksregisternr);
#else
								klantnr = OKlantDAO::getKlantViaRijksregisterNr(rijksregisternr);
								myDummyKlant = OKlantDAO::getKlant(klantnr);
#endif
							}
							cout <<endl<< "Hier zijn uw gegevens: " << endl<<endl;
							cout << myDummyKlant->toString();

							// 1.3. Geef het ID van wat uw wilt aanpassen. Dit dan ook opvragen met een CIN. Aanpassen uitvoeren. En loopen terug naar 2.
							cout<<"Wat wilt u aanpassen? Geef 0 om terug te gaan naar het hoofdmenu"<<endl<<"Uw keuze: ";
							cin>>keuze_aanpassing_klant;
							system("cls");
							if(keuze_aanpassing_klant!=0){
								myDummyKlant->pasAan(keuze_aanpassing_klant, myDummyKlant->getKlantType()); //Aanpassing opvragen aan de klant en doorvoeren naar de databank.
							}
						}while(keuze_aanpassing_klant!=0); // 1.4. Indien 0 ingegeven: Klaar tonen op hetscherm en main menu tonen.
						break;
							}
					default:
						break;
					}

					break;
					delete myDummyKlant;
						}
				case 2: { //Ticket beheer

					Ticket * myDummyTicket = new Ticket();
					int ticketID;

					do
					{
						menu->showTicketAdminMenu();
						cin>>keuze_menu_admin_ticket;
						system("cls");
						switch (keuze_menu_admin_ticket)
						{
						case 1:{ //Ticket opzoeken (en mogelijkheid tot afprinten)
							cout<<"Geef TicketID in: ";
							cin>>ticketID;
							system("cls");
#ifndef Databank_Offline
							myDummyTicket = TicketDAO::getTicket(ticketID);
#else
							myDummyTicket = OTicketDAO::getTicket(ticketID);
#endif
							while(myDummyTicket == 0){
								cout << "Dit ticket bestaat niet. Geef een nieuw TicketID in: ";
								cin >> ticketID;
								system("cls");
#ifndef Databank_Offline
								myDummyTicket = TicketDAO::getTicket(ticketID);
#else
								myDummyTicket = OTicketDAO::getTicket(ticketID);
#endif
							}
							cout <<endl<< "Hier zijn uw gegevens: " << endl<<endl;
							cout << myDummyTicket->toString();

							cout<<endl;
							cout<<"1. Ticket afprinten"<<endl;
							cout<<endl;
							cout<<"0. Terug naar vorig menu"<<endl;
							cout<<"Geef uw keuze: ";
							cin>>keuze_klant_sub_menu;
							system("cls");
							if(keuze_klant_sub_menu==0){
								break;
							}else{
								//myDummyTicket->printTicket(); ===>> IS FAKE. Gewoon voor de lol.
								cout<<"Uw Ticket wordt nu geprint!"<<endl;
								break;
							}
							break;
							   }
						case 2:{ //Ticket annuleren *DISCUSSIE PUNT ANNULATIE ENKEL VIP TICKETS OF ALLE TICKETS*
							cout<<"Geef TicketID in: ";
							cin>>ticketID;
							system("cls");
#ifndef Databank_Offline
							myDummyTicket = TicketDAO::getTicket(ticketID);
#else
							myDummyTicket = OTicketDAO::getTicket(ticketID);
#endif
							while(myDummyTicket == 0){
								cout << "Dit ticket bestaat niet. Geef een nieuw TicketID in: ";
								cin >> ticketID;
								system("cls");
#ifndef Databank_Offline
								myDummyTicket = TicketDAO::getTicket(ticketID);
#else
								myDummyTicket = OTicketDAO::getTicket(ticketID);
#endif
							}
							cout <<endl<< "Hier zijn uw gegevens: " << endl<<endl;
							cout << myDummyTicket->toString();

							cout<<endl;
							cout<<"1. Ticket verwijderen"<<endl;
							cout<<endl;
							cout<<"0. Terug"<<endl;
							cout<<"Geef uw keuze: ";
							cin>>keuze_klant_sub_menu;
							system("cls");
							if(keuze_klant_sub_menu==0){
								break;
							}else{
#ifndef Databank_Offline
								TicketDAO::removeTicket(ticketID);
#else
								OTicketDAO::verwijderTicket(ticketID);
#endif
								cout<<"Uw Ticket is verwijderd!"<<endl;
								break;
							}


							break;
							   }
						case 3:{ // * EXTRA * KASSA FUNCTIE *scannen voucher_ticket* Bespreken!!!
							Klant * myDummyKlant = new Klant;
							bool banned = false;
							string rijksregisternr;

							cout<<"Geef rijksregisterNr in AUB: "<<endl;
							cin>>rijksregisternr;

#ifndef Databank_Offline
							myDummyKlant = KlantDAO::findKlantByRijksregisternr(rijksregisternr);
#else
							myDummyKlant = OKlantDAO::getKlant(OKlantDAO::getKlantViaRijksregisterNr(rijksregisternr));
#endif

							banned = myDummyKlant->checkBan();

							if(banned==true){

								cout<<endl<<endl<<"WEIGER DEZE PERSOON TOEGANG TOT HET COMPLEX!!!"<<endl<<endl;

								break;
							}else{
								cout<<endl<<endl<<"Klant OK! Welkom :-)"<<endl;
							}

							break;
							delete myDummyKlant;
							   }
						default:
							break;
						}
					} while (keuze_menu_admin_ticket!=0);
					break;
					delete myDummyTicket;
						}
				case 3: { //Abbonement beheer - Abbonement opzoeken en mogelijkheid tot afprinten

					Abbonement * myDummyAbbonement = new Abbonement;

					int abbonementID;

					do
					{
						menu->showAbbonementAdminMenu();
						cin>>keuze_menu_admin_abbonement;
						system("cls");
						switch (keuze_menu_admin_abbonement)
						{
						case 1:{ //Abbonement opzoeken (en mogelijkheid tot afprinten)

							cout<<"Geef AbbonementID in: ";
							cin>>abbonementID;
							system("cls");
#ifndef Databank_Offline
							myDummyAbbonement = AbbonementDAO::getAbbonement(abbonementID);
#else
							myDummyAbbonement = OAbbonementDAO::getAbbonement(abbonementID);
#endif
							while(myDummyAbbonement == 0){
								cout << "Dit abbonement bestaat niet. Probeer opnieuw." << endl;
								cout<<"Geef AbbonementID in: ";
								cin>>abbonementID;
								system("cls");
#ifndef Databank_Offline
								myDummyAbbonement = AbbonementDAO::getAbbonement(abbonementID);
#else
								myDummyAbbonement = OAbbonementDAO::getAbbonement(abbonementID);
#endif
							}
							cout <<endl<< "Hier zijn uw gegevens: " << endl<<endl;
							cout << myDummyAbbonement->toString();

							cout<<endl;
							cout<<"1. Abbonement afprinten"<<endl;
							cout<<endl;
							cout<<"0. Terug naar vorig menu"<<endl;
							cout<<"Geef uw keuze: ";
							cin>>keuze_klant_sub_menu;
							system("cls");
							if(keuze_klant_sub_menu==0){
								break;
							}else{
								//myDummyAbbonement->printAbbonement(); ===>> IS FAKE. Gewoon voor de lol.
								cout<<"Uw Abbonement wordt nu geprint!"<<endl;
								break;
							}

							break;
							   }
						case 2:{ //Abbonement annuleren
							char answer;

							cout<<"Geef AbbonementID in: ";
							cin>>abbonementID;
							system("cls");
#ifndef Databank_Offline
							myDummyAbbonement = AbbonementDAO::getAbbonement(abbonementID);
#else
							myDummyAbbonement = OAbbonementDAO::getAbbonement(abbonementID);
#endif
							while(myDummyAbbonement == 0){
								cout << "Dit abbonement bestaat niet. Probeer opnieuw." << endl;
								cout<<"Geef AbbonementID in: ";
								cin>>abbonementID;
								system("cls");
#ifndef Databank_Offline
								myDummyAbbonement = AbbonementDAO::getAbbonement(abbonementID);
#else
								myDummyAbbonement = OAbbonementDAO::getAbbonement(abbonementID);
#endif
							}
							cout <<endl<< "Hier zijn uw gegevens: " << endl<<endl;
							cout << myDummyAbbonement->toString();

							cout<<"Bent u zeker dat u dit wilt annuleren? (Y/N)"<<endl;
							cin>>answer;
							system("cls");
							if(answer=='Y'||answer=='y'){
#ifndef Databank_Offline
								AbbonementDAO::removeAbbonement(abbonementID);
#else
								OAbbonementDAO::verwijderAbbonement(abbonementID);
#endif
								cout << "Uw abbonement is verwijderd!" << endl;
							}else{
								break;
							}

							break;
							   }
						default:
							break;
						}
					} while (keuze_menu_admin_abbonement!=0);
					break;
					delete myDummyAbbonement;
						}
				case 4: { //Matchen beheer
					menu->showMatchenAdminMenu();
					cin>>keuze_menu_admin_match;

					switch (keuze_menu_admin_match)
					{
					case 1:{
						string match_datum;
						int keuze_tegenstander, keuze_ploeg;
						int matchID = 0;

						cout<<"Geef matchdatum: ";
						cin>>match_datum;

						cout<<"Kies een Stadion/Ploeg: "<<endl<<endl;
						menu->getAllePloegen();
						cin>>keuze_ploeg;

						cout<<endl<<"Kies een Tegenstander: "<<endl<<endl;
						menu->getAlleTegenstanders();
						cin>>keuze_tegenstander;

						Match * myMatch = new Match(match_datum,keuze_ploeg, keuze_tegenstander);
#ifndef Databank_Offline
						Match * tempMatch = MatchDAO::saveMatch(myMatch);

						cout<<endl<<"Match aangemaakt!"<<endl<<endl;


						vector<Match*> matchen = MatchDAO::getAll();

						for(int y=0;y<matchen.size();y++){
							Match * Tmatch = matchen.at(y);

							matchID=Tmatch->getMatchID();
							cout<<matchID;
						}

						vector<Vak*> vakken = VakDAO::getAll();

						for(int i=0;i<vakken.size();i++){
							Vak * Tvak = vakken.at(i);

							for(int t=1;t<=Tvak->getCapaciteit();t++){
								Zitje * myZitje = new Zitje(Tvak->getVakID(),matchID,t);

								Zitje * tempZitje = ZitjeDAO::maakZitje(myZitje);

							}

							cout<<"Er zijn "<<Tvak->getCapaciteit()<<" aantal Stoelen aangemaakt voor Vak "<<Tvak->getNaam()<<endl;
						}
#endif
						cout<<endl<<endl<<"Alle stoelen zijn geset voor de match. Ticket verkoop gestart! "<<endl;

						break;
						delete myMatch;
						   }
					case 2:{

						cout<<"Kies een match die u wilt afsluiten: "<<endl;
						menu->toonAlleMatchen();
						cin>>keuze_match;

						bool gelukt=false;
#ifndef Databank_Offline
						gelukt = ZitjeDAO::removeZitjesMatch(keuze_match);
#endif
						if(gelukt){
							cout<<"Alle zitjes zijn verwijderd"<<endl;
						}else{
							cout<<"ERROR"<<endl;
						}

						gelukt=false;
#ifndef Databank_Offline
						gelukt = MatchDAO::removeMatch(keuze_match);
#endif
						if(gelukt){
							cout<<"De match is verwijderd"<<endl;
						}else{
							cout<<"ERROR"<<endl;
						}

						break;
						   }
					default:
						break;
					}

					break;
						}
				case 5: { //Blacklist beheer
					do
					{
						menu->showBlacklistAdminMenu();
						cin>>keuze_menu_admin_blacklist;
						system("cls");
						switch (keuze_menu_admin_blacklist)
						{
						case 1:{ //Alle blacklisten tonen
							//menu->toonBans(); //==>>> alle bans tonen. Pure DB select query van tblBans
							break;
							   }
						case 2:{ //Blacklisting toevoegen
							int klantnr;
							string van,tot;

							Klant * myDummyKlant = new Klant;

							cout<<endl<<"Geef klant nummer op: ";
							cin>>klantnr;
							system("cls");

#ifndef Databank_Online
							myDummyKlant = OKlantDAO::getKlant(klantnr);
#else
							//online DAO
#endif

							cout<<"Geef start datum op: "; //kan vervangen worden door huidige datum
							cin>>van;

							cout<<"Geef eind datum op: ";
							cin>>tot;
							system("cls");
							//myDummyKlant->banKlant(van,tot); // ===>> void functie. voert DB insert functie uit die de ban aanmaakt

							break;
							delete myDummyKlant;
							   }
						case 3:{ //Blacklisting annuleren
							int klantnr;

							Klant * myDummyKlant = new Klant;

							cout<<endl<<"Geef klant nummer op: ";
							cin>>klantnr;
							system("cls");
#ifndef Databank_Online
							myDummyKlant = OKlantDAO::getKlant(klantnr);
#else
							//online DAO
#endif

							//myDummyKlant -> unBan(); // ===>> void functie. Voert DB delete functie uit die de ban annuleert

							break;
							delete myDummyKlant;
							   }
						default:
							break;
						}
					} while (keuze_menu_admin_blacklist!=0);
					break;
						}
				default:
					break;
				}
			}while(keuze_menu_admin!=0);

			break;
			}
		default:
			break;
		}


	}while(keuze!=0);

	//--------Program Ending----------

	//--Classes Destructen && andere delete's
	delete menu;
	delete myKlant;

	//--System Pause
	cout<<endl<<endl;
	system("PAUSE");
	return 0;
}

bool SetWindow(int Width, int Height) 
{ 
	_COORD coord; 
	coord.X = Width; 
	coord.Y = Height; 

	_SMALL_RECT Rect; 
	Rect.Top = 0; 
	Rect.Left = 0; 
	Rect.Bottom = Height - 1; 
	Rect.Right = Width - 1; 

	// Get handle of the standard output 
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE); 
	if (Handle == NULL) 
	{ 
		cout<<"Failure in getting the handle\n"<<GetLastError(); 
		return FALSE; 
	} 

	// Set screen buffer size to that specified in coord 
	if(!SetConsoleScreenBufferSize(Handle, coord)) 
	{ 
		cout<<"Failure in setting buffer size\n"<<GetLastError(); 
		return FALSE; 
	} 

	// Set the window size to that specified in Rect 
	if(!SetConsoleWindowInfo(Handle, TRUE, &Rect)) 
	{ 
		cout<<"Failure in setting window size\n"<<GetLastError(); 
		return FALSE; 
	} 

	return TRUE; 
} 

