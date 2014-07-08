#include "stdafx.h"
#include "OAbbonementDAO.h"
#include <iostream>


vector<Abbonement*> OAbbonementDAO::abbonementen = vector<Abbonement*>();

//Objecten in database steken
void OAbbonementDAO::initialisatie()
{
	abbonementen.push_back(new Abbonement(1,3,1,1));
}

//Abbonement(int klant, int vak, int type,int id)

bool OAbbonementDAO::verwijderAbbonement(int id)
{
	Abbonement* temp = getAbbonement(id);
	if(temp == 0)
	{
		return false;
	}
	abbonementen.erase(abbonementen.begin()+getPositie(id));
	delete temp;
	return true;
}

vector<Abbonement*> OAbbonementDAO::getAlles()
{
	return abbonementen;
}

Abbonement* OAbbonementDAO::getAbbonement(int id)
{
	for(int i =0; i < abbonementen.size(); i++)
	{
		Abbonement* temp = abbonementen.at(i);
		if(temp->getAbbonementID() == id)
			return temp;
	}
	return 0;
}

string OAbbonementDAO::getAbbonementWithKlantID(int id)
{
	stringstream ss;

	ss << "Alle abbonementen van de klant" << endl;
	ss << "------------------------------" << endl;
	
	for(int i =0; i < abbonementen.size(); i++)
	{
		Abbonement* temp = abbonementen.at(i);
		if(temp->getAbbonementKlantID() == id)
		{	
			ss << temp->toString();
			ss << "------------------------------" << endl;
		}
		//delete temp;
	}
	return ss.str();
}

//Geeft de positie van een element in de array; Enkel noodzakelijk om de database te simuleren
int OAbbonementDAO::getPositie(int id)
{
	for(int i = 0; i < abbonementen.size(); i++)
	{
		Abbonement* temp = abbonementen.at(i);
		if(temp->getAbbonementID() == id)
			return i;
	}
	return -1;
}

Abbonement* OAbbonementDAO::bewaarAbbonement(Abbonement* abbonement)
{
	if(abbonement->getAbbonementID() == -1)
	{
		//Dit is een nieuw adres en simuleert de toekenning van een sequentiële ID door de database
		Abbonement* temp = abbonementen.at(abbonementen.size()-1);
		int nieuweID = temp->getAbbonementID()+1;
		abbonement->setAbbonementID(nieuweID);
	}
	Abbonement* temp = getAbbonement(abbonement->getAbbonementID());
	if(temp == 0)
	{
		abbonementen.push_back(abbonement);
		return abbonement;
	}
	else
	{
		//Abbonement updaten
		temp->setAbbonementID(abbonement->getAbbonementID());
		temp->setAbbonementKlantID(abbonement->getAbbonementKlantID());
		temp->setAbbonementVakID(abbonement->getAbbonementVakID());
		return temp;
	}
}