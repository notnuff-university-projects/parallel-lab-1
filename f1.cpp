#include "f1.h"
#include <iostream>

F1::F1(Data* data) : TThread(), data(data) {}

void F1::execute() {
    // Генерація або введення векторів та матриць
    std::vector<double> B, C, A;
    std::vector<std::vector<double>> MA, ME;

    if (data->N == 3) {
        // Виведення тексту про поточну функцію
        pthread_mutex_lock(&data->inputMutex);
        std::cout << "\nВведення F1:\n";
        pthread_mutex_unlock(&data->inputMutex);

        // Введення з клавіатури для малих розмірів
        B = data->getVectorFromConsole("B");
        C = data->getVectorFromConsole("C");
        A = data->getVectorFromConsole("A");
        MA = data->getMatrixFromConsole("MA");
        ME = data->getMatrixFromConsole("ME");
    } else {
        // Випадкова генерація для великих розмірів
        B = data->generateRandomVector();
        C = data->generateRandomVector();
        A = data->generateRandomVector();
        MA = data->generateRandomMatrix();
        ME = data->generateRandomMatrix();
    }

    // F1: d = (B*C) + (A*B) +(C*(B*(MA*ME)))
    double BC = data->vectorDotProduct(B, C);
    double AB = data->vectorDotProduct(A, B);
    
    auto MA_ME = data->multiplyMatrices(MA, ME);
    auto B_MA_ME = data->multiplyMatrixVector(MA_ME, B);
    double C_B_MA_ME = data->vectorDotProduct(C, B_MA_ME);

    double result = BC + AB + C_B_MA_ME;

    // Виведення результату
    pthread_mutex_lock(&data->outputMutex);
    std::cout << "\nРезультат F1 (скаляр d):\n";
    std::cout << "d = " << result << "\n";
    data->outputReady = true;
    pthread_cond_signal(&data->outputCondition);
    pthread_mutex_unlock(&data->outputMutex);
}
