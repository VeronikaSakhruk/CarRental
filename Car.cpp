#include "Car.h"

int Car::totalCars = 0;

Car::Car() : Vehicle("Unknown", "Unknown", 0, "None"), year(2020), pricePerDay(0.0) { totalCars++; }

Car::Car(std::string b, std::string m, int y, double p, int hp, std::string t)
    : Vehicle(b, m, hp, t), year(y), pricePerDay(p) {
    totalCars++;
}

Car::Car(const Car &other) : Vehicle(other), year(other.year), pricePerDay(other.pricePerDay) {
    totalCars++;
}

Car::Car(Car &&other) noexcept
    : Vehicle(std::move(other)), year(other.year), pricePerDay(other.pricePerDay) {
    other.year = 0;
}

Car::~Car() { totalCars--; }

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        brand = other.brand;
        model = other.model;
        engine = other.engine;
        year = other.year;
        pricePerDay = other.pricePerDay;
    }
    return *this;
}

void Car::displayInfo() const {
    Vehicle::displayInfo();
    std::cout << " | Year: " << year << " | Price: $" << pricePerDay << "/day";
}

int Car::getTotalCars() { return totalCars; }

Car& Car::operator++() { this->pricePerDay += 5.0; return *this; }
bool Car::operator>(const Car& other) const { return this->pricePerDay > other.pricePerDay; }

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << car.brand << " " << car.model << " ($" << car.pricePerDay << "/day)";
    return os;
}
