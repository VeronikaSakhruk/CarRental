#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(const std::string& b, const std::string& m, int hp, const std::string& t)
    : brand(b), model(m), engine(hp, t) {}

Vehicle::~Vehicle() {}

void Vehicle::displayInfo() const {
    std::cout << brand << " " << model
              << " [" << engine.getHP() << " HP, " << engine.getType() << "]";
}
