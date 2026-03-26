#ifndef VEHICLE_H
#define VEHICLE_H

#include "IDisplayable.h"
#include "Engine.h"
#include <string>

class Vehicle : public IDisplayable {
protected:
    std::string brand;
    Engine engine;

public:
    Vehicle(std::string b, int hp, std::string t);
    virtual ~Vehicle();

    virtual void displayInfo() const;
    virtual double calculateRental(int days) const = 0;

    void printDetails() const override { displayInfo(); }
};

#endif
