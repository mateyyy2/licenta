//
// Created by Matei on 18/08/2023.
//

#ifndef PROJECT_CLION_BIGINT_H
#define PROJECT_CLION_BIGINT_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <iomanip>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

#define MAX_UNIT_VALUE (ULONG_MAX >> 2)
#define BASE1 10
#define BASE2 1000000000

//using namespace std;

class BigInt {
    friend std::ostream& operator<< (std::ostream& os, const BigInt& big);

private:
    static unsigned long carry;
    std::vector<unsigned long> units;

public:
    BigInt(unsigned long unit);
    BigInt(BigInt big1, BigInt big2);

    unsigned long operator() (const unsigned long n1, const unsigned long n2);

};

//inline ostream& operator<< (ostream& os, const BigInt& ins_i);



#endif //PROJECT_CLION_BIGINT_H
