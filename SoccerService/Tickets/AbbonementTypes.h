#pragma once
#include <string>

using namespace std;

class AbbonementTypes
{
private: 
	int myAbbonementTypeID; 
	string myAbbonementTypeDatumVanaf; 
	string myAbbonementTypeDatumTot; 

public:
	AbbonementTypes(string,string, int = -1);
	~AbbonementTypes(void);

	int getAbbonementTypeID(); 
	string getAbbonementTypeDatumVanaf(); 
	string getAbbonementTypeDatumTot(); 

	void setAbbonementTypeID(int); 
	void setAbbonementTypeDatumVanaf(string); 
	void setAbbonementTypeDatumTot(string); 

	string toString(); 
};

