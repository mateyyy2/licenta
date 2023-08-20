//
// Created by Matei on 11/08/2023.
//

#include "BigFibonacci.h"

using namespace std;

//class BigInt {
//    friend ostream& operator<< (ostream& os, const BigInt& ins_i);
//
//
//};

Fibonacci::Fibonacci(unsigned int n) { getNumber(n); }
Fibonacci::~Fibonacci() {}

BigInt Fibonacci::getNumber(unsigned int n) {
    fibs.reserve(n + 1);
    const unsigned int cur_size = fibs.size();

    for(unsigned int i = cur_size; i <= n; i++) {
        switch(i) {
            case 0:
                fibs.push_back(BigInt(0));
                break;
            case 1:
                if(fibs.empty()) fibs.push_back(BigInt(0));
                fibs.push_back(BigInt(1));
                break;
            default:
                fibs.push_back(BigInt(getNumber(i - 2), getNumber(i - 1)));
                break;
        }
    }

    assert(n < fibs.size());

    return fibs[n];
}

void Fibonacci::showNumber(unsigned long n) {
    ostringstream oss;

    if(!(n < fibs.size())) getNumber(n);

    oss << "Fib [" << n << "] = " << fibs[n] << endl;

    cout << oss.str();
}

inline ostream& operator<< (ostream& os, const BigInt& big) {
    assert(!big.units.empty());

    for(unsigned long i = (big.units.size() - 1); i; --i) {
        os << big.units[i] << setw(BASE1 - 1) << setfill('0');
    }

    return os << big.units[0];
}

//unsigned long BigInt::head_s (0);