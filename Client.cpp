#include "Client.h"
#include <iostream>

Client::Client()
    : name("Unknown"), phone("None"), clientID(0) {
}

Client::Client(std::string n, std::string p, int id)
    : name(n), phone(p), clientID(id) {
}

Client::~Client() {}

void Client::displayInfo() const {
    std::cout << "Client: " << name
              << " | ID: " << clientID
              << " | Phone: " << phone;
}

void Client::printDetails() const {
    displayInfo();
}

double Client::getDiscount() const {
    return 0.0;
}
