#include "Car.h"
#include <iostream>

Car::Car(std::string brand, std::string plate, double price, std::shared_ptr<Engine> engine)
    : Vehicle(brand, plate, price, engine) {}

std::string Car::getType() const { return "Car"; }

void Car::display() const {
    std::cout << "[Car] " << brand << " (" << plate << ")"
              << " | " << engine->getFuelType() << " " << engine->getHp() << "HP"
              << " | Price: " << price << " UAH/day"
              << " | " << (isAvailable ? "Available" : "Rented") << std::endl;
}
