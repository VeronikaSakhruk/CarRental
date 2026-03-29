#ifndef ENGINE_H
#define ENGINE_H
#include <string>

class Engine {
    std::string fuelType;
    int horsepower;

public:
    Engine(std::string fuel, int hp) : fuelType(fuel), horsepower(hp) {}

    std::string getFuelType() const { return fuelType; }
    int getHp() const { return horsepower; }
};

#endif
