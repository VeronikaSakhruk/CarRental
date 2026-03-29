#include "Vehicle.h"

Vehicle::Vehicle(std::string brand, std::string plate, double price, std::shared_ptr<Engine> engine)
    : brand(brand), plate(plate), price(price), isAvailable(true), engine(engine) {}

std::string Vehicle::getBrand() const { return brand; }
std::string Vehicle::getPlate() const { return plate; }
double Vehicle::getPrice() const { return price; }
bool Vehicle::getAvailable() const { return isAvailable; }
void Vehicle::setAvailable(bool val) { isAvailable = val; }

std::string Vehicle::toFileLine() const {
    return getType() + ";" + brand + ";" + plate + ";"
         + std::to_string(price) + ";"
         + std::to_string(isAvailable) + ";"
         + (engine ? engine->getFuelType() : "") + ";"
         + std::to_string(engine ? engine->getHp() : 0);
}
