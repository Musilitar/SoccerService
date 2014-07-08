#include "stdafx.h"
#include "Stadion.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Stadion::Stadion(void)
{
	setStadionID(0);
	setStadionName("");
	setStadionManager("");
	setStadionAddress("");
	setStadionTelefoon("");
}
Stadion::Stadion(int id)
{
	setStadionID(id);
	//Rest ophalen op basis van ID
}

Stadion::Stadion(string name, string manager, string address, string telefoon, int id)
{
	setStadionID(id);
	setStadionName(name);
	setStadionManager(manager);
	setStadionAddress(address);
	setStadionTelefoon(telefoon);
}

Stadion::~Stadion(void){}

int Stadion::getStadionID(){return myStadionID;}
string Stadion::getStadionName(){return myStadionName;}
string Stadion::getStadionManager(){return myStadionManager;}
string Stadion::getStadionAddress(){return myStadionAddress;}
string Stadion::getStadionTelefoon(){return myStadionTelefoon;}

void Stadion::setStadionID(int id){myStadionID = id;}
void Stadion::setStadionName(string naam){myStadionName = naam;}
void Stadion::setStadionManager(string manager){myStadionManager = manager;}
void Stadion::setStadionAddress(string adres){myStadionAddress = adres;}
void Stadion::setStadionTelefoon(string telefoon){myStadionTelefoon = telefoon;}

string Stadion::toString()
{
	stringstream ss;
	ss << "ID: " << getStadionID() << endl;
	ss << "Stadionnaam: " << getStadionName() << endl;
	ss << "Manager: " << getStadionManager() << endl;
	ss << "Adres: " << getStadionAddress() << endl;
	ss << "Telefoonnummer: " << getStadionTelefoon() << endl;
	ss << endl;
	return ss.str();
}
