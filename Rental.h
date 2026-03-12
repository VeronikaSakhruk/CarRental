#ifndef RENTAL_H
#define RENTAL_H

#include "Car.h"
#include "Client.h"

class Rental {
private:
    Car rentedCar;
    Client renter;
    int days;
    double totalCost;

public:
    Rental(const Car &c, const Client &cl, int d);
    void displayReport() const;
};

#endif
