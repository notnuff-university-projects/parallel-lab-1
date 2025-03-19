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
#include <chrono>

#include "data.h"
#include "f1.h"
#include "f2.h"
#include "f3.h"
#include "f4.h"

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

    F1 f1(&data);
    F2 f2(&data);
    F3 f3(&data);
    // F4 f4(&data);

    auto startTime = std::chrono::high_resolution_clock::now();

    f1.start();
    f2.start();
    f3.start();
    // f4.start();

    f1.join();
    f2.join();
    f3.join();
    // f4.join();
    std::cout << "\nAll threads completed their job" << std::endl;

    // Вимірювання часу завершення
    auto endTime = std::chrono::high_resolution_clock::now();

    // Обчислення часу виконання в мілісекундах
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);


    // Виведення результатів
    std::cout << "\nLaboratory Work 1.2 Done";
    std::cout << "\nExecutionTime: " << duration.count() << " ms" << std::endl;

    return 0;
}