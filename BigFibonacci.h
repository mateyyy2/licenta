//
// Created by Matei on 11/08/2023.
//

#ifndef PROJECT_CLION_BIGFIBONACCI_H
#define PROJECT_CLION_BIGFIBONACCI_H

#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <iostream>

#include "BigInt.h"

#define MAX(x,y) ((x) > (y) ? (x) : (y))

#define MAX_UNIT_VALUE (ULONG_MAX >> 2)
#define BASE1 10
#define BASE2 1000000000

using namespace std;

inline ostream& operator<< (ostream& os, const BigInt& ins_i);

class Fibonacci {
private:
    vector<BigInt> fibs_;
    BigInt get_number(unsigned int n_i = 0);

public:
    void show_number(unsigned long n_i);

    Fibonacci(unsigned int n_i = 0) { get_number(n_i); }
    ~Fibonacci() {}
};

#endif //PROJECT_CLION_BIGFIBONACCI_H
