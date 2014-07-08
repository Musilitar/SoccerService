#include "stdafx.h"
#include "Tegenstanders.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Tegenstanders::Tegenstanders()
{
	setTegenstanderID(0); 
    setTegenstanderNaam(""); 
}
Tegenstanders::Tegenstanders(string tegenstander, int id)
{
	setTegenstanderID(id); 
    setTegenstanderNaam(tegenstander); 
}

Tegenstanders::~Tegenstanders(void)
{
}
int Tegenstanders::getTegenstanderID()
{
	return myTegenstanderID;
}
string Tegenstanders::getTegenstanderNaam()
{
	return myTegenstanderNaam;
}


void Tegenstanders::setTegenstanderID(int tegenstanderID)
{
	myTegenstanderID = tegenstanderID;
}
void Tegenstanders::setTegenstanderNaam(string tegenstanderNaam)
{
	myTegenstanderNaam = tegenstanderNaam; 
}

string Tegenstanders::toString(){
	stringstream ss;
	ss << "Tegenstander ID: " << getTegenstanderID() << endl;
	ss << "Tegenstander naam: " << getTegenstanderNaam() << endl;
	//Rest uit database halen.
	return ss.str();
}

