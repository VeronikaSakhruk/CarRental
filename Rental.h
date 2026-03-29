#ifndef RENTAL_H
#define RENTAL_H
#include <string>
#include <memory>
#include "Vehicle.h"
#include "Client.h"

class Rental {
public:
    std::shared_ptr<Vehicle> vehicle;
    std::shared_ptr<Client> client;
    int days;
    double totalCost;
    bool active;

    Rental(std::shared_ptr<Vehicle> v, std::shared_ptr<Client> c, int days, double cost);

    void display() const;
    void logToFile() const;
};

#endif
