#include "Rental.h"
#include <iostream>

Rental::Rental(Vehicle* v, Client* c, int d) : rentedVehicle(v), renter(c), days(d) {}

void Rental::displayReport() const {
    std::cout << "\n--- Rental Agreement ---" << std::endl;
    if (renter) {
        renter->displayInfo();
        std::cout << " (Discount: " << renter->getDiscount() * 100 << "%)" << std::endl;
    }
    std::cout << "Vehicle: ";
    if (rentedVehicle) rentedVehicle->displayInfo();
    std::cout << "\nDuration: " << days << " days" << std::endl;
    std::cout << "----------------------" << std::endl;
}
