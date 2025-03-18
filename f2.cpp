#include "f2.h"

F2::F2(Data* data) : data(data) {}

void F2::execute() {
    // Генерація матриць
    std::vector<std::vector<double>> MA = data->generateRandomMatrix();
    std::vector<std::vector<double>> MG = data->generateRandomMatrix();
    std::vector<std::vector<double>> MZ = data->generateRandomMatrix();
    std::vector<std::vector<double>> ML = data->generateRandomMatrix();

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
} 