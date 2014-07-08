#include "stdafx.h"
#include "OAbbonementTypesDAO.h"
#include <iostream>


vector<AbbonementTypes*> OAbbonementTypesDAO::AbbonementTypesVector = vector<AbbonementTypes*>();

//Objecten in database steken

void OAbbonementTypesDAO::initialisatie()
{
	AbbonementTypesVector.push_back(new AbbonementTypes("01/09/13", "01/11/13", 1));
}

bool OAbbonementTypesDAO::verwijderAbbonementType(int id)
{
	AbbonementTypes* temp = getAbbonementType(id);
	if(temp == 0)
	{
		return false;
	}
	AbbonementTypesVector.erase(AbbonementTypesVector.begin()+getPositie(id));
	delete temp;
	return true;
}

vector<AbbonementTypes*> OAbbonementTypesDAO::getAlles()
{
	return AbbonementTypesVector;
}

AbbonementTypes* OAbbonementTypesDAO::getAbbonementType(int id)
{
	for(int i =0; i < AbbonementTypesVector.size(); i++)
	{
		AbbonementTypes* temp = AbbonementTypesVector.at(i);
		if(temp->getAbbonementTypeID() == id)
			return temp;
	}
	return 0;
}

//Geeft de positie van een element in de array; Enkel noodzakelijk om de database te simuleren
int OAbbonementTypesDAO::getPositie(int id)
{
	for(int i = 0; i < AbbonementTypesVector.size(); i++)
	{
		AbbonementTypes* temp = AbbonementTypesVector.at(i);
		if(temp->getAbbonementTypeID() == id)
			return i;
	}
	return -1;
}

AbbonementTypes* OAbbonementTypesDAO::bewaarAbbonementType(AbbonementTypes* NewAbbonementType)
{
	if(NewAbbonementType->getAbbonementTypeID() == -1)
	{
		//Dit is een nieuw adres en simuleert de toekenning van een sequentiële ID door de database
		AbbonementTypes* temp = AbbonementTypesVector.at(AbbonementTypesVector.size()-1);
		int nieuweID = temp->getAbbonementTypeID()+1;
		NewAbbonementType->setAbbonementTypeID(nieuweID);
	}
	AbbonementTypes* temp = getAbbonementType(NewAbbonementType->getAbbonementTypeID());
	if(temp == 0)
	{
		AbbonementTypesVector.push_back(NewAbbonementType);
		return NewAbbonementType;
	}
	else
	{
		//AbboType updaten
		temp->setAbbonementTypeID(NewAbbonementType->getAbbonementTypeID());
		temp->setAbbonementTypeDatumVanaf(NewAbbonementType->getAbbonementTypeDatumVanaf());
		temp->setAbbonementTypeDatumTot(NewAbbonementType->getAbbonementTypeDatumTot());
		return temp;
	}
}