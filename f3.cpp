#include "f3.h"

F3::F3(Data* data) : data(data) {}

void F3::execute() {
    // Генерація вектора та матриць
    std::vector<double> P = data->generateRandomVector();
    std::vector<std::vector<double>> MR = data->generateRandomMatrix();
    std::vector<std::vector<double>> MS = data->generateRandomMatrix();

    // F3: O = SORT(P)*(MR * MS)
    auto sorted_P = data->sortVector(P);
    auto MRMS = data->multiplyMatrices(MR, MS);
    result = data->multiplyMatrixVector(MRMS, sorted_P);
} 