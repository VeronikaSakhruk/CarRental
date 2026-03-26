#include "Car.h"
#include <iostream>

Car::~Car() {}

Car::Car()
    : Vehicle("Unknown", 0, "None"), year(2026), dailyRate(0.0) {
}

Car::Car(std::string b, int hp, std::string t, int y, double rate)
    : Vehicle(b, hp, t), year(y), dailyRate(rate) {
}

void Car::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << " | Year: " << year
              << " | Rate: $" << dailyRate;
}

double Car::calculateRental(int days) const {
    return days * dailyRate;
}
