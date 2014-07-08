#include "Match.h"
#include <vector>
#pragma once
class OMatchDAO
{
private:
	static int getPositie(int);
public:
	static vector<Match*> matchen;
	static void initialisatie();
	static void maakLeeg();
	static vector<Match*> getAlles();
	static Match* bewaarMatch(Match*);
	static Match* getMatch(int);
	static bool verwijderMatch(int);
	static vector<Match*> vindMatchDoorID(int);
};

