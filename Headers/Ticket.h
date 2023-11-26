#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <cstring>
#include "EventLocation.h"
#include "EventDetails.h"

#include <ctime>
#include <cstdlib> //for random number generation, thought it would be fun to try it out

class Ticket
{
public:
	// add an enum for ticket types: DayPass, VIP, UltraVIP, etc.
enum class TicketType { DayPass, VIP, UltraVIP, Invalid};

private:
	static int ticketCount;
	int ticketID;
	TicketType ticketType;

	const EventLocation* eventLocation;
	const EventDetails* eventDetails;

	//!!!
	static int generateRandomID();

public:
	Ticket(TicketType type, const EventLocation& location, const EventDetails& details);
	Ticket(const Ticket& other);
	~Ticket();

	
	int getTicketID() const;

	TicketType getTicketType() const;
	const char* getTicketTypeString() const;
	const char* getTicketTypeString(TicketType type) const;
	const char* getTicketTypeString(int typeIndex) const;
	const char* getTicketTypeString(const char* typeString) const;

	const EventLocation* getEventLocation() const;
	const EventDetails* getEventDetails() const;

	void setTicketType(TicketType type);
	static int getTicketCount();

	void display() const;

	Ticket& operator=(const Ticket& other);

};

#endif // !TICKET_H

