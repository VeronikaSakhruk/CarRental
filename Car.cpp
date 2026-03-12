#include "Car.h"

int Car::totalCars = 0;

Car::Car() : Car("Unknown", "Unknown", 2020, 0.0) {}

Car::Car(string b, string m, int y, double p) : brand(b), model(m), year(y), pricePerDay(p) {
    totalCars++;
}

// 1. Copy
Car::Car(const Car &other) : brand(other.brand), model(other.model), year(other.year), pricePerDay(other.pricePerDay) {
    totalCars++;
}

// 2. Move
Car::Car(Car &&other) noexcept : brand(move(other.brand)), model(move(other.model)), year(other.year), pricePerDay(other.pricePerDay) {}

Car::~Car() {}

void Car::setPrice(double pricePerDay) {
    this->pricePerDay = pricePerDay; // 3. This usage
}

void Car::displayInfo() const {
    cout << brand << " " << model << " (" << year << ")";
}

int Car::getTotalCars() { return totalCars; }

Car& Car::operator++() {
    this->pricePerDay += 5.0;
    return *this;
}

bool Car::operator>(const Car& other) const {
    return this->pricePerDay > other.pricePerDay;
}

ostream& operator<<(ostream& os, const Car& car) {
    os << car.brand << " " << car.model << " ($" << car.pricePerDay << "/day)";
    return os;
}
