#include "CorporateClient.h"
#include <iostream>

CorporateClient::CorporateClient(std::string n, std::string p, int id, std::string cName)
    : Client(n, p, id), companyName(cName) {}

void CorporateClient::displayInfo() const {
    Client::displayInfo();
    std::cout << " [Company: " << companyName << "]";
}

void CorporateClient::printDetails() const {
    std::cout << "Company info: ";
    displayInfo();
    std::cout << std::endl;
}
