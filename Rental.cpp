#include "Rental.h"
#include <iostream>
using namespace std;

Rental::Rental() : rentalDays(0), totalCost(0.0) {}

Rental::Rental(int rentalDays, double pricePerDay)
    : rentalDays(rentalDays) {
    calculateCost(pricePerDay);
}

Rental::~Rental() {
    cout << "Rental destroyed." << endl;
}

void Rental::calculateCost(double pricePerDay) {
    totalCost = rentalDays * pricePerDay;
}

void Rental::displayInfo() const {
    cout << "Rental days: " << rentalDays
         << ", Total cost: " << totalCost << "$" << endl;
}
