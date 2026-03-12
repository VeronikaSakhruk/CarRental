#include <iostream>
#include "Rental.h"

using namespace std;

int main() {
    // 1. Створюємо автопарк
    Car car1("Tesla", "Model 3", 2023, 100.0);
    Car car2("Ford", "Focus", 2019, 45.0);
    Client client1("Anna", "123456789", 1);

    // 2. Логічна дія: Клієнт просить дешевшу машину
    cout << ">>> Manager checking prices..." << endl;
    if (car1 > car2) {
        cout << car2.getBrand() << " is more budget-friendly." << endl;
    }

    // 3. Логічна дія: Сталася інфляція, менеджер оновлює ціну одним кліком
    ++car2;
    cout << "Updated price for Ford (with tax): " << car2 << endl;

    // 4. Оформлюємо оренду (тут виведеться і Анна, і машина)
    Rental order(car1, client1, 5);
    order.displayReport();

    // 5. Статистика для власника бізнесу
    cout << "Total cars in system: " << Car::getTotalCars() << endl;

    return 0;
}
