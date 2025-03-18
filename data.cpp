#include "data.h"

#include <algorithm>
#include <iostream>
#include <random>

Data::Data(Mode m) : mode(m), gen(rd()), dis(-100.0, 100.0) {
    if (mode == Mode::SmallNum) {
        N = 3;
    } else if (mode == Mode::BigNum) {
        N = 1000;
    }
}

Data::~Data() = default;

// Скалярний добуток двох векторів
double Data::vectorDotProduct(const std::vector<double>& a, const std::vector<double>& b) {
    double result = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }
    return result;
}

// Добуток двох матриць
std::vector<std::vector<double>> Data::multiplyMatrices(
    const std::vector<std::vector<double>>& a, 
    const std::vector<std::vector<double>>& b) {
    
    std::vector<std::vector<double>> result(N, std::vector<double>(N, 0.0));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

// Добуток вектора на матрицю
std::vector<double> Data::multiplyMatrixVector(
    const std::vector<std::vector<double>>& matrix, 
    const std::vector<double>& vec) {
    
    std::vector<double> result(N, 0.0);
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}

// Транспонування матриці
std::vector<std::vector<double>> Data::transposeMatrix(
    const std::vector<std::vector<double>>& matrix) {
    
    std::vector<std::vector<double>> result(N, std::vector<double>(N));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

// Сортування вектора
std::vector<double> Data::sortVector(const std::vector<double>& vec) {
    std::vector<double> result = vec;
    std::sort(result.begin(), result.end());
    return result;
}

std::vector<double> Data::generateRandomVector() const {
    std::vector<double> vector(N);
    for (int i = 0; i < N; ++i) {
        vector[i] = dis(gen);
    }
    return vector;
}

std::vector<std::vector<double>> Data::generateRandomMatrix() const {
    std::vector<std::vector<double>> matrix(N, std::vector<double>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = dis(gen);
        }
    }
    return matrix;
}

