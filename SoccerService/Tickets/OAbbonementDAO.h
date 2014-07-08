#include "Abbonement.h"
#include <vector>
#pragma once
class OAbbonementDAO
{
private:
	static vector<Abbonement*> abbonementen;
	static int getPositie(int);
public:
	static void initialisatie();
	static vector<Abbonement*> getAlles();
	static Abbonement* bewaarAbbonement(Abbonement*);
	static Abbonement* getAbbonement(int);
	static string getAbbonementWithKlantID(int id);
	static bool verwijderAbbonement(int);
};

