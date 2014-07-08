
#ifndef Databank_Offline

#pragma once
#include "stdafx.h"
#include "Tegenstanders.h"


class TegenstandersDAO
{
private:
	static Connection* con;
public:
	static vector<Tegenstanders*> getAll();
	static Tegenstanders* maakTegenstanders(Tegenstanders*);
	static Tegenstanders* getTegenstanders(int ID);
	static int getID(Tegenstanders*);
	static bool removeTegenstanders(int ID);

	static Tegenstanders* findTegenstandersByID(int ID);
};

#endif