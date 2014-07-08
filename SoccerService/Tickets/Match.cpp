#include "stdafx.h"
#include "Match.h"

Match::Match()
{
	setMatchID(0);
	setMatchDatum("");
	setStadionID(0);
	setTegenstanderID(0);
}
Match::Match(int id)
{
	setMatchID(id);
	setMatchDatum("12/12/2012");
}
Match::Match(string datum,int stadion, int tegenstander, int id)
{
	setStadionID(stadion);
	setTegenstanderID(tegenstander);
	setMatchID(id);
	setMatchDatum(datum);
}

Match::~Match()
{

}

string Match::getMatchDatum()
{
	return myMatchDatum;
}

void Match::setMatchID(int id)
{
	myMatchID = id;
}

void Match::setMatchDatum(string datum)
{
	myMatchDatum = datum;
}
void Match::setTegenstanderID(int tegenstander)
{
	myTegenstanderID = tegenstander;
}
void Match::setStadionID(int stadion)
{
	myStadionID = stadion;
}

int Match::getMatchID()
{
	return myMatchID;
}
int Match::getStadionID()
{
	return myStadionID;
}
int Match::getTegenstanderID()
{
	return myTegenstanderID;
}
string Match::toString()
{

#ifndef Databank_Offline	
	Tegenstanders* tegenstander = TegenstandersDAO::getTegenstanders(getTegenstanderID());
	Stadion* stadion = StadionDAO::getStadion(getStadionID());

#else
	Tegenstanders* tegenstander = OTegenstandersDAO::getTegenstanders(getTegenstanderID());
	Stadion* stadion = OStadionDAO::getStadion(getStadionID());

#endif
	stringstream ss;
	ss << getMatchID() << ". " << getMatchDatum() <<": "  << stadion->getStadionName() << " - " << tegenstander->getTegenstanderNaam() << endl;
	return ss.str();
}