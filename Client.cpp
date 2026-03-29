#include "Client.h"

Client::Client(std::string name, std::string phone) : name(name), phone(phone) {}

std::string Client::getName() const { return name; }
std::string Client::getPhone() const { return phone; }
std::string Client::getClientType() const { return "Client"; }

std::string Client::toFileLine() const {
    return "Client;" + name + ";" + phone;
}
