#include "Client.h"
#include <iostream>

Client::Client() : name("NoName"), phone("None"), clientID(0) {}

Client::Client(std::string n, std::string p, int id) : name(n), phone(p), clientID(id) {}

Client::~Client() {}

double Client::getDiscount() const { return 0.0; }

void Client::displayInfo() const {
    std::cout << name << " (ID: " << clientID << ", Tel: " << phone << ")";
}
