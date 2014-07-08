#include "stdafx.h"
#include "Vak.h"


Vak::Vak(void){
	setVakID(0);
	setVakKost(0);
}
Vak::Vak(int id){setVakID(id);}
Vak::Vak(string naam, double kost, bool soort, int capaciteit, bool thuisSupporter, int bezettePlaatsen, int ID){
	setSoort(soort);
	setThuisSupporter(thuisSupporter);
	setVakID(ID);
	setBezettePlaatsen(bezettePlaatsen);
	setCapaciteit(capaciteit);
	setVakKost(kost);
	setNaam(naam);
}

Vak::Vak(string naam, double kost, bool soort, int capaciteit, bool thuisSupporter, int ID){
	setSoort(soort);
	setThuisSupporter(thuisSupporter);
	setVakID(ID);
	setCapaciteit(capaciteit);
	setVakKost(kost);
	setNaam(naam);
	setBezettePlaatsen(0);
}

Vak::Vak(string naam, float kost, int id)
{
	myVakKost=kost;
	myNaam = naam;
	myVakID = id;
}
Vak::~Vak(void){}

bool Vak::getSoort(){return mySoort;}
bool Vak::getSupporter(){return myThuisSupporter;}
int Vak::getVakID(){return myVakID;}
int Vak::getBezettePlaatsen(){return myBezettePlaatsen;}
int Vak::getCapaciteit(){return myCapaciteit;}
float Vak::getVakKost(){return myVakKost;}
string Vak::getNaam(){return myNaam;}

void Vak::setSoort(bool soort){mySoort = soort;};
void Vak::setThuisSupporter(bool thuisSupporter){myThuisSupporter = thuisSupporter;};
void Vak::setNaam(string naam){myNaam = naam;}
void Vak::setVakID(int id){myVakID = id;}
void Vak::setVakKost(float kost){myVakKost = kost;}
void Vak::setBezettePlaatsen(int plaatsen){myBezettePlaatsen = plaatsen;}
void Vak::setCapaciteit(int capaciteit){myCapaciteit = capaciteit;}

string Vak::toString(){
	stringstream ss;
	ss << "Vaknummer: " << getVakID() << endl;
	ss << "Prijs: " << getVakKost() << endl;
	ss << "Aantal bezette plaatsen: " << getBezettePlaatsen() << endl;
	ss << "Capaciteit: " << getCapaciteit() << endl;
	ss << "Type: " << getSoort() << endl;
	return ss.str();
}
