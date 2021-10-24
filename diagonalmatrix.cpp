#include "diagonalmatrix.h"
#include "rnd.h"
#include <iostream>
#include <fstream>

DiagonalMatrix::DiagonalMatrix(int length) : Matrix(length) {
    diagonal_ = nullptr;
}

void DiagonalMatrix::out(std::ofstream &ofStream) {
    ofStream << "Diagonal matrix with dimension = " << length_ << "\n";
    for (int i = 0; i < length_; ++i) {
        for (int j = 0; j < length_; ++j) {
            if (i == j) {
                ofStream << diagonal_[i] << " ";
            } else {
                ofStream << 0 << " ";
            }
        }
        ofStream << "\n";
    }
    ofStream << "Average = " << this->getAverage() << "\n" << std::endl;
}

double DiagonalMatrix::getAverage() {
    double sum = 0.0;

    for (int i = 0; i < length_; ++i) {
        sum += diagonal_[i];
    }
    return sum / (length_ * length_);
}

void DiagonalMatrix::in(std::ifstream &ifStream) {
    diagonal_ = new double[length_];

    for (int i = 0; i < length_; ++i) {
        ifStream >> diagonal_[i];
    }
}

void DiagonalMatrix::inRandom() {
    diagonal_ = new double[length_];

    Random random = Random(-10, 20);
    for (int i = 0; i < length_; ++i) {
        diagonal_[i] = random.getRandom();
    }
}
