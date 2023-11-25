#define _CRT_SECURE_NO_WARNINGS
#include "EventLocation.h"
#include <iostream>
#include <cstring>
using namespace std;

EventLocation::EventLocation(const char* name, int maxSeats, int numRows, const int* seatsPerRow)
	: maxSeats(maxSeats), numRows(numRows), seatsPerRow(nullptr)
{
	locationName = new char[MAX_NAME_LENGTH];
	strncpy(locationName, name, MAX_NAME_LENGTH - 1);
	locationName[MAX_NAME_LENGTH - 1] = '\0';

	this->seatsPerRow = new int[numRows];
	for (int i = 0; i < numRows; i++)
	{
		this->seatsPerRow[i] = seatsPerRow[i];
	}
}

EventLocation::EventLocation(const EventLocation& other)
	: maxSeats(other.maxSeats), numRows(other.numRows)
{
	locationName = new char[MAX_NAME_LENGTH];
	strncpy(locationName, other.locationName, MAX_NAME_LENGTH - 1);
	locationName[MAX_NAME_LENGTH - 1] = '\0';

	seatsPerRow = new int[numRows];
	for (int i = 0; i < numRows; i++)
	{
		seatsPerRow[i] = other.seatsPerRow[i];
	}
}

EventLocation::~EventLocation()
{
	delete[] locationName;
	delete[] seatsPerRow;
}

const char* EventLocation::getLocationName() const
{
	return locationName;
}

int EventLocation::getMaxSeats() const
{
	return maxSeats;
}

int EventLocation::getNumRows() const
{
	return numRows;
}

const int* EventLocation::getSeatsPerRow() const
{
	return seatsPerRow;
}

void EventLocation::setLocationName(const char* name)
{
	strncpy(locationName, name, MAX_NAME_LENGTH - 1);
	locationName[MAX_NAME_LENGTH - 1] = '\0';
}

void EventLocation::setMaxSeats(int seats)
{
	this->maxSeats = seats;
}

void EventLocation::setNumRows(int rows)
{
	this->numRows = rows;
}

void EventLocation::setSeatsPerRow(const int* newseatsPerRow)
{
	delete[] this-> seatsPerRow;
	this-> seatsPerRow = new int[EventLocation::numRows];
	for (int i = 0; i < numRows; i++)
	{
		this->seatsPerRow[i] = newseatsPerRow[i];
	}
}

void EventLocation::display() const
{
	cout << "Location: " << locationName << "\n";
	cout << "Max seats: " << maxSeats << "\n";
	cout << "Number of rows: " << numRows << "\n";
	cout << "Seats per row: ";
	for (int i = 0; i < numRows; i++)
		cout << seatsPerRow[i] << " ";
	cout << "\n";
}
