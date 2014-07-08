#ifndef Databank_Offline

#pragma once
#include "stdafx.h"
#include "Zitje.h"


class ZitjeDAO
{
private:
	static Connection* con;
public:
	static vector<Zitje*> getAll();
	static Zitje* updateZitje(int,int,int,Zitje*);
	static Zitje* getZitje(int ID);
	static int getID(Zitje*);
	static bool removeZitje(int ID);
	static bool removeZitjesMatch(int);
	static Zitje* eersteVrijeStoel(int,int);

	static Zitje* findZitjeByID(int ID);

	static Zitje* maakZitje(Zitje*);
};

#endif