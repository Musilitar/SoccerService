#include "Stadion.h"
#include <vector>
#pragma once
class OStadionDAO
{
private:
	static vector<Stadion*> stadions;
	static int getPositie(int);
public:
	static void initialisatie();
	static vector<Stadion*> getAlles();
	static Stadion* bewaarStadion(Stadion*);
	static Stadion* getStadion(int);
	static bool verwijderStadion(int);
};

