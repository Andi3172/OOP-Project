#define _CRT_SECURE_NO_WARNINGS
#include "EventDetails.h"
#include <iostream>
#include <cstring>

EventDetails::EventDetails(const char* name, const char* date, const char* time)
	:eventName(new char[MAX_NAME_LENGTH]), eventDate(new char[MAX_DATE_LENGTH]), eventTime(new char[MAX_TIME_LENGTH])
{
	strncpy(eventName, name, MAX_NAME_LENGTH -1);
	eventName[MAX_NAME_LENGTH - 1] = '\0';

	strncpy(eventDate, date, MAX_DATE_LENGTH - 1);
	eventDate[MAX_DATE_LENGTH - 1] = '\0';

	strncpy(eventTime, time, MAX_TIME_LENGTH - 1);
	eventTime[MAX_TIME_LENGTH - 1] = '\0';
}

EventDetails::EventDetails(const EventDetails& other)
	:eventName(new char[MAX_NAME_LENGTH]), eventDate(new char[MAX_DATE_LENGTH]), eventTime(new char[MAX_TIME_LENGTH])
{
	strncpy(eventName, other.eventName, MAX_NAME_LENGTH - 1);
	eventName[MAX_NAME_LENGTH - 1] = '\0';

	strncpy(eventDate, other.eventDate, MAX_DATE_LENGTH - 1);
	eventDate[MAX_DATE_LENGTH - 1] = '\0';

	strncpy(eventTime, other.eventTime, MAX_TIME_LENGTH - 1);
	eventTime[MAX_TIME_LENGTH - 1] = '\0';
}

EventDetails::~EventDetails()
{
	delete[] eventName;
	delete[] eventDate;
	delete[] eventTime;
}

const char* EventDetails::getEventName() const
{
	return eventName;
}
const char* EventDetails::getEventDate() const
{
	return eventDate;
}
const char* EventDetails::getEventTime() const
{
	return eventTime;
}

void EventDetails::setEventName(const char* name)
{
	strncpy(eventName, name, MAX_NAME_LENGTH - 1);
	eventName[MAX_NAME_LENGTH - 1] = '\0';
}

void EventDetails::setEventDate(const char* date)
{
	strncpy(eventDate, date, MAX_DATE_LENGTH - 1);
	eventDate[MAX_DATE_LENGTH - 1] = '\0';
}

void EventDetails::setEventTime(const char* time)
{
	strncpy(eventTime, time, MAX_TIME_LENGTH - 1);
	eventTime[MAX_TIME_LENGTH - 1] = '\0';
}

void EventDetails::display() const
{
	std::cout << "Event Name: " << eventName << std::endl;
	std::cout << "Event Date: " << eventDate << std::endl;
	std::cout << "Event Time: " << eventTime << std::endl;
}
