#include "stdafx.h"
#include "Abbonement.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Abbonement::Abbonement()
{
	setAbbonementID(0); 

}
Abbonement::Abbonement(int klant, int vak, int type,int id)
{
	setAbbonementID(id); 
	setAbbonementKlantID(klant);
	setAbbonementVakID(vak);
	setAbbonementTypeID(type); 
}


Abbonement::~Abbonement(void)
{
}
int Abbonement::getAbbonementID()
{
	return myAbbonementID;
}

int Abbonement::getAbbonementKlantID()
{
	return myAbbonementKlantID;
}
int Abbonement::getAbbonementVakID()
{
	return myAbbonementVakID;
}
int Abbonement::getAbbonementTypeID(){
	return myAbbonementTypeID;
}

void Abbonement::setAbbonementID(int abbonementID)
{
	myAbbonementID = abbonementID;
}

void Abbonement::setAbbonementKlantID(int klantID)
{
	myAbbonementKlantID = klantID;
}
void Abbonement::setAbbonementVakID(int vakID)
{
	myAbbonementVakID = vakID;
}
void Abbonement::setAbbonementTypeID(int typeID){
	myAbbonementTypeID = typeID;
}


string Abbonement::maakAbbonement (int klantID, int vakID, int typeID)
{
#ifndef Databank_Online
	Abbonement* newAbbonement = new Abbonement(klantID, vakID, typeID, -1);
	Abbonement* tempAbbonement = OAbbonementDAO::bewaarAbbonement(newAbbonement);
#else
	Abbonement* newAbbonement = new Abbonement(klantID, vakID, typeID);
	Abbonement* tempAbbonement = AbbonementDAO::maakAbbonement(newAbbonement);
#endif

	stringstream ss;

	ss << endl<< "Abbonement aangekocht!" << endl;
	ss << endl << "Info van abbonement" << endl;
	ss << tempAbbonement->toString() << endl << endl;

	return ss.str();
	delete newAbbonement;
	delete tempAbbonement;
}


void Abbonement::deleteAbbo()
{
	OAbbonementDAO::verwijderAbbonement(myAbbonementID);
}

string Abbonement::toString(){
	stringstream ss;
	ss << "Abbonement ID: " << getAbbonementID() << endl;
	ss << "Klant ID: " << getAbbonementKlantID() << endl;
	ss << "Vak ID: " << getAbbonementVakID() << endl;
	//Rest uit database halen.
	return ss.str();
}

