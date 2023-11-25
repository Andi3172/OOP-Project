#include "EventLocation.h"
#include <iostream>
int main() {
    // Example usage of EventLocation
    const int numRows = 5;
    const int seatsPerRow[numRows] = { 10, 15, 20, 15, 10 };

    EventLocation eventLocation("Example Location", 150, numRows, seatsPerRow);
    eventLocation.display();

    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}
