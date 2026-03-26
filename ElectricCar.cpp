#include "ElectricCar.h"
#include <iostream>

ElectricCar::ElectricCar(std::string b, int hp, std::string t, int y, double rate, int battery)
    : Car(b, hp, t, y, rate), batteryCapacity(battery) {
}

void ElectricCar::displayInfo() const {
    Car::displayInfo();
    std::cout << " | Battery Capacity: " << batteryCapacity << " kWh";
}
