#include "stdafx.h"
#include "Vak.h"

#pragma once
class OVakDAO
{
private:
	static int getPositie(int);
public:
	static vector<Vak*> vakken;
	static void initialisatie();
	static void maakLeeg();
	static vector<Vak*> getAlles();
	static Vak* bewaarVak(Vak*);
	static Vak* getVak(int);
	static int getVakID(int);
	static int getKost(int);
	static bool verwijderVak(int);
	static vector<Vak*> vindVakDoorID(int);
	static vector<int> vindVrijeVakken();
};
