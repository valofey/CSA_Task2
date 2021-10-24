#ifndef __triangleMatrix__
#define __triangleMatrix__

#include <fstream>
#include "Matrix.h"

class TriangleMatrix : public Matrix {
 private:
    int dim_;
    double *triangleMatrix_;

 public:
    explicit TriangleMatrix(int length);

    void out(std::ofstream &ofStream) override;

    void inRandom() override;

    double getAverage() override;

    void in(std::ifstream &ifStream) override;
};

#endif