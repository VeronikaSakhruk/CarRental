#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include <iostream>

class Car : public Vehicle {
protected:
    int year;
    double pricePerDay;
    static int totalCars;
public:
    Car();
    Car(std::string b, std::string m, int y, double p, int hp, std::string t);
    Car(const Car &other);
    Car(Car &&other) noexcept;
    virtual ~Car();

    Car& operator=(const Car& other);
    static int getTotalCars();
    void displayInfo() const override;

    Car& operator++();
    bool operator>(const Car& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Car& car);
};
#endif
