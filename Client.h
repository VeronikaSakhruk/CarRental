#ifndef CLIENT_H
#define CLIENT_H
#include <string>

class Client {
protected:
    std::string name;
    std::string phone;

public:
    Client(std::string name, std::string phone);
    virtual ~Client() = default;

    std::string getName() const;
    std::string getPhone() const;
    virtual std::string getClientType() const;
    virtual std::string toFileLine() const;
};

#endif
