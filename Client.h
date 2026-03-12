#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>

using namespace std;

class Client {
private:
    string name;
    string phone;
    int clientID;

public:
    Client();
    Client(string n, string p, int id);
    ~Client();
    void displayInfo() const;
    string getName() const { return name; }
};

#endif
