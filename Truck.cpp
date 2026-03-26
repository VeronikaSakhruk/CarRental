#include "Truck.h"
#include <iostream>

Truck::Truck(std::string b, int hp, std::string t, double capacity)
    : Vehicle(b, hp, t), loadCapacity(capacity) {
}

void Truck::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << " | Truck Capacity: " << loadCapacity << " tons";
}

double Truck::calculateRental(int days) const {
    return days * 200.0;
}
