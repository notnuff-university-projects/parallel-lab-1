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

#include "data.h"

int main() {
    Data data;

    // Print the prompt to the user
    std::cout << "Select mode: small number / big number (press [s] or [b]): ";

    char input;
    // Read the input character
    std::cin >> input;

    // Validate the input
    if (input == 's') {
        std::cout << "Small number mode selected." << std::endl;
        data.mode = Mode::SmallNum;
    } else if (input == 'b') {
        data.mode = Mode::BigNum;
        std::cout << "Big number mode selected." << std::endl;
    } else {
        // Throw an error if input is not 's' or 'b'
        throw std::invalid_argument("Invalid input. Please enter 's' or 'b'.");
    }



    return 0;
}