#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H

#include "Car.h"

class ElectricCar : public Car {
private:
    int batteryCapacity;
public:
    ElectricCar(std::string b, int hp, std::string t, int y, double rate, int battery);

    void displayInfo() const override;
};

#endif
