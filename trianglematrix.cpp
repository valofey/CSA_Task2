#include "trianglematrix.h"
#include "rnd.h"


TriangleMatrix::TriangleMatrix(int length) : Matrix(length) {
    triangleMatrix_ = nullptr;
    dim_ = 0;
}

void TriangleMatrix::out(std::ofstream &ofStream) {
    ofStream << "Triangle matrix with dimension = " << length_ << "\n";
    for (int i = 0; i < length_; ++i) {
        for (int j = 0; j < length_; ++j) {
            if (j > i) {
                ofStream << 0 << " ";
            } else {
                int pos = (length_ * i) + j - ((i * (i + 1)) / 2);
                ofStream << triangleMatrix_[pos] << " ";
            }
        }
        ofStream << "\n";
    }
    ofStream << "Average = " << this->getAverage() << std::endl;
}

void TriangleMatrix::inRandom() {
    dim_ = length_ * (length_ + 1) / 2;
    triangleMatrix_ = new double[dim_];

    Random random = Random(-10, 20);
    for (int i = 0; i < dim_; ++i) {
        triangleMatrix_[i] = random.getRandom();
    }
}

double TriangleMatrix::getAverage() {
    double sum = 0.0;

    for (int i = 0; i < length_; ++i) {
        sum += triangleMatrix_[i];
    }
    return sum / (length_ * length_);
}

void TriangleMatrix::in(std::ifstream &ifStream) {
    dim_ = length_ * (length_ + 1) / 2;
    triangleMatrix_ = new double[dim_];

    for (int i = 0; i < dim_; ++i) {
        ifStream >> triangleMatrix_[i];
    }
}
