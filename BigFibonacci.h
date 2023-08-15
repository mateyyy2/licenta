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

#define MAX(x,y) ((x) > (y) ? (x) : (y))

#define MAX_UNIT_VALUE (ULONG_MAX >> 2)
#define BASE1 10
#define BASE2 1000000000

using namespace std;

class BigInt {
    friend ostream& operator<< (ostream& os, const BigInt& ins_i);

private:
    static unsigned long head_s;
    vector<unsigned long> units_;

public:
    BigInt(unsigned long unit_i);
    BigInt(BigInt big1_i, BigInt big2_i);
    unsigned long operator() (const unsigned long n1, const unsigned long n2);

};

inline ostream& operator<< (ostream& os, const BigInt& ins_i);


class Fibonacci {

};


#endif //PROJECT_CLION_BIGFIBONACCI_H
