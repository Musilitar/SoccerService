#pragma once
#include <string>

using namespace std;

class Tegenstanders
{
private: 
	int myTegenstanderID; 
	string myTegenstanderNaam; 

public:
	Tegenstanders();
	Tegenstanders(string, int = -1);
	~Tegenstanders();

	int getTegenstanderID();
	string getTegenstanderNaam();

	void setTegenstanderID(int); 
	void setTegenstanderNaam(string); 

	string toString();

};

