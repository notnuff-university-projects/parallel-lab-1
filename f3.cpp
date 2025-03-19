#include "f3.h"
#include <iostream>

F3::F3(Data* data) : TThread(), data(data) {}

void F3::execute() {
    std::vector<double> B, C;
    std::vector<std::vector<double>> MA, ME;

    if (data->N == 3) {
        // Виведення тексту про поточну функцію
        pthread_mutex_lock(&data->inputMutex);
        std::cout << "\nВведення F3:\n";
        pthread_mutex_unlock(&data->inputMutex);

        // Введення даних з клавіатури
        B = data->getVectorFromConsole("B");
        C = data->getVectorFromConsole("C");
        MA = data->getMatrixFromConsole("MA");
        ME = data->getMatrixFromConsole("ME");
    } else {
        // Генерація випадкових даних
        B = data->generateRandomVector();
        C = data->generateRandomVector();
        MA = data->generateRandomMatrix();
        ME = data->generateRandomMatrix();
    }

    // Обчислення F3
    std::vector<double> result = data->multiplyMatrixVector(
        data->multiplyMatrices(MA, ME),
        data->sortVector(B)
    );
    
    // Виведення результату
    data->printVector("O", result);
} 