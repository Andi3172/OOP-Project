#include "Ticket.h"
#include "EventLocation.h"
#include "EventDetails.h"
#include <iostream>
#include <cstring>

int Ticket::ticketCount = 0;

Ticket::Ticket(TicketType type, const EventLocation& location, const EventDetails& details)
	: ticketID(generateRandomID()), ticketType(type), eventLocation(&location), eventDetails(&details)
{

	if (ticketCount > location.getMaxSeats())
	{
		std::cout << "Error: Ticket count exceeds maximum seats for this event location.\n";
		ticketType = TicketType::Invalid;
	}
	else
	{
		ticketCount++;
	}

}

int Ticket::generateRandomID()
{
	//generate random id to be a sequence of 6 digits, numbers and letters. each digit has a 1/36 chance of being a letter
	srand(static_cast<unsigned int>(time(nullptr)));
	int id = 0;
	for (int i = 0; i < 6; i++)
	{
		int random = rand() % 36;
		if (random < 10)
		{
			id += random * static_cast<int>(pow(10, i));
		}
		else
		{
			id += (random + 55) * static_cast<int>(pow(10, i));
		}
	}
	return id;

}

int Ticket::getTicketID() const
{
	return ticketID;
}

Ticket::TicketType Ticket::getTicketType() const
{
	return ticketType;
}

const char* Ticket::getTicketTypeString() const
{
	return getTicketTypeString(ticketType);
}
const char* Ticket::getTicketTypeString(TicketType type) const
{
	switch (type)
	{
	case TicketType::DayPass:
		return "Day Pass";
	case TicketType::VIP:
		return "VIP";
	case TicketType::UltraVIP:
		return "Ultra VIP";
	default:
		return "Invalid";
	}
}

const char* Ticket::getTicketTypeString(int typeIndex) const
{
	if (typeIndex >= 0 && typeIndex < 3)
	{
		return getTicketTypeString(static_cast<TicketType>(typeIndex));
	}
	else
	{
		return "Invalid";
	}
}
const char* Ticket::getTicketTypeString(const char* typeString) const
{
	if (strcmp(typeString, "DayPass") == 0) {
		return "DayPass";
	}
	else if (strcmp(typeString, "VIP") == 0) {
		return "VIP";
	}
	else if (strcmp(typeString, "UltraVIP") == 0) {
		return "UltraVIP";
	}
	else {
		return "Invalid";
	}
}

void Ticket::display() const
{
	std::cout << "Ticket ID: " << ticketID << std::endl;
	std::cout << "Ticket Type: " << getTicketTypeString() << std::endl;
	std::cout << "Event Location: " << eventLocation->getLocationName() << std::endl;
	std::cout << "Event Date: " << eventDetails->getEventDate() << std::endl;
	std::cout << "Event Time: " << eventDetails->getEventTime() << std::endl;
}

int Ticket::getTicketCount()
{
	return ticketCount;
}

Ticket& Ticket::operator=(const Ticket& other)
{
	if (this != &other)
	{
		ticketID = other.ticketID;
		ticketType = other.ticketType;
		eventLocation = other.eventLocation;
		eventDetails = other.eventDetails;
	}
	return *this;
}

Ticket::~Ticket()
{
	////std::cout << "Ticket " << ticketID << " destroyed.\n";
}

