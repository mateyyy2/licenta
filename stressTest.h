//
// Created by Matei on 16/08/2023.
//

#ifndef PROJECT_CLION_STRESSTEST_H
#define PROJECT_CLION_STRESSTEST_H

#include <thread>
#include <vector>
#include <atomic>
#include <iostream>

#include "BigFibonacci.h"
#include "MillerRabin.h"
#include "FFT.h"

void fibonacciStartEnd(Fibonacci& fib, int start, int end);
void stressTest();

#endif //PROJECT_CLION_STRESSTEST_H
