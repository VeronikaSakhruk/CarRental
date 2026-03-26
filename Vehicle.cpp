#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(std::string b, int hp, std::string t)
    : brand(b), engine(hp, t) {}

Vehicle::~Vehicle() {}

void Vehicle::displayInfo() const {
    std::cout << "Vehicle: " << brand << " | ";
    engine.displaySpecs();
}
