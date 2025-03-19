#include "data.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <limits>
#include <pthread.h>

Data::Data(Mode m) : mode(m), gen(rd()), dis(-100.0, 100.0), outputReady(false) {
    if (mode == Mode::SmallNum) {
        N = 3;
    } else if (mode == Mode::BigNum) {
        N = 1000;
    }
    // Ініціалізація мютексів та умовної змінної
    pthread_mutex_init(&inputMutex, nullptr);
    pthread_mutex_init(&outputMutex, nullptr);
    pthread_cond_init(&outputCondition, nullptr);
}

Data::~Data() {
    // Звільнення мютексів та умовної змінної
    pthread_mutex_destroy(&inputMutex);
    pthread_mutex_destroy(&outputMutex);
    pthread_cond_destroy(&outputCondition);
}

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

std::vector<double> Data::getVectorFromConsole(const std::string& vectorName) const {
    std::vector<double> result(N);
    
    // Захоплення мютексу перед введенням
    pthread_mutex_lock(&inputMutex);
    
    for (int i = 0; i < N; i++) {
        std::cout << "Введіть елемент " << vectorName << "[" << i << "]: ";
        while (!(std::cin >> result[i])) {
            std::cout << "Помилка! Введіть число: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    // Звільнення мютексу після введення
    pthread_mutex_unlock(&inputMutex);
    
    return result;
}

std::vector<std::vector<double>> Data::getMatrixFromConsole(const std::string& matrixName) const {
    std::vector<std::vector<double>> result(N, std::vector<double>(N));
    
    // Захоплення мютексу перед введенням
    pthread_mutex_lock(&inputMutex);
    
    for (int i = 0; i < N; i++) {
        std::cout << "\nВведення рядка " << matrixName << "[" << i << "]:\n";
        for (int j = 0; j < N; j++) {
            std::cout << "Введіть елемент " << matrixName << "[" << i << "][" << j << "]: ";
            while (!(std::cin >> result[i][j])) {
                std::cout << "Помилка! Введіть число: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    
    // Звільнення мютексу після введення
    pthread_mutex_unlock(&inputMutex);
    
    return result;
}

void Data::printVector(const std::string& vectorName, const std::vector<double>& vec) const {
    pthread_mutex_lock(&outputMutex);
    std::cout << "\nРезультат " << vectorName << ":\n";
    for (int i = 0; i < N; i++) {
        std::cout << vectorName << "[" << i << "] = " << vec[i] << "\n";
    }
    outputReady = true;
    pthread_cond_signal(&outputCondition);
    pthread_mutex_unlock(&outputMutex);
}

void Data::printMatrix(const std::string& matrixName, const std::vector<std::vector<double>>& matrix) const {
    pthread_mutex_lock(&outputMutex);
    std::cout << "\nРезультат " << matrixName << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrixName << "[" << i << "][" << j << "] = " << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    outputReady = true;
    pthread_cond_signal(&outputCondition);
    pthread_mutex_unlock(&outputMutex);
}

void Data::waitForOutput() const {
    pthread_mutex_lock(&outputMutex);
    while (!outputReady) {
        pthread_cond_wait(&outputCondition, &outputMutex);
    }
    outputReady = false;
    pthread_mutex_unlock(&outputMutex);
}

