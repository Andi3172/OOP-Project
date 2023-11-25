#include "EventLocation.h"
#include "EventDetails.h"
#include <iostream>

int main() {
    // Example usage of EventLocation
    const int numRows = 5;
    const int seatsPerRow[numRows] = { 10, 15, 20, 15, 10 };

    EventLocation eventLocation("Example Location", 150, numRows, seatsPerRow);
    std::cout << "Event Location Details:\n";
    eventLocation.display();
    std::cout << "\n";

    // Example usage of EventDetails
    EventDetails eventDetails("Movie Night", "2023-12-01", "18:30");
    std::cout << "Event Details:\n";
    eventDetails.display();
    std::cout << "\n";

    // Modify Event Details
    eventDetails.setEventName("Concert");
    eventDetails.setEventDate("2023-12-15");
    eventDetails.setEventTime("20:00");
    std::cout << "Modified Event Details:\n";
    eventDetails.display();
    std::cout << "\n";

    return 0;
}
