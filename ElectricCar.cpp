#include "ElectricCar.h"
#include <iostream>

ElectricCar::ElectricCar(std::string brand, std::string plate, double price,
                         std::shared_ptr<Engine> engine, int battery)
    : Vehicle(brand, plate, price, engine), batteryCapacity(battery) {}

std::string ElectricCar::getType() const { return "ElectricCar"; }

void ElectricCar::display() const {
    std::cout << "[Electric] " << brand << " (" << plate << ")"
              << " | Battery: " << batteryCapacity << "kWh"
              << " | Price: " << price << " UAH/day"
              << " | " << (isAvailable ? "Available" : "Rented") << std::endl;
}

std::string ElectricCar::toFileLine() const {
    // ElectricCar;brand;plate;price;available;fuel;hp;battery
    return Vehicle::toFileLine() + ";" + std::to_string(batteryCapacity);
}
