#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "Engine.h"

class Vehicle {
protected:
    std::string brand;
    std::string model;
    Engine engine;

public:
    Vehicle(const std::string& b, const std::string& m, int hp, const std::string& t);
    virtual ~Vehicle();
    virtual void displayInfo() const;
};

#endif
