#pragma once
#include <string>

using namespace std;

class Ban
{
private: 
	int myBanID; 
	string myBanVanaf; 
	string myBanTot;
	int myBanKlantID;


public:
	Ban();
	Ban(string,string, int, int = -1);
	~Ban();

	int getBanID();
	string getBanVanaf();
	string getBanTot(); 
	int getBanKlantID();

	void setBanID(int); 
	void setBanVanaf(string); 
	void setBanTot(string);
	void setBanKlantID(int);
	

	string toString();

};

