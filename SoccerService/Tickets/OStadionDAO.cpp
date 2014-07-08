#include "stdafx.h"
#include "OStadionDAO.h"
#include <iostream>

vector<Stadion*> OStadionDAO::stadions = vector<Stadion*>();

//Objecten in database steken
void OStadionDAO::initialisatie()
{
	stadions.push_back(new Stadion("Koningboudewijnstadion", "Gert Verhulst", "Koningsstraat 48 1000 Brussel", "0272548595", 1));
	stadions.push_back(new Stadion("Dummystadionnaam", "Samson", "Koninginnenstraat 84 1000 Brussel", "0123456789", 2));
}

bool OStadionDAO::verwijderStadion(int id)
{
	Stadion* temp = getStadion(id);
	if(temp == 0)
	{
		return false;
	}
	stadions.erase(stadions.begin()+getPositie(id));
	delete temp;
	return true;
}

vector<Stadion*> OStadionDAO::getAlles()
{
	return stadions;
}

Stadion* OStadionDAO::getStadion(int id)
{
	for(int i =0; i < stadions.size(); i++)
	{
		Stadion* temp = stadions.at(i);
		if(temp->getStadionID() == id)
			return temp;
	}
	return 0;
}

//Geeft de positie van een element in de array; Enkel noodzakelijk om de database te simuleren
int OStadionDAO::getPositie(int id)
{
	for(int i = 0; i < stadions.size(); i++)
	{
		Stadion* temp = stadions.at(i);
		if(temp->getStadionID() == id)
			return i;
	}
	return -1;
}

Stadion* OStadionDAO::bewaarStadion(Stadion* stadion)
{
	if(stadion->getStadionID() == -1)
	{
		//Dit is een nieuw adres en simuleert de toekenning van een sequentiële ID door de database
		Stadion* temp = stadions.at(stadions.size()-1);
		int nieuweID = temp->getStadionID()+1;
		stadion->setStadionID(nieuweID);
	}
	Stadion* temp = getStadion(stadion->getStadionID());
	if(temp == 0)
	{
		stadions.push_back(stadion);
		return stadion;
	}
	else
	{
		//Stadion updaten
		temp->setStadionID(stadion->getStadionID());
		temp->setStadionName(stadion->getStadionName());
		temp->setStadionManager(stadion->getStadionManager());
		temp->setStadionAddress(stadion->getStadionAddress());
		temp->setStadionTelefoon(stadion->getStadionTelefoon());
		return temp;
	}
}