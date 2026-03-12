#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    double pricePerDay;
    static int totalCars; // 5. Static field

public:
    Car();
    Car(string b, string m, int y, double p);
    Car(const Car &other);            // 1. Copy constructor
    Car(Car &&other) noexcept;       // 2. Move constructor
    ~Car();

    void setPrice(double price);     // 3. This pointer inside
    void displayInfo() const;        // 4. Const method
    static int getTotalCars();
    string getBrand() const { return brand; }

    Car& operator++();               // 6. Unary (Price inflation)
    bool operator>(const Car& other) const; // 6. Binary (Price compare)

    friend ostream& operator<<(ostream& os, const Car& car); // 7. Insertion
};

#endif
