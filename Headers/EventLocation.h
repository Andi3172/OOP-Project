#pragma once
#ifndef EVENTLOCATION_H
#define EVENTLOCATION_H

#include<iostream>
#include<string>

using namespace std;

class EventLocation {

private:
	const int MAX_ROWS = 10;
	const int MAX_SEATS_ON_ROW = 20;
	static int totalLocations;

	char* locationName;
	int* seatsOnRow;

public:
	EventLocation();
	EventLocation(const char* name, const int* seats);
	~EventLocation();
	EventLocation(const EventLocation& other);
	EventLocation& operator=(const EventLocation& other);

	//access methods
	const char* getLocationName() const;
	const int* getSeatsOnRow() const;
	static int getTotalLocations();

	//mutator methods
	void displayLocation() const;

};

//overload
ostream& operator<<(ostream& os, const EventLocation& location);
istream& operator>>(istream& is, EventLocation& location);

#endif // !EVENTLOCATION_H