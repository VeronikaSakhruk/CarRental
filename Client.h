#ifndef CLIENT_H
#define CLIENT_H

#include "IDisplayable.h"
#include <string>

class Client : public IDisplayable {
protected:
    std::string name;
    std::string phone;
    int clientID;

public:
    Client();
    Client(std::string n, std::string p, int id);
    virtual ~Client();

    virtual void displayInfo() const;

    virtual double getDiscount() const;

    void printDetails() const override;
};

#endif
