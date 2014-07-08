#include "stdafx.h"

#pragma once
class Vak
{
private:
	bool myTegenstander, mySoort, myThuisSupporter;
	int myVakID, myBezettePlaatsen, myCapaciteit;
	float myVakKost;
	string myNaam;
public:
	Vak(void);
	Vak(int);
	Vak(string, double, bool, int, bool, int, int);
	Vak(string, double, bool, int, bool, int);
	Vak(string,float,int = -1);
	~Vak(void);

	bool getSoort();
	bool getSupporter();
	int getVakID();
	int getBezettePlaatsen();
	int getCapaciteit();
	string getNaam();
	float getVakKost();
	void setSoort(bool);
	void setThuisSupporter(bool);
	void setVakID(int);
	void setNaam(string);
	void setBezettePlaatsen(int);
	void setCapaciteit(int);
	void setVakKost(float);

	string toString();
};

