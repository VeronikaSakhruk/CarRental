#include <iostream>
#include "Car.h"
#include "Client.h"
#include "Rental.h"

using namespace std;

int main() {
    Car car1("Toyota", "Corolla", 2022, 70.0);
    Client client1("Anna", "123456789", 1);
    Rental rental1(5, 70.0);

    car1.displayInfo();
    client1.displayInfo();
    rental1.displayInfo();

    return 0;
}
