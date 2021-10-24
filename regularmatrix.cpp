#include <iostream>
#include "regularmatrix.h"
#include "rnd.h"

RegularMatrix::RegularMatrix(int length) : Matrix(length) {
    matrix_ = nullptr;
}

double RegularMatrix::getAverage() {
    double sum = 0.0;

    for (int i = 0; i < length_; ++i) {
        for (int j = 0; j < length_; ++j) {
            sum += matrix_[i][j];
        }
    }
    return sum / (length_ * length_);
}


void RegularMatrix::out(std::ofstream &ofStream) {
    ofStream << "Regular matrix with dimension = " << length_ << "\n";
    for (int i = 0; i < length_; ++i) {
        for (int j = 0; j < length_; ++j) {
            ofStream << matrix_[i][j] << " ";
        }
        ofStream << "\n";
    }
    ofStream << "Average = " << this->getAverage() << "\n" << std::endl;
}

void RegularMatrix::in(std::ifstream &ifStream) {
    matrix_ = new double *[length_];

    for (int i = 0; i < length_; ++i) {
        matrix_[i] = new double[length_];
        for (int j = 0; j < length_; ++j) {
            ifStream >> matrix_[i][j];
        }
    }
}

void RegularMatrix::inRandom() {
    matrix_ = new double *[length_];

    Random random = Random(-10, 20);
    for (int i = 0; i < length_; ++i) {
        matrix_[i] = new double[length_];
        for (int j = 0; j < length_; ++j) {
            matrix_[i][j] = random.getRandom();
        }
    }
}
