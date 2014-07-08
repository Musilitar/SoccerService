#pragma once
#include "stdafx.h"
#include "OKlantDAO.h"
#include <iostream>
#ifndef Databank_Online

vector<Klant*> OKlantDAO::klanten = vector<Klant*>();

//Objecten in database steken
void OKlantDAO::initialisatie()
{
	klanten.push_back(new Klant(0, "Lode", "Lesage", "Geenstraat", "9000", "Gent", "Belgie", "0458521245", "lode@onbestaand.be", "admin1", "1", "93.12.04-253.65", "admin1", "admin1", 1));
	klanten.push_back(new Klant(1, "Sam", "Junius", "Broccolistraat", "7210", "Aalst", "Belgie", "0428541495", "sam@onbestaand.be", "admin2", "2", "91.09.25-123.25", "admin2", "admin2", 2));
	klanten.push_back(new Klant(2, "Emmanuel", "Vandenbergh", "Broccolistraat", "7210", "Aalst", "Belgie", "0428541495", "sam@onbestaand.be", "admin2", "2", "91.09.25-123.25", "admin3", "admin3", 3));
	klanten.push_back(new Klant(3, "Dany", "Thys", "Broccolistraat", "7210", "Aalst", "Belgie", "0428541495", "sam@onbestaand.be", "admin2", "2", "91.09.25-123.25", "admin4", "admin4", 4));
}

//Opkuisen van database
void OKlantDAO::maakLeeg()
{
	for(int i =0; i < klanten.size(); i++)
	{
		if(klanten.at(i)!=NULL)
			delete klanten.at(i);
	}
}

bool OKlantDAO::verwijderKlant(int id)
{
	Klant* temp = getKlant(id);
	if(temp == 0)
	{
		return false;
	}
	klanten.erase(klanten.begin()+getPositie(id));
	delete temp;
	return true;
}

vector<Klant*> OKlantDAO::getAlles()
{
	return klanten;
}

Klant* OKlantDAO::getKlant(int id)
{
	for(int i =0; i < klanten.size(); i++)
	{
		Klant* temp = klanten.at(i);
		if(temp->getKlantID() == id)
			return temp;
	}
	return 0;
}

//Geeft de positie van een element in de array; Enkel noodzakelijk om de database te simuleren
int OKlantDAO::getPositie(int id)
{
	for(int i = 0; i < klanten.size(); i++)
	{
		Klant* temp = klanten.at(i);
		if(temp->getKlantID() == id)
			return i;
	}
	return -1;
}

Klant* OKlantDAO::bewaarKlant(Klant* klant)
{
	if(klant->getKlantID() == -1)
	{
		//Dit is een nieuw adres en simuleert de toekenning van een sequentiële ID door de database
		Klant* temp = klanten.at(klanten.size()-1);
		int nieuweID = temp->getKlantID()+1;
		klant->setKlantID(nieuweID);
	}
	Klant* temp = getKlant(klant->getKlantID());
	if(temp == 0)
	{
		klanten.push_back(klant);
		return klant;
	}
	else
	{
		//Klant updaten
		temp->setKlantID(klant->getKlantID()); 
		temp->setKlantType(klant->getKlantType());
		temp->setKlantVnaam(klant->getKlantVnaam());
		temp->setKlantFnaam(klant->getKlantFnaam());
		temp->setKlantStraat(klant->getKlantStraat()); 
		temp->setKlantPostcode(klant->getKlantPostcode());
		temp->setKlantGemeente(klant->getKlantGemeente());
		temp->setKlantLand(klant->getKlantLand()); 
		temp->setKlantTelefoon(klant->getKlantTelefoon());
		temp->setKlantEmail(klant->getKlantEmail());
		temp->setKlantBedrijfsnaam(klant->getKlantBedrijfsnaam());
		temp->setKlantBTW(klant->getKlantBTW());
		temp->setKlantRijksregister(klant->getKlantRijksregister());
		temp->setKlantGnaam(klant->getKlantGnaam());
		temp->setKlantWachtwoord(klant->getKlantWachtwoord());
		return temp;
	}
}

vector<Klant*> OKlantDAO::vindKlantDoorID(int id)
{
	vector<Klant*> results = vector<Klant*>();
	for(int i =0; i < klanten.size(); i++)
	{
		Klant* temp = klanten.at(i);
		if(temp->getKlantID() == id)
			results.push_back(temp);
	}
	return results;
}

int OKlantDAO::vindKlantDoorGnaam(string gnaam)
{
	for(int i =0; i < klanten.size(); i++)
	{
		Klant* temp = klanten.at(i);
		if(temp->getKlantGnaam() == gnaam)
			return temp->getKlantID();
	}
	return -1;
}

Klant* OKlantDAO::vindKlantDoorNaam(string vnaam, string anaam)
{
	for(int i =0; i < klanten.size(); i++)
	{
		Klant* temp = klanten.at(i);
		if((temp->getKlantVnaam() == vnaam)&&(temp->getKlantFnaam() == anaam))
			return temp;
	}
	return 0;
}



int OKlantDAO::getKlantViaRijksregisterNr(string rijksregister)
{
	for(int i =0; i < klanten.size(); i++)
	{
		Klant* temp = klanten.at(i);
		if(temp->getKlantRijksregister() == rijksregister)
			return temp->getKlantID();
	}
	return -1;
}
#endif