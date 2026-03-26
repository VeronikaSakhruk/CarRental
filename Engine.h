#ifndef ENGINE_H
#define ENGINE_H

#include <string>

class Engine {
private:
    int horsepower;
    std::string type;

public:
    Engine();
    Engine(int hp, const std::string& t);
    int getHP() const;
    std::string getType() const;

    void displaySpecs() const;
};

#endif
