
#ifndef Databank_Offline

#pragma once
#include "stdafx.h"
#include "AbbonementTypes.h"


class AbbonementTypesDAO
{
private:
	static Connection* con;
public:
	static vector<AbbonementTypes*> getAll();
	static AbbonementTypes* maakAbbonementTypes(AbbonementTypes*);
	static AbbonementTypes* getAbbonementTypes(int ID);
	static int getID(AbbonementTypes*);
	static bool removeAbbonementTypes(int ID);

	static vector<AbbonementTypes*> findAbbonementTypesByID(int ID);
};

#endif