/**
* ПЗВПКС
* Лабораторна робота ЛР1.2
* Потоки в бібліотеці PThread
* F1: 1.22: d = (B*C) + (A*B) +(C*(B*(MA*ME)))
* F2: 2.10: MK = MA*(MG*MZ) + TRANS(ML)]
* F3: 3.9: O = SORT(P)*(MR * MS)
* Ярошенко Олександр Сергійович
* Група ІМ-21
* Дата 16.03.2025
*/

#include <iostream>
#include <stdexcept>
#include <pthread.h>
#include "data.h"


int main() {
    // Print the prompt to the user
    std::cout << "Оберіть режим: малі числа / великі числа (натисніть [s] або [b]): ";

    char input;
    std::cin >> input;

    Mode dataMode;
    if (input == 's') {
        std::cout << "Обрано режим малих чисел (N=3)." << std::endl;
        dataMode = Mode::SmallNum;
    } else if (input == 'b') {
        dataMode = Mode::BigNum;
        std::cout << "Обрано режим великих чисел (N=1000)." << std::endl;
    } else {
        throw std::invalid_argument("Невірний ввід. Будь ласка, введіть 's' або 'b'.");
    }

    // Глобальний об'єкт даних для доступу з потоків
    Data data(dataMode);

    std::cout << "\nВсі потоки завершили роботу." << std::endl;
    return 0;
}