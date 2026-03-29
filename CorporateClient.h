#ifndef CORPORATECLIENT_H
#define CORPORATECLIENT_H
#include "Client.h"

class CorporateClient : public Client {
    std::string company;
    double discount;

public:
    CorporateClient(std::string name, std::string phone, std::string company, double discount);

    std::string getClientType() const override;
    double getDiscount() const;
    std::string toFileLine() const override;
};

#endif
