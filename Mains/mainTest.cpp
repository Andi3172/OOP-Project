#include "EventLocation.h"
#include "EventDetails.h"
#include <iostream>

/*int main() {
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
}*/

#include "EventLocation.h"
#include "EventDetails.h"
#include "Ticket.h"
#include <iostream>

int main() {
    // Create an EventLocation
    const char* locationName = "Arenele Romane";
    int maxSeats = 100;
    int numRows = 10;
    const int seatsPerRow[] = { 10, 12, 15, 15, 12, 10, 8, 8, 12, 10 };

    EventLocation exampleLocation(locationName, maxSeats, numRows, seatsPerRow);

    // Create an EventDetails
    const char* eventName = "Concert";
    const char* eventDate = "2023-12-01";
    const char* eventTime = "18:00";

    EventDetails exampleDetails(eventName, eventDate, eventTime);

    // Generate a Ticket
    Ticket::TicketType ticketType = Ticket::TicketType::VIP;

    Ticket exampleTicket(ticketType, exampleLocation, exampleDetails);

    // Display Ticket information
    std::cout << "Generated Ticket Information:\n";
    exampleTicket.display();

    return 0;
}

