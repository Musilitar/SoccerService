
#ifndef Databank_Offline

#pragma once
#include "stdafx.h"
#include "Abbonement.h"


class AbbonementDAO
{
private:
	static Connection* con;
public:
	static vector<Abbonement*> getAll();
	static Abbonement* maakAbbonement(Abbonement*);
	static Abbonement* getAbbonement(int ID);
	static int getID(Abbonement*);
	static bool removeAbbonement(int ID);
	static Abbonement* findAbbonementByKlantID(int);
};

#endif