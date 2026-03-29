#include "Menu.h"
#include "Car.h"
#include "ElectricCar.h"
#include "Truck.h"
#include "CorporateClient.h"
#include <iostream>
#include <fstream>
#include <limits>

Menu::Menu(RentalSystem& system) : system(system) {
    // завантажуємо пароль з файлу, якщо є
    adminPassword = "admin123";
    std::ifstream f("password.txt");
    if (f) std::getline(f, adminPassword);
}

bool Menu::checkPassword() {
    std::string p;
    std::cout << "Password: ";
    std::cin >> p;
    std::cin.ignore();
    return p == adminPassword;
}

void Menu::run() {
    // завантажуємо дані при старті
    system.loadVehicles();
    system.loadClients();

    int choice;
    while (true) {
        std::cout << "\n=== CAR RENTAL ===" << std::endl;
        std::cout << "1. Admin" << std::endl;
        std::cout << "2. User" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore();

        if (choice == 0) break;
        else if (choice == 1) {
            if (checkPassword()) adminMenu();
            else std::cout << "Wrong password!" << std::endl;
        }
        else if (choice == 2) userMenu();
        else std::cout << "Invalid choice." << std::endl;
    }
}

void Menu::adminMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- ADMIN MENU ---" << std::endl;
        std::cout << "1. Show all vehicles" << std::endl;
        std::cout << "2. Add Car" << std::endl;
        std::cout << "3. Add Electric Car" << std::endl;
        std::cout << "4. Add Truck" << std::endl;
        std::cout << "5. Remove vehicle" << std::endl;
        std::cout << "6. Add Client" << std::endl;
        std::cout << "7. Add Corporate Client" << std::endl;
        std::cout << "8. Show all clients" << std::endl;
        std::cout << "9. Show all rentals" << std::endl;
        std::cout << "10. Change password" << std::endl;
        std::cout << "0. Logout" << std::endl;
        std::cout << "Choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore();

        if (choice == 0) break;

        else if (choice == 1) {
            system.showVehicles();
        }
        else if (choice == 2) {
            std::string brand, plate, fuel;
            double price; int hp;
            std::cout << "Brand: "; std::getline(std::cin, brand);
            std::cout << "Plate: "; std::getline(std::cin, plate);
            std::cout << "Price/day: "; std::cin >> price; std::cin.ignore();
            std::cout << "Fuel type: "; std::getline(std::cin, fuel);
            std::cout << "HP: "; std::cin >> hp; std::cin.ignore();

            auto eng = std::make_shared<Engine>(fuel, hp);
            system.addVehicle(std::make_shared<Car>(brand, plate, price, eng));
            system.saveVehicles();
            std::cout << "Car added." << std::endl;
        }
        else if (choice == 3) {
            std::string brand, plate, fuel;
            double price; int hp, battery;
            std::cout << "Brand: "; std::getline(std::cin, brand);
            std::cout << "Plate: "; std::getline(std::cin, plate);
            std::cout << "Price/day: "; std::cin >> price; std::cin.ignore();
            std::cout << "Fuel type: "; std::getline(std::cin, fuel);
            std::cout << "HP: "; std::cin >> hp; std::cin.ignore();
            std::cout << "Battery (kWh): "; std::cin >> battery; std::cin.ignore();

            auto eng = std::make_shared<Engine>(fuel, hp);
            system.addVehicle(std::make_shared<ElectricCar>(brand, plate, price, eng, battery));
            system.saveVehicles();
            std::cout << "Electric car added." << std::endl;
        }
        else if (choice == 4) {
            std::string brand, plate, fuel;
            double price, load; int hp;
            std::cout << "Brand: "; std::getline(std::cin, brand);
            std::cout << "Plate: "; std::getline(std::cin, plate);
            std::cout << "Price/day: "; std::cin >> price; std::cin.ignore();
            std::cout << "Fuel type: "; std::getline(std::cin, fuel);
            std::cout << "HP: "; std::cin >> hp; std::cin.ignore();
            std::cout << "Load capacity (tons): "; std::cin >> load; std::cin.ignore();

            auto eng = std::make_shared<Engine>(fuel, hp);
            system.addVehicle(std::make_shared<Truck>(brand, plate, price, eng, load));
            system.saveVehicles();
            std::cout << "Truck added." << std::endl;
        }
        else if (choice == 5) {
            system.showVehicles();
            if (system.getVehicleCount() == 0) continue;
            size_t idx;
            std::cout << "Number to remove: "; std::cin >> idx; std::cin.ignore();
            system.removeVehicle(idx - 1);
        }
        else if (choice == 6) {
            std::string name, phone;
            std::cout << "Name: "; std::getline(std::cin, name);
            std::cout << "Phone: "; std::getline(std::cin, phone);
            system.addClient(std::make_shared<Client>(name, phone));
            system.saveClients();
            std::cout << "Client added." << std::endl;
        }
        else if (choice == 7) {
            std::string name, phone, company;
            double discount;
            std::cout << "Name: "; std::getline(std::cin, name);
            std::cout << "Phone: "; std::getline(std::cin, phone);
            std::cout << "Company: "; std::getline(std::cin, company);
            std::cout << "Discount (%): "; std::cin >> discount; std::cin.ignore();
            system.addClient(std::make_shared<CorporateClient>(name, phone, company, discount));
            system.saveClients();
            std::cout << "Corporate client added." << std::endl;
        }
        else if (choice == 8) {
            system.showClients();
        }
        else if (choice == 9) {
            system.showRentals();
        }
        else if (choice == 10) {
            std::string np;
            std::cout << "New password: "; std::getline(std::cin, np);
            if (!np.empty()) {
                adminPassword = np;
                std::ofstream f("password.txt");
                if (f) f << adminPassword;
                std::cout << "Password changed." << std::endl;
            }
        }
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}

void Menu::userMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- USER MENU ---" << std::endl;
        std::cout << "1. Show available vehicles" << std::endl;
        std::cout << "2. Rent a vehicle" << std::endl;
        std::cout << "3. Return a vehicle" << std::endl;
        std::cout << "4. My rental history" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "Choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore();

        if (choice == 0) break;

        else if (choice == 1) {
            system.showAvailableVehicles();
        }
        else if (choice == 2) {
            system.showAvailableVehicles();
            system.showClients();
            if (system.getVehicleCount() == 0 || system.getClientCount() == 0) continue;

            size_t vIdx, cIdx; int days;
            std::cout << "Vehicle number: "; std::cin >> vIdx; std::cin.ignore();
            std::cout << "Client number: "; std::cin >> cIdx; std::cin.ignore();
            std::cout << "Days: "; std::cin >> days; std::cin.ignore();
            system.rentVehicle(vIdx - 1, cIdx - 1, days);
        }
        else if (choice == 3) {
            system.showRentals();
            if (system.getClientCount() == 0) continue;
            size_t rIdx;
            std::cout << "Rental number: "; std::cin >> rIdx; std::cin.ignore();
            system.returnVehicle(rIdx - 1);
        }
        else if (choice == 4) {
            system.showClients();
            if (system.getClientCount() == 0) continue;
            size_t cIdx;
            std::cout << "Client number: "; std::cin >> cIdx; std::cin.ignore();
            system.showClientHistory(cIdx - 1);
        }
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    }
}
