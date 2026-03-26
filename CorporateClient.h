#ifndef CORPORATE_CLIENT_H
#define CORPORATE_CLIENT_H
#include "Client.h"

class CorporateClient : public Client {
private:
    std::string companyName;

public:
    CorporateClient(std::string n, std::string p, int id, std::string cName);
    double getDiscount() const override;
    void displayInfo() const override;
};
#endif
