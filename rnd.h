#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <ctime>

class Random {
 public:
    Random(double first, double last) {
        if (first <= last) {
            _first = first;
            _last = last;
        } else {
            _first = last;
            _last = first;
        }
         srand(static_cast<unsigned int>(time(0)));
    }

    // Get random floating point number from first to last
    inline double getRandom() {
        auto range = static_cast<double>(_last - _first);
        double div = RAND_MAX / range;
        return _first + (rand() / div);
    }

    static inline int getRandomDimension() {
        return rand() % 20 + 1;
    }

    static inline int getRandomType() {
        return rand() % 3 + 1;
    }

 private:
    double _first;
    double _last;
};

#endif
