#include "Engine.h"

Engine::Engine() : horsepower(100), type("Unknown") {}

Engine::Engine(int hp, const std::string& t) : horsepower(hp), type(t) {}

int Engine::getHP() const { return horsepower; }

std::string Engine::getType() const { return type; }
