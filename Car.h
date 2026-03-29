#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(std::string brand, std::string plate, double price, std::shared_ptr<Engine> engine);

    std::string getType() const override;
    void display() const override;
};

#endif
