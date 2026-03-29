#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H
#include "Vehicle.h"

class ElectricCar : public Vehicle {
    int batteryCapacity;

public:
    ElectricCar(std::string brand, std::string plate, double price,
                std::shared_ptr<Engine> engine, int battery);

    std::string getType() const override;
    void display() const override;
    std::string toFileLine() const override;
};

#endif
