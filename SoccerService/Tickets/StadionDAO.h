
#ifndef Databank_Offline

#pragma once
#include "stdafx.h"
#include "Stadion.h"


class StadionDAO
{
private:
	static Connection* con;
public:
	static vector<Stadion*> getAll();
	static Stadion* saveStadion(Stadion*);
	static Stadion* getStadion(int ID);
	static int getID(Stadion*);
	static bool removeStadion(int ID);

	static vector<Stadion*> findStadionByID(int ID);
};

#endif