#ifndef Databank_Offline

#pragma once
#include "stdafx.h"
#include "Klant.h"


class KlantDAO
{
private:
	static Connection* con;
public:
	static vector<Klant*> getAll();
	static Klant* saveKlant(Klant*);
	static Klant* getKlant(int ID);
	static int getID(Klant*);
	static bool removeKlant(int ID);
	static int findKlantByGnaam(string);
	static Klant* findKlantByID(int ID);
	static Klant* findKlantByName(string, string);
	static Klant* findKlantByRijksregisternr(string);
};

#endif