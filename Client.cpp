#include "Client.h"

Client::Client() : Client("NoName", "None", 0) {}
Client::Client(string n, string p, int id) : name(n), phone(p), clientID(id) {}
Client::~Client() {}

void Client::displayInfo() const {
    cout << name << " (ID: " << clientID << ")";
}
