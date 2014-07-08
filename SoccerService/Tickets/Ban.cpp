#include "stdafx.h"
#include "Ban.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Ban::Ban()
{
	setBanID(0); 
    setBanVanaf(""); 
	setBanTot("");
	setBanKlantID(0);

}
Ban::Ban(string vanaf, string tot, int klant, int id)
{
	setBanID(id); 
    setBanVanaf(vanaf); 
	setBanTot(tot);
	setBanKlantID(klant);
}

Ban::~Ban(void)
{
}
int Ban::getBanID()
{
	return myBanID;
}
string Ban::getBanVanaf()
{
	return myBanVanaf;
}
string Ban::getBanTot()
{
	return myBanTot;
}
int Ban::getBanKlantID()
{
	return myBanKlantID;
}

void Ban::setBanID(int banID)
{
	myBanID = banID;
}
void Ban::setBanVanaf(string banVanaf)
{
	myBanVanaf = banVanaf; 
}
void Ban::setBanTot(string banTot)
{
	myBanTot = banTot;
}
void Ban::setBanKlantID(int banKlantID)
{
	myBanKlantID = banKlantID;
}


string Ban::toString(){
	stringstream ss;
	ss << "Ban ID: " << getBanID() << endl;
	ss << "Begindatum ban: " << getBanVanaf() << endl;
	ss << "Einddatum ban: " << getBanTot() << endl;
	ss << "Klant ID: " << getBanKlantID() << endl;
	//Rest uit database halen.
	return ss.str();
}

