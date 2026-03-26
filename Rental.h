#ifndef RENTAL_H
#define RENTAL_H
#include "Vehicle.h"
#include "Client.h"

class Rental {
private:
    Vehicle* rentedVehicle;
    Client* renter;
    int days;

public:
    Rental(Vehicle* v, Client* c, int d);
    void displayReport() const;
};
#endif
