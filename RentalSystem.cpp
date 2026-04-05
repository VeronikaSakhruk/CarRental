#include "RentalSystem.h"
#include "Car.h"
#include "ElectricCar.h"
#include "Truck.h"
#include "CorporateClient.h"
#include "Exceptions.h"
#include <iostream>
#include <fstream>
#include <sstream>


// Vehicles
void RentalSystem::addVehicle(std::shared_ptr<Vehicle> v) {
    vehicles.push_back(v);
}

void RentalSystem::removeVehicle(size_t index) {
    if (index >= vehicles.size())
        throw InvalidIndexException();

    if (!vehicles[index]->getAvailable())
        throw RentalException("Cannot remove: vehicle is currently rented.");

    std::cout << "Removed: " << vehicles[index]->getBrand() << std::endl;
    vehicles.erase(vehicles.begin() + index);
    saveVehicles();
}

void RentalSystem::showVehicles() const {
    if (vehicles.empty()) { std::cout << "No vehicles." << std::endl; return; }
    std::cout << "\n--- All Vehicles ---" << std::endl;
    for (size_t i = 0; i < vehicles.size(); ++i) {
        std::cout << i + 1 << ". ";
        vehicles[i]->display();
    }
}

void RentalSystem::showAvailableVehicles() const {
    std::cout << "\n--- Available Vehicles ---" << std::endl;
    bool found = false;
    for (size_t i = 0; i < vehicles.size(); ++i) {
        if (vehicles[i]->getAvailable()) {
            std::cout << i + 1 << ". ";
            vehicles[i]->display();
            found = true;
        }
    }
    if (!found) std::cout << "No available vehicles." << std::endl;
}

size_t RentalSystem::getVehicleCount() const { return vehicles.size(); }

std::shared_ptr<Vehicle> RentalSystem::getVehicle(size_t i) { return vehicles[i]; }


// Clients
void RentalSystem::addClient(std::shared_ptr<Client> c) {
    clients.push_back(c);
}

void RentalSystem::showClients() const {
    if (clients.empty()) { std::cout << "No clients." << std::endl; return; }
    std::cout << "\n--- Clients ---" << std::endl;
    for (size_t i = 0; i < clients.size(); ++i) {
        std::cout << i + 1 << ". " << clients[i]->getName()
                  << " | " << clients[i]->getPhone()
                  << " | " << clients[i]->getClientType() << std::endl;
    }
}

size_t RentalSystem::getClientCount() const { return clients.size(); }

std::shared_ptr<Client> RentalSystem::getClient(size_t i) { return clients[i]; }


// Rentals
void RentalSystem::rentVehicle(size_t vIdx, size_t cIdx, int days) {
    if (vIdx >= vehicles.size() || cIdx >= clients.size())
        throw InvalidIndexException();

    if (days <= 0)
        throw RentalException("Number of days must be positive.");

    auto v = vehicles[vIdx];
    auto c = clients[cIdx];

    if (!v->getAvailable())
        throw VehicleNotAvailableException();

    double cost = v->getPrice() * days;

    CorporateClient* corp = dynamic_cast<CorporateClient*>(c.get());
    if (corp) {
        cost -= cost * corp->getDiscount() / 100.0;
        std::cout << "Corporate discount applied: " << corp->getDiscount() << "%" << std::endl;
    }

    v->setAvailable(false);
    auto rental = std::make_shared<Rental>(v, c, days, cost);
    rentals.push_back(rental);
    rental->logToFile();
    saveVehicles();

    std::cout << "Rented successfully! Total: " << cost << " UAH" << std::endl;
}

void RentalSystem::returnVehicle(size_t rIdx) {
    if (rIdx >= rentals.size())
        throw InvalidIndexException();

    auto r = rentals[rIdx];
    if (!r->active)
        throw AlreadyReturnedException();

    r->active = false;
    r->vehicle->setAvailable(true);
    saveVehicles();
    std::cout << "Vehicle returned successfully." << std::endl;
}

void RentalSystem::showRentals() const {
    if (rentals.empty()) { std::cout << "No rentals." << std::endl; return; }
    std::cout << "\n--- Rentals ---" << std::endl;
    for (size_t i = 0; i < rentals.size(); ++i) {
        std::cout << i + 1 << ". ";
        rentals[i]->display();
    }
}

void RentalSystem::showClientHistory(size_t cIdx) const {
    if (cIdx >= clients.size())
        throw InvalidIndexException();

    std::string name = clients[cIdx]->getName();
    std::cout << "\n--- History for " << name << " ---" << std::endl;
    bool found = false;
    for (auto& r : rentals) {
        if (r->client->getName() == name) {
            r->display();
            found = true;
        }
    }
    if (!found) std::cout << "No rentals found." << std::endl;
}


// Files
void RentalSystem::saveVehicles() const {
    std::ofstream out("vehicles.txt");
    if (!out) throw FileException("vehicles.txt");
    for (auto& v : vehicles)
        out << v->toFileLine() << std::endl;
}

void RentalSystem::loadVehicles() {
    std::ifstream in("vehicles.txt");
    if (!in) return;

    vehicles.clear();
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        try {
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> parts;
            while (std::getline(ss, token, ';'))
                parts.push_back(token);

            if (parts.size() < 7) continue;

            std::string type  = parts[0];
            std::string brand = parts[1];
            std::string plate = parts[2];
            double price      = std::stod(parts[3]);
            bool available    = (parts[4] == "1");
            std::string fuel  = parts[5];
            int hp            = std::stoi(parts[6]);

            auto eng = std::make_shared<Engine>(fuel, hp);
            std::shared_ptr<Vehicle> v;

            if (type == "Car") {
                v = std::make_shared<Car>(brand, plate, price, eng);
            } else if (type == "ElectricCar" && parts.size() >= 8) {
                int battery = std::stoi(parts[7]);
                v = std::make_shared<ElectricCar>(brand, plate, price, eng, battery);
            } else if (type == "Truck" && parts.size() >= 8) {
                double load = std::stod(parts[7]);
                v = std::make_shared<Truck>(brand, plate, price, eng, load);
            } else {
                continue;
            }

            v->setAvailable(available);
            vehicles.push_back(v);
        } catch (const std::exception& e) {
            std::cout << "Warning: skipping bad line in vehicles.txt: " << e.what() << std::endl;
        }
    }
}

void RentalSystem::saveClients() const {
    std::ofstream out("clients.txt");
    if (!out) throw FileException("clients.txt");
    for (auto& c : clients)
        out << c->toFileLine() << std::endl;
}

void RentalSystem::loadClients() {
    std::ifstream in("clients.txt");
    if (!in) return;

    clients.clear();
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        try {
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> parts;
            while (std::getline(ss, token, ';'))
                parts.push_back(token);

            if (parts.size() < 3) continue;

            if (parts[0] == "Client") {
                clients.push_back(std::make_shared<Client>(parts[1], parts[2]));
            } else if (parts[0] == "CorporateClient" && parts.size() >= 5) {
                clients.push_back(std::make_shared<CorporateClient>(
                    parts[1], parts[2], parts[3], std::stod(parts[4])));
            }
        } catch (const std::exception& e) {
            std::cout << "Warning: skipping bad line in clients.txt: " << e.what() << std::endl;
        }
    }
}
