#include "Client.h"
#include <iostream>
using namespace std;

Client::Client() : Client("NoName", "NoPhone", 0) {}

Client::Client(string name, string phone, int clientID)
    : name(name), phone(phone), clientID(clientID) {}

Client::~Client() {
    cout << "Client destroyed: " << name << endl;
}

void Client::displayInfo() const {
    cout << "Client: " << name << ", Phone: " << phone
         << ", ID: " << clientID << endl;
}
