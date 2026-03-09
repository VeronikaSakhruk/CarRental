#ifndef RENTAL_H
#define RENTAL_H

class Rental {
private:
    int rentalDays;
    double totalCost;

public:
    Rental();
    Rental(int rentalDays, double pricePerDay);
    ~Rental();

    void calculateCost(double pricePerDay);
    void displayInfo() const;
};

#endif
