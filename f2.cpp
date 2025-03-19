#include "f2.h"
#include <iostream>

F2::F2(Data* data) : TThread(), data(data) {}

void F2::execute() {
    std::vector<std::vector<double>> MB, MC, MD;
    std::vector<double> A;

    if (data->N == 3) {
        // Виведення тексту про поточну функцію
        pthread_mutex_lock(&data->inputMutex);
        std::cout << "\nВведення F2:\n";
        pthread_mutex_unlock(&data->inputMutex);

        // Введення даних з клавіатури
        MB = data->getMatrixFromConsole("MB");
        MC = data->getMatrixFromConsole("MC");
        MD = data->getMatrixFromConsole("MD");
        A = data->getVectorFromConsole("A");
    } else {
        // Генерація випадкових даних
        MB = data->generateRandomMatrix();
        MC = data->generateRandomMatrix();
        MD = data->generateRandomMatrix();
        A = data->generateRandomVector();
    }

    // Обчислення F2
    std::vector<std::vector<double>> result = data->multiplyMatrices(
        data->multiplyMatrices(MB, MC),
        data->multiplyMatrices(MD, data->transposeMatrix(MD))
    );
    
    // Виведення результату
    data->printMatrix("MK", result);
} 