#include "stdafx.h"
#include "Zitje.h"


Zitje::Zitje(void){
	setZitjeID(0);
}
Zitje::Zitje(int id){
	setZitjeID(id);
}

Zitje::Zitje(int vakID, int matchID, int nummer,int klantID,int id)
{
	myZitjeNr = nummer;
	myZitjeID = id;
	myVakID = vakID;
	myKlantID = klantID;
	myMatchID = matchID;
}

/*Zitje::Zitje(Vak*vak, Match*match, Klant*klant,string nummer,int id)
{
	myZitjeNr = nummer;
	myZitjeID = id;
	myVak = vak;
	myKlant = klant;
	myMatch = match;
}*/

Zitje::Zitje(int nummer, int id)
{
	myZitjeNr = nummer;
	myZitjeID = id;
}
Zitje::~Zitje(void){}
int Zitje::getKlantID(){return myKlantID;}
int Zitje::getVakID(){return myVakID;}
int Zitje::getMatchID(){return myMatchID;}
int Zitje::getZitjeID(){return myZitjeID;}
int Zitje::getZitjeNr(){return myZitjeNr;}
void Zitje::setKlantID(int klant){myKlantID=klant;}
void Zitje::setMatchID(int match){myMatchID=match;}
void Zitje::setVakID(int vak){myVakID = vak;}
void Zitje::setZitjeNr(int nummer){myZitjeNr = nummer;}
void Zitje::setZitjeID(int id){myZitjeID = id;}
