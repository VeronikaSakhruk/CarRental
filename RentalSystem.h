#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H
#include <vector>
#include <memory>
#include <string>
#include "Vehicle.h"
#include "Client.h"
#include "Rental.h"

class RentalSystem {
    std::vector<std::shared_ptr<Vehicle>> vehicles;
    std::vector<std::shared_ptr<Client>> clients;
    std::vector<std::shared_ptr<Rental>> rentals;

public:
    // vehicles
    void addVehicle(std::shared_ptr<Vehicle> v);
    void removeVehicle(size_t index);
    void showVehicles() const;
    void showAvailableVehicles() const;
    size_t getVehicleCount() const;
    std::shared_ptr<Vehicle> getVehicle(size_t i);

    // clients
    void addClient(std::shared_ptr<Client> c);
    void showClients() const;
    size_t getClientCount() const;
    std::shared_ptr<Client> getClient(size_t i);

    // rentals
    void rentVehicle(size_t vIdx, size_t cIdx, int days);
    void returnVehicle(size_t rIdx);
    void showRentals() const;
    void showClientHistory(size_t cIdx) const;

    // files
    void saveVehicles() const;
    void loadVehicles();
    void saveClients() const;
    void loadClients();
};

#endif
