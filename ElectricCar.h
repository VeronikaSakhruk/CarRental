#ifndef ELECTRIC_CAR_H
#define ELECTRIC_CAR_H
#include "Car.h"

class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar(std::string b, std::string m, int y, double p, int hp, int cap);
    ElectricCar(const ElectricCar& other);
    ElectricCar(ElectricCar&& other) noexcept;
    ElectricCar& operator=(const ElectricCar& other);
    void displayInfo() const override;
};
#endif
