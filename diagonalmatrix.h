#ifndef __diagonalMatrix__
#define __diagonalMatrix__

#include "Matrix.h"

// Диагональная матрица.
class DiagonalMatrix : public Matrix {
 private:
    double *diagonal_;

 public:
    explicit DiagonalMatrix(int length);

    void in(std::ifstream &ifStream) override;

    void inRandom() override;

    void out(std::ofstream &ofStream) override;

    double getAverage() override;
};

#endif
