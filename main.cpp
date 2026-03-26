#include <iostream>
#include "ElectricCar.h"
#include "Truck.h"
#include "Rental.h"
#include "CorporateClient.h"

using namespace std;

int main() {
    ElectricCar tesla("Tesla", "Model 3", 2023, 120.0, 450, 75);
    CorporateClient corp("Ivan", "0991234567", 101, "CyberTech");
    Truck man("MAN", "TGX", 500, "Diesel", 20.0);
    Client regular("Olena", "0507778899", 102);

    Rental order1(&tesla, &corp, 3);
    order1.displayReport();

    Rental order2(&man, &regular, 5);
    order2.displayReport();

    cout << "Total cars in system: " << Car::getTotalCars() << endl;

    return 0;
}
