#include "stdafx.h"
#include "OTegenstandersDAO.h"
#include <iostream>


vector<Tegenstanders*> OTegenstandersDAO::tegenstandersen = vector<Tegenstanders*>();

//Objecten in database steken
void OTegenstandersDAO::initialisatie()
{
	tegenstandersen.push_back(new Tegenstanders("Mechelen", 1));
	tegenstandersen.push_back(new Tegenstanders("Bende Janetten FC", 2));
}

bool OTegenstandersDAO::verwijderTegenstanders(int id)
{
	Tegenstanders* temp = getTegenstanders(id);
	if(temp == 0)
	{
		return false;
	}
	tegenstandersen.erase(tegenstandersen.begin()+getPositie(id));
	delete temp;
	return true;
}

vector<Tegenstanders*> OTegenstandersDAO::getAlles()
{
	return tegenstandersen;
}

Tegenstanders* OTegenstandersDAO::getTegenstanders(int id)
{
	for(int i =0; i < tegenstandersen.size(); i++)
	{
		Tegenstanders* temp = tegenstandersen.at(i);
		if(temp->getTegenstanderID() == id)
			return temp;
	}
	return 0;
}

//Geeft de positie van een element in de array; Enkel noodzakelijk om de database te simuleren
int OTegenstandersDAO::getPositie(int id)
{
	for(int i = 0; i < tegenstandersen.size(); i++)
	{
		Tegenstanders* temp = tegenstandersen.at(i);
		if(temp->getTegenstanderID() == id)
			return i;
	}
	return -1;
}

Tegenstanders* OTegenstandersDAO::bewaarTegenstanders(Tegenstanders* tegenstanders)
{
	if(tegenstanders->getTegenstanderID() == -1)
	{
		//Dit is een nieuw adres en simuleert de toekenning van een sequentiële ID door de database
		Tegenstanders* temp = tegenstandersen.at(tegenstandersen.size()-1);
		int nieuweID = temp->getTegenstanderID()+1;
		tegenstanders->setTegenstanderID(nieuweID);
	}
	Tegenstanders* temp = getTegenstanders(tegenstanders->getTegenstanderID());
	if(temp == 0)
	{
		tegenstandersen.push_back(tegenstanders);
		return tegenstanders;
	}
	else
	{
		//Abbonement updaten
		temp->setTegenstanderID(tegenstanders->getTegenstanderID());
		temp->setTegenstanderNaam(tegenstanders->getTegenstanderNaam());
		return temp;
	}
}