#pragma once

#ifndef Databank_Online

#include "Klant.h"
#include <vector>

class OKlantDAO
{
private:
	static int getPositie(int);
public:
	static vector<Klant*> klanten;
	static void initialisatie();
	static void maakLeeg();
	static vector<Klant*> getAlles();
	static Klant* bewaarKlant(Klant*);
	static Klant* getKlant(int);
	static string getKlantGnaam(string);
	static string getKlantWachtwoord(string);
	static bool verwijderKlant(int);
	static vector<Klant*> vindKlantDoorID(int);
	static int vindKlantDoorGnaam(string);
	static Klant* vindKlantDoorNaam(string, string);
	static int getKlantViaRijksregisterNr(string);
};

#endif
