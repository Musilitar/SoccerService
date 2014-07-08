
#ifndef Databank_Offline

#pragma once
#include "stdafx.h"
#include "Ticket.h"


class TicketDAO
{
private:
	static Connection* con;
public:
	static vector<Ticket*> getAll();
	static Ticket* saveTicket(Ticket*);
	static Ticket* getTicket(int ID);
	static int getID(Ticket*);
	static bool removeTicket(int ID);

	static vector<Ticket*> findTicketByID(int ID);
	static vector<Ticket*> findTicketByKlantID(int ID);
};

#endif