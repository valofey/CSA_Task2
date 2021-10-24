#include <iostream>
#include <fstream>
#include "Container.h"
#include "Matrix.h"

Container::Container() : length_(0) {}

Container::~Container() {
    for (int i = 0; i < length_; ++i) {
        delete container_[i];
    }
    length_ = 0;
}

void Container::in(std::ifstream &ifStream) {
    while (!ifStream.eof()) {
        if ((container_[length_] = Matrix::staticIn(ifStream)) != nullptr) {
            ++length_;
        }
    }
}

void Container::inRandom(int size) {
    while (length_ < size) {
        if ((container_[length_] = Matrix::staticInRandom()) != nullptr) {
            length_++;
        }
    }
}

void Container::out(std::ofstream &ofStream) {
    ofStream << "Container contains " << length_ << " elements.\n" << std::endl;
    for (int i = 0; i < length_; i++) {
        ofStream << i << ": ";
        container_[i]->out(ofStream);
    }
}

void Container::mergeSort(int const begin, int const end) {
    if (begin >= end)
      return; // Рекурсия.
  
    auto mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid + 1, end);
    merge(begin, mid, end);
}

void Container::merge(int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    Matrix *leftArray [subArrayOne];
    Matrix *rightArray [subArrayTwo];
  
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = container_[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = container_[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, 
        indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]->getAverage() >= rightArray[indexOfSubArrayTwo]->getAverage()) {
            container_[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            container_[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        container_[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        container_[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

