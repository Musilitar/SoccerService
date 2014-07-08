#include "stdafx.h"

vector<Vak*> OVakDAO::vakken = vector<Vak*>();

//Objecten in database steken
void OVakDAO::initialisatie()
{
	vakken.push_back(new Vak("Vak A", 25, false, 100, false, 50, 1));
	vakken.push_back(new Vak("Vak B", 30, false, 100, true, 97, 2));
	vakken.push_back(new Vak("Vak C", 15, false, 100, true, 60, 3));
	vakken.push_back(new Vak("VIP", 250, true, 25, false, 10, 4));
}

//Opkuisen van database
void OVakDAO::maakLeeg()
{
	for(int i =0; i < vakken.size(); i++)
	{
		if(vakken.at(i)!=NULL)
			delete vakken.at(i);
	}
}

bool OVakDAO::verwijderVak(int id)
{
	Vak* temp = getVak(id);
	if(temp == 0)
	{
		return false;
	}
	vakken.erase(vakken.begin()+getPositie(id));
	delete temp;
	return true;
}

vector<Vak*> OVakDAO::getAlles()
{
	return vakken;
}

Vak* OVakDAO::getVak(int id)
{
	for(int i =0; i < vakken.size(); i++)
	{
		Vak* temp = vakken.at(i);
		if(temp->getVakID() == id)
			return temp;
	}
	return 0;
}
int OVakDAO::getKost(int id)
{
	for(int i = 0; i < vakken.size(); i++)
	{
		Vak* temp = vakken.at(i);
		if(temp->getVakID() == id)
			return temp->getVakKost();
	}
	return 0;
}
int OVakDAO::getVakID(int id)
{
	for(int i = 0; i < vakken.size(); i++)
	{
		Vak* temp = vakken.at(i);
		if(temp->getVakID() == id)
			return id;
	}
	return 0;
}

//Geeft de positie van een element in de array; Enkel noodzakelijk om de database te simuleren
int OVakDAO::getPositie(int id)
{
	for(int i = 0; i < vakken.size(); i++)
	{
		Vak* temp = vakken.at(i);
		if(temp->getVakID() == id)
			return i;
	}
	return -1;
}

Vak* OVakDAO::bewaarVak(Vak* vak)
{
	if(vak->getVakID() == -1)
	{
		//Dit is een nieuw adres en simuleert de toekenning van een sequentiële ID door de database
		Vak* temp = vakken.at(vakken.size()-1);
		int nieuweID = temp->getVakID()+1;
		vak->setVakID(nieuweID);
	}
	Vak* temp = getVak(vak->getVakID());
	if(temp == 0)
	{
		vakken.push_back(vak);
		return vak;
	}
	else
	{
		//Vak updaten
		temp->setVakID(vak->getVakID());
		return temp;
	}
}

vector<Vak*> OVakDAO::vindVakDoorID(int ID)
{
	vector<Vak*> results = vector<Vak*>();
	for(int i =0; i < vakken.size(); i++)
	{
		Vak* temp = vakken.at(i);
		if(temp->getVakID() == ID)
			results.push_back(temp);
	}
	return results;
}

//vector<int> OVakDAO::vindVrijeVakken()
//{
//	vector<int> vrijeVakken;
//	for(int i = 0; i < vakken.size(); i++){
//		if(OZitjeDAO::vindEersteVrijeZitjeDoorVak(i) != 0)
//			vrijeVakken.push_back(i);
//	}
//	return vrijeVakken;
//}