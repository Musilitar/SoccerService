#include "stdafx.h"
#include "AbbonementTypes.h"
#include <iostream>
#include <string>
#include <sstream>

AbbonementTypes::AbbonementTypes(string,string, int)
{
	setAbbonementTypeID(0); 
	setAbbonementTypeDatumVanaf(""); 
	setAbbonementTypeDatumTot("");
}
AbbonementTypes::~AbbonementTypes(void)
{
}
int AbbonementTypes::getAbbonementTypeID()
{
	return myAbbonementTypeID; 
}
string AbbonementTypes::getAbbonementTypeDatumVanaf()
{
	return myAbbonementTypeDatumVanaf;
}
string AbbonementTypes::getAbbonementTypeDatumTot()
{
	return myAbbonementTypeDatumTot;
}

void AbbonementTypes::setAbbonementTypeID(int abbonementTypID)
{
	myAbbonementTypeID = abbonementTypID; 
}
void AbbonementTypes::setAbbonementTypeDatumVanaf(string abbonementTypeDatumVanaf)
{
	myAbbonementTypeDatumVanaf = abbonementTypeDatumVanaf;
}
void AbbonementTypes::setAbbonementTypeDatumTot(string abbonementTypeDatumTot)
{
	myAbbonementTypeDatumTot = abbonementTypeDatumTot; 
}

//*string AbbonementTypes::toString(){}