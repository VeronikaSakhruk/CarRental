#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double loadCapacity;
public:
    Truck(std::string b, int hp, std::string t, double capacity);

    void displayInfo() const override;
    double calculateRental(int days) const override; // Реалізація чисто віртуальної функції
};

#endif
