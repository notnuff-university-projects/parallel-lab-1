#ifndef DATA_H
#define DATA_H

#include <vector>
#include <random>
#include <string>

enum class Mode {
    SmallNum,  // N = 3
    BigNum     // N = 1000
};

class Data {
public:
    Data(Mode m);
    ~Data();

    // Службові функції для роботи з векторами та матрицями
    double vectorDotProduct(const std::vector<double>& a, const std::vector<double>& b);
    std::vector<std::vector<double>> multiplyMatrices(const std::vector<std::vector<double>>& a, const std::vector<std::vector<double>>& b);
    std::vector<double> multiplyMatrixVector(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vec);
    std::vector<std::vector<double>> transposeMatrix(const std::vector<std::vector<double>>& matrix);
    std::vector<double> sortVector(const std::vector<double>& vec);


    std::vector<double> getVector() const;
    std::vector<std::vector<double>> getMatrix() const;

    // Функції для генерації випадкових даних
    std::vector<double> generateRandomVector() const;
    std::vector<std::vector<double>> generateRandomMatrix() const;

    // Функції для введення даних з клавіатури
    std::vector<double> getVectorFromConsole(const std::string& vectorName) const;
    std::vector<std::vector<double>> getMatrixFromConsole(const std::string& matrixName) const;

    Mode mode;
    int N;  // Розмір векторів та матриць

private:
    // Генератор випадкових чисел
    mutable std::random_device rd;
    mutable std::mt19937 gen;
    mutable std::uniform_real_distribution<double> dis;
};

#endif //DATA_H
