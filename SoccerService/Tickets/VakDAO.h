#ifndef Databank_Offline

#pragma once
#include "stdafx.h"
#include "Vak.h"


class VakDAO
{
private:
	static Connection* con;
public:
	static vector<Vak*> getAll();
	static Vak* saveVak(Vak*);
	static Vak* getVak(int ID);
	static int getID(Vak*);
	static bool removeVak(int ID);

	static vector<Vak*> findVakByID(int ID);
};

#endif