#ifndef CLIENT_H
#define CLIENT_H

#include <string>
using namespace std;

class Client {
private:
    string name;
    string phone;
    int clientID;

public:
    Client();
    Client(string name, string phone, int clientID = 0);
    ~Client();

    void displayInfo() const;
};

#endif
