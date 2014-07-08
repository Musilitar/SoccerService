#include <string>

using namespace std;

#pragma once
class Stadion
{
private:
	int myStadionID;
	string myStadionName;
	string myStadionManager;
	string myStadionAddress;
	string myStadionTelefoon;
public:
	Stadion();
	Stadion(int);
	Stadion(string, string, string, string, int = -1);
	~Stadion(void);

	int getStadionID();
	string getStadionName();
	string getStadionManager();
	string getStadionAddress();
	string getStadionTelefoon();
	
	void setStadionID(int);
	void setStadionName(string);
	void setStadionManager(string);
	void setStadionAddress(string);
	void setStadionTelefoon(string);

	string toString();
};

