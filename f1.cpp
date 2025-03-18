#include "f1.h"

F1::F1(Data* data) : data(data) {}

void F1::execute() {
    // Генерація векторів та матриць
    std::vector<double> B = data->generateRandomVector();
    std::vector<double> C = data->generateRandomVector();
    std::vector<double> A = data->generateRandomVector();
    std::vector<std::vector<double>> MA = data->generateRandomMatrix();
    std::vector<std::vector<double>> ME = data->generateRandomMatrix();

    // F1: d = (B*C) + (A*B) +(C*(B*(MA*ME)))
    double BC = data->vectorDotProduct(B, C);
    double AB = data->vectorDotProduct(A, B);
    
    auto MA_ME = data->multiplyMatrices(MA, ME);
    auto B_MA_ME = data->multiplyMatrixVector(MA_ME, B);
    double C_B_MA_ME = data->vectorDotProduct(C, B_MA_ME);

    result = std::vector<double>(data->N);
    for (int i = 0; i < data->N; ++i) {
        result[i] = BC + AB + C_B_MA_ME;
    }
}
