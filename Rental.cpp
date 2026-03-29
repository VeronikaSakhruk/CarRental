#include "Rental.h"
#include <iostream>
#include <fstream>

Rental::Rental(std::shared_ptr<Vehicle> v, std::shared_ptr<Client> c, int days, double cost)
    : vehicle(v), client(c), days(days), totalCost(cost), active(true) {}

void Rental::display() const {
    std::cout << client->getName() << " -> " << vehicle->getBrand()
              << " (" << vehicle->getPlate() << ")"
              << " | " << days << " days | " << totalCost << " UAH"
              << " | " << (active ? "Active" : "Returned") << std::endl;
}

void Rental::logToFile() const {
    std::ofstream out("history.txt", std::ios::app);
    if (out) {
        out << client->getName() << " rented " << vehicle->getBrand()
            << " (" << vehicle->getPlate() << ")"
            << " for " << days << " days, cost: " << totalCost << " UAH" << std::endl;
    }
}
