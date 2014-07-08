#include "stdafx.h"
#include "OZitjeDAO.h"

vector<Zitje*> OZitjeDAO::zitjes = vector<Zitje*>();

void OZitjeDAO::initialisatie()
{
	zitjes.push_back(new Zitje(1,1,101,1,1));
	zitjes.push_back(new Zitje(1,2,102,1,2));
	zitjes.push_back(new Zitje(2,1,201,1,3));
	zitjes.push_back(new Zitje(3,1,301,1,4));
	zitjes.push_back(new Zitje(3,2,302,1,5));
	zitjes.push_back(new Zitje(3,1,303,1,6));
	zitjes.push_back(new Zitje(4,1,401,1,7));
	zitjes.push_back(new Zitje(5,1,402,1,8));
	zitjes.push_back(new Zitje(5,2,501,1,9));

	//Alle vakken hebben klantID 1 omdat het gaat om de functionaliteiten van de database.
	//voor een realistische database --> zien online
}

//int vakID, int matchID, int nummer,int klantID,int id

void OZitjeDAO::maakLeeg()
{
	for(int i =0; i < zitjes.size(); i++)
	{
		if(zitjes.at(i)!=NULL)
			delete zitjes.at(i);
	}
}

bool OZitjeDAO::verwijderZitje(int id)
{
	Zitje* temp = getZitje(id);
	if(temp == 0)
	{
		return false;
	}
	zitjes.erase(zitjes.begin()+getPositie(id));
	delete temp;
	return true;
}

vector<Zitje*> OZitjeDAO::getAlles()
{
	return zitjes;
}

Zitje* OZitjeDAO::getZitje(int id)
{
	for(int i =0; i < zitjes.size(); i++)
	{
		Zitje* temp = zitjes.at(i);
		if(temp->getZitjeID() == id)
			return temp;
	}
	return 0;
}

//Geeft de positie van een element in de array; Enkel noodzakelijk om de database te simuleren
int OZitjeDAO::getPositie(int id)
{
	for(int i = 0; i < zitjes.size(); i++)
	{
		Zitje* temp = zitjes.at(i);
		if(temp->getZitjeID() == id)
			return i;
	}
	return -1;
}

Zitje* OZitjeDAO::bewaarZitje(Zitje* vak)
{
	if(vak->getZitjeID() == -1)
	{
		//Dit is een nieuw adres en simuleert de toekenning van een sequentiële ID door de database
		Zitje* temp = zitjes.at(zitjes.size()-1);
		int nieuweID = temp->getZitjeID()+1;
		vak->setZitjeID(nieuweID);
	}
	Zitje* temp = getZitje(vak->getZitjeID());
	if(temp == 0)
	{
		zitjes.push_back(vak);
		return vak;
	}
	else
	{
		//Vak updaten
		temp->setZitjeID(vak->getZitjeID());
		return temp;
	}
}

vector<Zitje*> OZitjeDAO::vindZitjeDoorID(int ID)
{
	vector<Zitje*> results = vector<Zitje*>();
	for(int i =0; i < zitjes.size(); i++)
	{
		Zitje* temp = zitjes.at(i);
		if(temp->getZitjeID() == ID)
			results.push_back(temp);
	}
	return results;
}

int OZitjeDAO::reserveerVolgendeVrijeZitje(int vakID)
{
	Vak* temp = OVakDAO::getVak(vakID);
	int zitjeID = temp->getBezettePlaatsen();
	temp->setBezettePlaatsen(temp->getBezettePlaatsen() + 1);
	return zitjeID += 1;
}

