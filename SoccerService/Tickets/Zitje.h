#pragma once
#include "Klant.h"
#include "Match.h"
#include "Vak.h"
class Zitje
{
private:
	int myZitjeID;
	int myZitjeNr;
	int myKlantID;
	int myVakID;
	int myMatchID;
public:
	Zitje(void);
	Zitje(int);
	Zitje(int,int);
	Zitje(int, int, int,int = NULL,int = -1);
	//Zitje(Vak*,Match*,Klant*,string,int = -1);

	~Zitje(void);

	int getKlantID();
	int getVakID();
	int getMatchID();
	int getZitjeID();
	int getZitjeNr();

	void setKlantID(int);
	void setVakID(int);
	void setMatchID(int);
	void setZitjeNr(int);
	void setZitjeID(int);

};