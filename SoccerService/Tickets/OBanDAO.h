#include "Ban.h"
#include <vector>
#pragma once
class OBanDAO
{
private:
	static int getPositie(int);
public:
	static vector<Ban*> bannen;
	static void initialisatie();
	static vector<Ban*> getAlles();
	static Ban* bewaarBan(Ban*);
	static Ban* getBan(int);
	static bool verwijderBan(int);
	static vector<Ban*> vindBanDoorKlantID(int);
};

