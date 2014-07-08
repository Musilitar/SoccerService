
#ifndef Databank_Offline

#pragma once
#include "stdafx.h"
#include "Ban.h"


class BanDAO
{
private:
	static Connection* con;
public:
	static vector<Ban*> getAll();
	static Ban* maakBan(Ban*);
	static Ban* getBan(int ID);
	static int getID(Ban*);
	static bool removeBan(int ID);

	static vector<Ban*> findBanByKlantID(int ID);
};

#endif