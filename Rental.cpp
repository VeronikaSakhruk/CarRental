#include "Rental.h"

Rental::Rental(const Car &c, const Client &cl, int d) : rentedCar(c), renter(cl), days(d) {
    totalCost = d * 50.0;
}

void Rental::displayReport() const {
    cout << "\n========================================" << endl;
    cout << "           RENTAL AGREEMENT             " << endl;
    cout << "========================================" << endl;

    // Тут ми знову виводимо деталі через методи об'єктів
    cout << "CUSTOMER: ";
    renter.displayInfo(); // Покаже Ім'я та ID

    cout << "\nVEHICLE:  " << rentedCar; // Використає наш новий оператор <<

    cout << "\n----------------------------------------" << endl;
    cout << "DURATION: " << days << " days" << endl;
    cout << "TOTAL:    $" << totalCost << endl;
    cout << "========================================\n" << endl;
}
