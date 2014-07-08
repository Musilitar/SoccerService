#include "stdafx.h"
#include <string>

using namespace std;

#pragma once

class Menu{

public:
	//constructor
	Menu();

	//destructor
	~Menu(void);
	
	//functions
	void showMainMenu();
	void toonAlleMatchen();
	void getAllePloegen();
	void getAlleTegenstanders();
	void toonMogelijkeAbbonementen(bool,bool);
	Klant* registreerForm(Klant*);
	void showKlantMenu();
	void toonAlleVakken(int);
	void showAdminMenu(int);
	void showTicketAdminMenu();
	void showAbbonementAdminMenu();
	void showMatchenAdminMenu();
	void showBlacklistAdminMenu();
	void showAdminKlantMenu();
	void toonBans();
	void maakFactuurTicket(int,int, int, int); 
};