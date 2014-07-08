#include "stdafx.h"
#include "Zitje.h"

#pragma once
class OZitjeDAO
{
private:
	static int getPositie(int);
public:
	static vector<Zitje*> zitjes;
	static void initialisatie();
	static void maakLeeg();
	static vector<Zitje*> getAlles();
	static Zitje* bewaarZitje(Zitje*);
	static Zitje* getZitje(int);
	static bool verwijderZitje(int);
	static vector<Zitje*> vindZitjeDoorID(int);
	static int reserveerVolgendeVrijeZitje(int);
};

