#ifndef EVENTDETAILS_H
#define EVENTDETAILS_H

#include <iostream>
#include <cstring>

class EventDetails
{
private:
	char* eventName;
	char* eventDate;
	char* eventTime;

public:
	static const int MAX_NAME_LENGTH = 50;
	static const int MAX_DATE_LENGTH = 20;
	static const int MAX_TIME_LENGTH = 20;

	EventDetails(const char* name, const char* date, const char* time);
	EventDetails(const EventDetails& other);
	~EventDetails();

	//Interface for reading the data
	const char* getEventName() const;
	const char* getEventDate() const;
	const char* getEventTime() const;

	//Interface for changing the data
	void setEventName(const char* name);
	void setEventDate(const char* date);
	void setEventTime(const char* time);

	//Interface for printing the data
	void display() const;

};


#endif // !EVENTDETAILS_H