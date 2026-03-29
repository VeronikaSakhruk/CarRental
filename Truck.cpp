#include "Truck.h"
#include <iostream>

Truck::Truck(std::string brand, std::string plate, double price,
             std::shared_ptr<Engine> engine, double loadCapacity)
    : Vehicle(brand, plate, price, engine), loadCapacity(loadCapacity) {}

std::string Truck::getType() const { return "Truck"; }

void Truck::display() const {
    std::cout << "[Truck] " << brand << " (" << plate << ")"
              << " | Load: " << loadCapacity << "t"
              << " | " << engine->getFuelType() << " " << engine->getHp() << "HP"
              << " | Price: " << price << " UAH/day"
              << " | " << (isAvailable ? "Available" : "Rented") << std::endl;
}

std::string Truck::toFileLine() const {
    // Truck;brand;plate;price;available;fuel;hp;loadCapacity
    return Vehicle::toFileLine() + ";" + std::to_string(loadCapacity);
}
