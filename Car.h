#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
protected:
    double dailyRate;
    int year;
public:
    Car();
    Car(std::string b, int hp, std::string t, int y, double rate);

    virtual ~Car();
    void displayInfo() const override;
    double calculateRental(int days) const override;
};

#endif
