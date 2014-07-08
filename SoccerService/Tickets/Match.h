#include "stdafx.h"

using namespace std;

#pragma once

class Match
{

private:
	int myMatchID;
	string myMatchDatum;
	int myTegenstanderID;
	int myStadionID;

public:
	
	void setMatchID(int);
	void setMatchDatum(string);
	void setStadionID(int);
	void setTegenstanderID(int);
	int getMatchID();
	string getMatchDatum();
	int getStadionID();
	int getTegenstanderID();
	
	Match();
	Match(int);
	Match(string, int,int, int = -1);
	~Match();
	string toString();
	void toonAlleMatchen();
};