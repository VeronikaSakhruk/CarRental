#include <iostream>
#include "RentalSystem.h"
#include "Menu.h"
#include "Car.h"
#include "ElectricCar.h"
#include "Truck.h"
#include "CorporateClient.h"
#include "Exceptions.h"

using namespace std;

void seedData(RentalSystem& system) {
    auto petrol  = make_shared<Engine>("Petrol", 450);
    auto electric = make_shared<Engine>("Electric", 250);
    auto diesel  = make_shared<Engine>("Diesel", 500);

    system.addVehicle(make_shared<Car>("BMW M5", "AA1111BB", 1500.0, petrol));
    system.addVehicle(make_shared<ElectricCar>("Tesla Model 3", "EE5555EE", 1200.0, electric, 75));
    system.addVehicle(make_shared<Truck>("Volvo FH16", "BC0001CB", 2500.0, diesel, 20.0));

    system.addClient(make_shared<Client>("Ivan Petrenko", "+380501234567"));
    system.addClient(make_shared<CorporateClient>("Olena Kovalenko", "+380671112233", "TechCorp", 10.0));
}

int main() {
    try {
        RentalSystem system;

        system.loadVehicles();
        system.loadClients();

        if (system.getVehicleCount() == 0) {
            seedData(system);
            system.saveVehicles();
            system.saveClients();
        }

        Menu menu(system);
        menu.run();

    } catch (const FileException& e) {
        cout << "File error: " << e.what() << endl;
        return 1;
    } catch (const RentalException& e) {
        cout << "Application error: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cout << "Unexpected error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
