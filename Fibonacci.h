//
// Created by Matei on 11/08/2023.
//

#ifndef PROJECT_CLION_FIBONACCI_H
#define PROJECT_CLION_FIBONACCI_H

#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <iostream>

#include "BigInt.h"

//#define MAX(x,y) ((x) > (y) ? (x) : (y))
//
//#define MAX_UNIT_VALUE (ULONG_MAX >> 2)
//#define BASE1 10
//#define BASE2 1000000000

//using namespace std;

//inline std::ostream& operator<< (std::ostream& os, const BigInt& big);
//
//class Fibonacci {
//private:
//    std::vector<BigInt> fibs;
//
//public:
//    BigInt getNumber(unsigned int n = 0);
//    void showNumber(unsigned long n);
//
//    Fibonacci(unsigned int n = 0);
//    ~Fibonacci();
    //Fibonacci(unsigned int n = 0) { get_number(n); }
    //~Fibonacci() {}
//};

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
