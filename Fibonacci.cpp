//
// Created by Matei on 11/08/2023.
//

#include "Fibonacci.h"

using namespace std;

Fibonacci::Fibonacci(unsigned int n) { getFib(n); }
Fibonacci::~Fibonacci() {}

//BigInt Fibonacci::getFib(unsigned int n) {
//    //fibs.reserve(n + 1);
//    const unsigned int currSize = fibs.size();
//
//    for(unsigned int i = currSize; i <= n; i++) {
//        switch(i) {
//            case 0:
//                fibs.push_back(BigInt(0, 1));
//                break;
//            case 1:
//                if(fibs.empty()) { fibs.push_back(BigInt(0, 1)); }
//                fibs.push_back(BigInt(1, 1));
//                break;
//            default:
//                // TODO: push_back BigInt(i - 1) + BigInt(i - 2)
//                int newSize = fibs[i - 1].getSize() + 1;
//                //BigInt sum = BigInt((fibs[i - 1] + fibs[i - 2]), 1000);
//                BigInt sum = BigInt(0, newSize);
//                sum += fibs[i - 1];
//                sum += fibs[i - 2];
//                fibs.push_back(sum);
//                break;
//        }
//        // debug
//        cout << "Computed fib(" << i << ") = ";
//        fibs[i].print();
//    }
//
//    return fibs[n];
//}

BigInt Fibonacci::getFib(unsigned int n) {
    fibs.reserve(n + 1);
    //int theoreticalSize;

    for(unsigned int i = fibs.size(); i <= n; i++) {
        //theoreticalSize = ceil(i * 0.209);
        switch(i) {
            case 0:
                fibs.push_back(BigInt(0, 2090));
                //fibs.push_back(BigInt(0, theoreticalSize));
                break;
            case 1:
                if(fibs.empty()) { fibs.push_back(BigInt(0, 2090)); }
                fibs.push_back(BigInt(1, 2090));
                //if(fibs.empty()) { fibs.push_back(BigInt(0, theoreticalSize)); }
                //fibs.push_back(BigInt(1, theoreticalSize));
                break;
            default:
                BigInt a = BigInt(0, fibs[i - 1].getSize() + 1);
                //BigInt a = BigInt(0, theoreticalSize);
                a = fibs[i - 1] + fibs[i - 2];
                fibs.push_back(a);
                break;
        }
    }

    return fibs[n];
}

void Fibonacci::showFib(unsigned int n) {
    if(!(n < fibs.size())) getFib(n);

    fibs[n].print();
}