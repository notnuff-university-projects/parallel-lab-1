#include "f3.h"

F3::F3(Data* data) : data(data) {}

void F3::execute() {
    // Генерація або введення вектора та матриць
    std::vector<double> P;
    std::vector<std::vector<double>> MR, MS;

    if (data->N == 3) {
        // Введення з клавіатури для малих розмірів
        P = data->getVectorFromConsole("P");
        MR = data->getMatrixFromConsole("MR");
        MS = data->getMatrixFromConsole("MS");
    } else {
        // Випадкова генерація для великих розмірів
        P = data->generateRandomVector();
        MR = data->generateRandomMatrix();
        MS = data->generateRandomMatrix();
    }

    // F3: O = SORT(P)*(MR * MS)
    auto sorted_P = data->sortVector(P);
    auto MRMS = data->multiplyMatrices(MR, MS);
    result = data->multiplyMatrixVector(MRMS, sorted_P);
} 