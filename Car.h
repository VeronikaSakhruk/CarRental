#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    double pricePerDay;

public:
    Car();

    Car(string brand, string model, int year, double pricePerDay);

    Car(string brand, string model);

    ~Car();

    void displayInfo() const;
};

#endif
