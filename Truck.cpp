#include "Truck.h"
#include <iostream>

Truck::Truck(std::string b, std::string m, int hp, std::string t, double payload)
    : Vehicle(b, m, hp, t), maxPayload(payload) {}

void Truck::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << " | Payload: " << maxPayload << " tons";
}
