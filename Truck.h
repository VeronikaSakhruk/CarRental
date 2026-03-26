#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double maxPayload;

public:
    Truck(std::string b, std::string m, int hp, std::string t, double payload);
    void displayInfo() const override;
};
#endif
