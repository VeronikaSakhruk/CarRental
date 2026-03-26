#include "ElectricCar.h"
#include <iostream>

ElectricCar::ElectricCar(std::string b, std::string m, int y, double p, int hp, int cap)
    : Car(b, m, y, p, hp, "Electric"), batteryCapacity(cap) {}

ElectricCar::ElectricCar(const ElectricCar& other)
    : Car(other), batteryCapacity(other.batteryCapacity) {}

ElectricCar::ElectricCar(ElectricCar&& other) noexcept
    : Car(std::move(other)), batteryCapacity(other.batteryCapacity) {
    other.batteryCapacity = 0;
}

ElectricCar& ElectricCar::operator=(const ElectricCar& other) {
    if (this != &other) {
        Car::operator=(other);
        batteryCapacity = other.batteryCapacity;
    }
    return *this;
}

void ElectricCar::displayInfo() const {
    Car::displayInfo();
    std::cout << " | Battery: " << batteryCapacity << " kWh";
}
