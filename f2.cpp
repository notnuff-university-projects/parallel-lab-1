#include "f2.h"
#include <iostream>

F2::F2(Data* data) : data(data) {}

void F2::execute() {
    // Генерація або введення матриць
    std::vector<std::vector<double>> MA, MG, MZ, ML;

    if (data->N == 3) {
        // Введення з клавіатури для малих розмірів
        MA = data->getMatrixFromConsole("MA");
        MG = data->getMatrixFromConsole("MG");
        MZ = data->getMatrixFromConsole("MZ");
        ML = data->getMatrixFromConsole("ML");
    } else {
        // Випадкова генерація для великих розмірів
        MA = data->generateRandomMatrix();
        MG = data->generateRandomMatrix();
        MZ = data->generateRandomMatrix();
        ML = data->generateRandomMatrix();
    }

    // F2: MK = MA*(MG*MZ) + TRANS(ML)
    auto MGMZ = data->multiplyMatrices(MG, MZ);
    auto MA_MGMZ = data->multiplyMatrices(MA, MGMZ);
    auto ML_TRANS = data->transposeMatrix(ML);

    // Результат - матриця
    result = std::vector<std::vector<double>>(data->N, std::vector<double>(data->N));
    for (int i = 0; i < data->N; ++i) {
        for (int j = 0; j < data->N; ++j) {
            result[i][j] = MA_MGMZ[i][j] + ML_TRANS[i][j];
        }
    }

    // Виведення результату
    std::cout << "\nРезультат F2 (матриця MK):\n";
    for (int i = 0; i < data->N; ++i) {
        for (int j = 0; j < data->N; ++j) {
            std::cout << "MK[" << i << "][" << j << "] = " << result[i][j] << "\t";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
} 