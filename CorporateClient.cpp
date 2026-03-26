#include "CorporateClient.h"
#include <iostream>

CorporateClient::CorporateClient(std::string n, std::string p, int id, std::string cName)
    : Client(n, p, id), companyName(cName) {}

double CorporateClient::getDiscount() const { return 0.15; }

void CorporateClient::displayInfo() const {
    Client::displayInfo();
    std::cout << " [Company: " << companyName << "]";
}
