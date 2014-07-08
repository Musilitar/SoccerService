#include "stdafx.h"
#include "Ticket.h"
#include "OTicketDAO.h"

Ticket::Ticket(int ticketID){
	setTicketID(ticketID);
}

Ticket::Ticket(int stadionID, int klantID, int zitjeID, int keuze_vak, int keuze_match, int ticketID){
	setTicketID(ticketID);
	setStadionID(stadionID);
	setKlantID(klantID);
	setZitjeID(zitjeID);
	setVakID(keuze_vak);
	setMatchID(keuze_match);
}
Ticket::~Ticket(){}

string Ticket::toString(){
	stringstream ss;
	ss << endl;
	ss << "Ticket ID: " << getTicketID() << endl
		<< "StadionID: " << getStadionID() << endl
		<< "KlantID: " << getKlantID() << endl
		<< "ZitjeID: " << getZitjeID() << endl
		<< "Keuze vak: " << getVakID() << endl
		<< "Keuze match: " << getMatchID() << endl;
	ss << endl;

	return ss.str();

	/*stringstream ss;

	ss << "LOKEREN VS. STANDARD - 21 / 11 / 2013" << endl;
	ss << "------------------------------------------------" << endl;
	ss << "Klant 0000001 - Sam Junius" << endl;
	ss << "Vak: 001 \t Stoel: 53" << endl;
	ss << "35 euro" << endl;
	ss << endl;

	return ss.str();*/
}

int Ticket::getTicketID(){return myTicketID;}

void Ticket::setTicketID(int ticketID){myTicketID = ticketID;}

int Ticket::getStadionID(){return myStadionID;}

void Ticket::setStadionID(int stadionID){myStadionID = stadionID;}

int Ticket::getKlantID(){return myKlantID;}

void Ticket::setKlantID(int klantID){myKlantID = klantID;}

int Ticket::getZitjeID(){return myZitjeID;}

void Ticket::setZitjeID(int zitjeID){myZitjeID = zitjeID;}

int Ticket::getVakID(){return myVakID;}

void Ticket::setVakID(int keuze_vak){myVakID = keuze_vak;}

int Ticket::getMatchID(){return myMatchID;}

void Ticket::setMatchID(int keuze_match){myMatchID = keuze_match;}
void Ticket::deleteTicket()
{
	OTicketDAO::verwijderTicket(myTicketID);
}