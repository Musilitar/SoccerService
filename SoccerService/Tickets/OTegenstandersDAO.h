#include "Tegenstanders.h"
#include <vector>
#pragma once
class OTegenstandersDAO
{
private:
	static vector<Tegenstanders*> tegenstandersen;
	static int getPositie(int);
public:
	static void initialisatie();
	static vector<Tegenstanders*> getAlles();
	static Tegenstanders* bewaarTegenstanders(Tegenstanders*);
	static Tegenstanders* getTegenstanders(int);
	static bool verwijderTegenstanders(int);
};

