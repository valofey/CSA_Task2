#ifndef __container__
#define __container__
#define MAX_LENGTH 10000

#include "Matrix.h"

class Container {
 private:

    Matrix *container_[MAX_LENGTH];

 public:
    int length_;

    Container();

    ~Container();

    void in(std::ifstream &ifStream);

    void inRandom(int size);

    void out(std::ofstream &ofStream);

    void mergeSort(int, int);

    void merge(int,int,int);
};

#endif
