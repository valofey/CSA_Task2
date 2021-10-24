#ifndef __regularMatrix__
#define __regularMatrix__

#include <fstream>
#include "Matrix.h"

class RegularMatrix : public Matrix {
 private:
    double **matrix_;

 public:
    explicit RegularMatrix(int length);

    void in(std::ifstream &ifStream) override;

    void inRandom() override;

    void out(std::ofstream &ofStream) override;

    double getAverage() override;
};

#endif