#include "stdafx.h"
#include "OMatchDAO.h"
#include <iostream>

vector<Match*> OMatchDAO::matchen = vector<Match*>();

//Objecten in database steken
void OMatchDAO::initialisatie()
{
	matchen.push_back(new Match("04/09/2013",1, 2, 1));
	matchen.push_back(new Match("09/09/2013",1, 1, 2));
	matchen.push_back(new Match("12/09/2013",1, 2, 3));
}

//Opkuisen van database
void OMatchDAO::maakLeeg()
{
	for(int i =0; i < matchen.size(); i++)
	{
		if(matchen.at(i)!=NULL)
			delete matchen.at(i);
	}
}

bool OMatchDAO::verwijderMatch(int id)
{
	Match* temp = getMatch(id);
	if(temp == 0)
	{
		return false;
	}
	matchen.erase(matchen.begin()+getPositie(id));
	delete temp;
	return true;
}

vector<Match*> OMatchDAO::getAlles()
{
	return matchen;
}

Match* OMatchDAO::getMatch(int id)
{
	for(int i =0; i < matchen.size(); i++)
	{
		Match* temp = matchen.at(i);
		if(temp->getMatchID() == id)
			return temp;
	}
	return 0;
}

//Geeft de positie van een element in de array; Enkel noodzakelijk om de database te simuleren
int OMatchDAO::getPositie(int id)
{
	for(int i = 0; i < matchen.size(); i++)
	{
		Match* temp = matchen.at(i);
		if(temp->getMatchID() == id)
			return i;
	}
	return -1;
}

Match* OMatchDAO::bewaarMatch(Match* match)
{
	if(match->getMatchID() == -1)
	{
		//Dit is een nieuw adres en simuleert de toekenning van een sequentiële ID door de database
		Match* temp = matchen.at(matchen.size()-1);
		int nieuweID = temp->getMatchID()+1;
		match->setMatchID(nieuweID);
	}
	Match* temp = getMatch(match->getMatchID());
	if(temp == 0)
	{
		matchen.push_back(match);
		return match;
	}
	else
	{
		//Match updaten
		temp->setMatchID(match->getMatchID()); 
		temp->setMatchDatum(match->getMatchDatum());
		return temp;
	}
}

vector<Match*> OMatchDAO::vindMatchDoorID(int id)
{
	vector<Match*> results = vector<Match*>();
	for(int i =0; i < matchen.size(); i++)
	{
		Match* temp = matchen.at(i);
		if(temp->getMatchID() == id)
			results.push_back(temp);
	}
	return results;
}