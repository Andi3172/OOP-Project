#pragma once
#ifndef EVENTLOCATION_H
#define EVENTLOCATION_H

#include<iostream>
#include<cstring>

class EventLocation {

private:
    char* locationName;
    int maxSeats;
    int numRows;
    int* seatsPerRow;

public:
    static const int MAX_NAME_LENGTH = 50;

    EventLocation(const char* name, int maxSeats, int numRows, const int* seatsPerRow);
    EventLocation(const EventLocation& other);
    ~EventLocation();

    // Public interface for reading values
    const char* getLocationName() const;
    int getMaxSeats() const;
    int getNumRows() const;
    const int* getSeatsPerRow() const;

    // Public interface for writing values
    void setLocationName(const char* name);
    void setMaxSeats(int seats);
    void setNumRows(int rows);
    void setSeatsPerRow(const int* seatsPerRow);

    // Display method
    void display() const;
};

#endif // !EVENTLOCATION_H