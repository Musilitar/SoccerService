 #include "stdafx.h"
#include "OTicketDAO.h"
#include <iostream>

vector<Ticket*> OTicketDAO::tickets = vector<Ticket*>();

void OTicketDAO::initialisatie()
{
	tickets.push_back(new Ticket(1, 2, 2, 2, 1, 1));
	tickets.push_back(new Ticket(1, 3, 3, 2, 1, 2));
	tickets.push_back(new Ticket(1, 2, 4, 3, 2, 3));
	tickets.push_back(new Ticket(1, 1, 1, 1, 2, 4));
}

//int stadionID, int klantID, int zitjeID, int keuze_vak, int keuze_match, int ticketID

void OTicketDAO::maakLeeg()
{
	for(int i =0; i < tickets.size(); i++)
	{
		if(tickets.at(i)!=NULL)
			delete tickets.at(i);
	}
}

bool OTicketDAO::verwijderTicket(int id)
{
	Ticket* temp = getTicket(id);
	if(temp == 0)
	{
		return false;
	}
	tickets.erase(tickets.begin()+getPositie(id));
	delete temp;
	return true;
}

vector<Ticket*> OTicketDAO::getAlles()
{
	return tickets;
}

Ticket* OTicketDAO::getTicket(int id)
{
	for(int i =0; i < tickets.size(); i++)
	{
		Ticket* temp = tickets.at(i);
		if(temp->getTicketID() == id)
			return temp;
	}
	return 0;
}

int OTicketDAO::getTicketID(int id)
{
	for(int i =0; i < tickets.size(); i++)
	{
		Ticket* temp = tickets.at(i);
		if(temp->getTicketID() == id)
			return id;
	}
	return 0;
}

//Geeft de positie van een element in de array; Enkel noodzakelijk om de database te simuleren
int OTicketDAO::getPositie(int id)
{
	for(int i = 0; i < tickets.size(); i++)
	{
		Ticket* temp = tickets.at(i);
		if(temp->getTicketID() == id)
			return i;
	}
	return -1;
}

Ticket* OTicketDAO::bewaarTicket(Ticket* ticket)
{
	if(ticket->getTicketID() == -1)
	{
		//Dit is een nieuw adres en simuleert de toekenning van een sequentiële ID door de database
		Ticket* temp = tickets.at(tickets.size()-1);
		int nieuweID = temp->getTicketID()+1;
		ticket->setTicketID(nieuweID);
	}
	Ticket* temp = getTicket(ticket->getTicketID());
	if(temp == 0)
	{
		tickets.push_back(ticket);
		return ticket;
	}
	else
	{
		//Ticket updaten
		temp->setTicketID(ticket->getTicketID());
		return temp;
	}

	return 0;
}

vector<Ticket*> OTicketDAO::vindTicketDoorID(int ID)
{
	vector<Ticket*> results = vector<Ticket*>();
	for(int i =0; i < tickets.size(); i++)
	{
		Ticket* temp = tickets.at(i);
		if(temp->getTicketID() == ID)
			results.push_back(temp);
	}
	return results;
}