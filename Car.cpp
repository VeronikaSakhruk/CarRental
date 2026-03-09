#include "Car.h"
#include <iostream>
using namespace std;

Car::Car() : Car("Unknown", "Unknown", 0, 0.0) {}

Car::Car(string brand, string model)
    : Car(brand, model, 2020, 50.0) {}

Car::Car(string brand, string model, int year, double pricePerDay)
    : brand(brand), model(model), year(year), pricePerDay(pricePerDay) {}

Car::~Car() {
    cout << "Car destroyed: " << brand << " " << model << endl;
}

void Car::displayInfo() const {
    cout << brand << " " << model << " (" << year << ") - "
         << pricePerDay << "$ per day" << endl;
}
