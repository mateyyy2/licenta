//
// Created by Matei on 11/08/2023.
//

#ifndef PROJECT_CLION_FIBONACCI_H
#define PROJECT_CLION_FIBONACCI_H

#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cmath>

#include "BigInt.h"

class Fibonacci {
private:
    std::vector<BigInt> fibs;

public:
    Fibonacci(unsigned int n = 0);
    ~Fibonacci();

    BigInt getFib(unsigned int n = 0);
    void showFib(unsigned int n);
};

#endif //PROJECT_CLION_FIBONACCI_H
