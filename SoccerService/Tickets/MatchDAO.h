#ifndef Databank_Offline

#pragma once
#include "stdafx.h"
#include "Match.h"


class MatchDAO
{
private:
	static Connection* con;
public:
	static vector<Match*> getAll();
	static Match* saveMatch(Match*);
	static Match* getMatch(int ID);
	static int getID(Match*);
	static bool removeMatch(int ID);

	static vector<Match*> findMatchByID(int ID);
};

#endif