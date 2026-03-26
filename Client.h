#ifndef CLIENT_H
#define CLIENT_H
#include <string>

class Client {
protected:
    std::string name;
    std::string phone;
    int clientID;

public:
    Client();
    Client(std::string n, std::string p, int id);
    virtual ~Client();
    virtual double getDiscount() const;
    virtual void displayInfo() const;
};
#endif
