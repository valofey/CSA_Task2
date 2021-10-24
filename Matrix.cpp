#include <iostream>
#include <fstream>
#include "Matrix.h"
#include "regularmatrix.h"
#include "diagonalmatrix.h"
#include "trianglematrix.h"
#include "rnd.h"

Matrix::Matrix(int length) {
    length_ = length;
}

Matrix *Matrix::staticIn(std::ifstream &ifStream) {
    int type;
    ifStream >> type;
    int length;
    ifStream >> length;
    Matrix *_matrix = nullptr;
    switch (type) {
        case 1:
            _matrix = new RegularMatrix(length);
            break;
        case 2:
            _matrix = new DiagonalMatrix(length);
            break;
        case 3:
            _matrix = new TriangleMatrix(length);
            break;
    }
    _matrix->in(ifStream);
    return _matrix;
}

Matrix *Matrix::staticInRandom() {
    int type = Random::getRandomType();
    int length = Random::getRandomDimension();

    Matrix *_matrix = nullptr;
    switch (type) {
        case 1:
            _matrix = new RegularMatrix(length);
            break;
        case 2:
            _matrix = new DiagonalMatrix(length);
            break;
        case 3:
            _matrix = new TriangleMatrix(length);
            break;
    }
    _matrix->inRandom();
    return _matrix;
}
