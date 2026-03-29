#ifndef MENU_H
#define MENU_H
#include "RentalSystem.h"
#include <string>

class Menu {
    RentalSystem& system;
    std::string adminPassword;

    void adminMenu();
    void userMenu();
    bool checkPassword();

public:
    Menu(RentalSystem& system);
    void run();
};

#endif
