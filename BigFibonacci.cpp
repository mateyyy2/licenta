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

//Fibonacci::Fibonacci(unsigned int n) { getNumber(n); }
//Fibonacci::~Fibonacci() {}
//
//BigInt Fibonacci::getNumber(unsigned int n) {
//    fibs.reserve(n + 1);
//    const unsigned int cur_size = fibs.size();
//
//    for(unsigned int i = cur_size; i <= n; i++) {
//        switch(i) {
//            case 0:
//                fibs.push_back(BigInt(0));
//                break;
//            case 1:
//                if(fibs.empty()) fibs.push_back(BigInt(0));
//                fibs.push_back(BigInt(1));
//                break;
//            default:
//                fibs.push_back(BigInt(getNumber(i - 2), getNumber(i - 1)));
//                break;
//        }
//    }
//
//    assert(n < fibs.size());
//
//    return fibs[n];
//}
//
//void Fibonacci::showNumber(unsigned long n) {
//    ostringstream oss;
//
//    if(!(n < fibs.size())) getNumber(n);
//
//    oss << "Fib [" << n << "] = " << fibs[n] << endl;
//
//    cout << oss.str();
//}
//
//inline ostream& operator<< (ostream& os, const BigInt& big) {
//    assert(!big.digits.empty());
//
//    for(unsigned long i = (big.digits.size() - 1); i; --i) {
//        os << big.digits[i] << setw(BASE1 - 1) << setfill('0');
//    }
//
//    return os << big.digits[0];
//}

//unsigned long BigInt::head_s (0);



Fibonacci::Fibonacci(unsigned int n) { getFib(n); }
Fibonacci::~Fibonacci() {}

BigInt Fibonacci::getFib(unsigned int n) {
    //fibs.reserve(n + 1);
    const unsigned int currSize = fibs.size();

    for(unsigned int i = currSize; i <= n; i++) {
        switch(i) {
            case 0:
                fibs.push_back(BigInt(0, 1));
                break;
            case 1:
                if(fibs.empty()) { fibs.push_back(BigInt(0, 1)); }
                fibs.push_back(BigInt(1, 1));
                break;
            default:
                // TODO: push_back BigInt(i - 1) + BigInt(i - 2)
                int newSize = fibs[i - 1].getSize() + 1;
                //BigInt sum = BigInt((fibs[i - 1] + fibs[i - 2]), 1000);
                BigInt sum = BigInt(0, newSize);
                sum += fibs[i - 1];
                sum += fibs[i - 2];
                fibs.push_back(sum);
                break;
        }
    }

    return fibs[n];
}

void Fibonacci::showFib(unsigned int n) {
    if(!(n < fibs.size())) getFib(n);

    fibs[n].print();
}