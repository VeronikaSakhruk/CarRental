#include "CorporateClient.h"

CorporateClient::CorporateClient(std::string name, std::string phone,
                                 std::string company, double discount)
    : Client(name, phone), company(company), discount(discount) {}

std::string CorporateClient::getClientType() const {
    return "Corporate (" + company + ")";
}

double CorporateClient::getDiscount() const { return discount; }

std::string CorporateClient::toFileLine() const {
    return "CorporateClient;" + name + ";" + phone + ";"
         + company + ";" + std::to_string(discount);
}
