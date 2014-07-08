#pragma once
#include <string>
#include "AbbonementTypes.h"

using namespace std;

class Abbonement
{
private: 
	int myAbbonementID; 
	int myAbbonementKlantID;
	int myAbbonementVakID;
	int myAbbonementTypeID;

public:
	Abbonement();
	Abbonement(int, int, int, int = -1);
	~Abbonement();

	int getAbbonementID();
	int getAbbonementKlantID();
	int getAbbonementVakID();
	int getAbbonementTypeID();

	void setAbbonementID(int); 
	void setAbbonementKlantID(int);
	void setAbbonementVakID(int);
	void setAbbonementTypeID(int);
	
	void deleteAbbo(); 
	static string maakAbbonement(int, int, int); 

	string toString();

};

