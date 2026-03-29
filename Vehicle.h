#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
#include <iostream>
#include <memory>
#include "Engine.h"
#include "IDisplayable.h"

class Vehicle : public IDisplayable {
protected:
    std::string brand;
    std::string plate;
    double price;
    bool isAvailable;
    std::shared_ptr<Engine> engine;

public:
    Vehicle(std::string brand, std::string plate, double price, std::shared_ptr<Engine> engine);
    virtual ~Vehicle() = default;

    std::string getBrand() const;
    std::string getPlate() const;
    double getPrice() const;
    bool getAvailable() const;
    void setAvailable(bool val);

    virtual std::string getType() const = 0;
    virtual void display() const = 0;

    virtual std::string toFileLine() const;
};

#endif
