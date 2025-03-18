#include "f4.h"
#include <iostream>

F4::F4(Data* data) : data(data) {}

void F4::execute() {
    std::vector<double> P;

    if (data->N == 3)
    // Введення з клавіатури для малих розмірів
    P = data->getVectorFromConsole("P");

    // Виведення результату
    std::cout << "\nРезультат F4 (вектор P):\n";
    for (int i = 0; i < data->N; ++i) {
        std::cout << "O[" << i << "] = " << P[i] << "\n";
    }
    std::cout << std::endl;
} 