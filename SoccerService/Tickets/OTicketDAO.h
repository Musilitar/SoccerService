#include "Ticket.h"
#include <vector>
#pragma once
class OTicketDAO
{
private:
public:
	static vector<Ticket*> tickets;
	static int getPositie(int);
	static void initialisatie();
	static void maakLeeg();
	static vector<Ticket*> getAlles();
	static Ticket* bewaarTicket(Ticket*);
	static Ticket* getTicket(int);
	static int getTicketID(int);
	static bool verwijderTicket(int);
	static vector<Ticket*> vindTicketDoorID(int);
};
