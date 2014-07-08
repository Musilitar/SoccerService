#include "stdafx.h"
#include "OBanDAO.h"
#include <iostream>


vector<Ban*> OBanDAO::bannen = vector<Ban*>();

//Objecten in database steken
void OBanDAO::initialisatie()
{
	bannen.push_back(new Ban("12/04/2013", "12/04/2014", 2, 1));
}

bool OBanDAO::verwijderBan(int id)
{
	Ban* temp = getBan(id);
	if(temp == 0)
	{
		return false;
	}
	bannen.erase(bannen.begin()+getPositie(id));
	delete temp;
	return true;
}

vector<Ban*> OBanDAO::getAlles()
{
	return bannen;
}

Ban* OBanDAO::getBan(int id)
{
	for(int i =0; i < bannen.size(); i++)
	{
		Ban* temp = bannen.at(i);
		if(temp->getBanID() == id)
			return temp;
	}
	return 0;
}

//Geeft de positie van een element in de array; Enkel noodzakelijk om de database te simuleren
int OBanDAO::getPositie(int id)
{
	for(int i = 0; i < bannen.size(); i++)
	{
		Ban* temp = bannen.at(i);
		if(temp->getBanID() == id)
			return i;
	}
	return -1;
}

Ban* OBanDAO::bewaarBan(Ban* ban)
{
	if(ban->getBanID() == -1)
	{
		//Dit is een nieuw adres en simuleert de toekenning van een sequentiële ID door de database
		Ban* temp = bannen.at(bannen.size()-1);
		int nieuweID = temp->getBanID()+1;
		ban->setBanID(nieuweID);
	}
	Ban* temp = getBan(ban->getBanID());
	if(temp == 0)
	{
		bannen.push_back(ban);
		return ban;
	}
	else
	{
		//Gebande personen updaten
		temp->setBanID(ban->getBanID());
		temp->setBanVanaf(ban->getBanVanaf());
		temp->setBanTot(ban->getBanTot());
		temp->setBanKlantID(ban->getBanKlantID());
		return temp;
	}
}

vector<Ban*> OBanDAO::vindBanDoorKlantID(int id)
{
	vector<Ban*> results = vector<Ban*>(); 
	for(int i =0; i < bannen.size(); i++)
	{
		Ban* temp = bannen.at(i);
		if(temp->getBanKlantID() == id){
			results.push_back(temp);
		}
	}
	return results;
}