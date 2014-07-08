#pragma once

#include "stdafx.h"

#ifndef TICKET_H
#define TICKET_H
class Ticket
{
private: 
	int myTicketID;
	int myStadionID;
	int myKlantID;
	int myZitjeID;
	int myVakID;
	int myMatchID;

public:

	Ticket(int = -1);
	Ticket(int, int, int, int, int, int = -1);
	~Ticket();

	int getTicketID();
	int getStadionID();
	int getKlantID();
	int getZitjeID();
	int getVakID();
	int getMatchID();

	void setTicketID(int);
	void setStadionID(int);
	void setKlantID(int);
	void setZitjeID(int);
	void setVakID(int);
	void setMatchID(int);
	void deleteTicket();

	//void koopTicket(int);
	string toString();
};

#endif