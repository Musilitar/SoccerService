#include "AbbonementTypes.h"
#include <vector>
#pragma once
class OAbbonementTypesDAO
{
private:
	static int getPositie(int);
public:
	static vector<AbbonementTypes*> AbbonementTypesVector;
	static void initialisatie();
	static vector<AbbonementTypes*> getAlles();
	static AbbonementTypes* bewaarAbbonementType(AbbonementTypes*);
	static AbbonementTypes* getAbbonementType(int);
	static bool verwijderAbbonementType(int);
};

