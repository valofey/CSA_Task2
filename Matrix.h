#ifndef __matrix__
#define __matrix__

#include <iosfwd>

class Matrix {
 protected:
    int length_;
 public:
    explicit Matrix(int length);

    virtual ~Matrix() = default;

    static Matrix *staticIn(std::ifstream &ifStream);

    static Matrix *staticInRandom();

    virtual void in(std::ifstream &ifStream) = 0;

    virtual void inRandom() = 0;

    virtual void out(std::ofstream &ofStream) = 0;

    virtual double getAverage() = 0;
};

#endif
