#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"

class Truck : public Vehicle {
    double loadCapacity;

public:
    Truck(std::string brand, std::string plate, double price,
          std::shared_ptr<Engine> engine, double loadCapacity);

    std::string getType() const override;
    void display() const override;
    std::string toFileLine() const override;
};

#endif
