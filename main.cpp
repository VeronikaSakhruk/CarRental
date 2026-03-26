#include <iostream>
#include <vector>
#include "ElectricCar.h"
#include "CorporateClient.h"

using namespace std;

void printVehicle(const Vehicle& v) {
    v.displayInfo();
}

int main() {
    ElectricCar tesla("Tesla", 450, "Electric", 2024, 120.5, 85);
    CorporateClient corp("Ivan", "0991234567", 101, "CyberTech");

    Vehicle* vPtr = &tesla;
    cout << "Pointer Polymorphism: ";
    vPtr->displayInfo();

    cout << "\nReference Polymorphism: ";
    printVehicle(tesla);

    cout << "\n\nInterface usage:";
    IDisplayable* items[2];
    items[0] = &tesla;
    items[1] = &corp;

    for(int i = 0; i < 2; i++) {
        cout << "\nItem " << i+1 << ": ";
        items[i]->printDetails();
    }

    return 0;
}
