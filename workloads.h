//
// Created by Matei on 05/09/2023.
//

#ifndef PROJECT_CLION_WORKLOADS_H
#define PROJECT_CLION_WORKLOADS_H

#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <chrono>
#include <iomanip>

#include "Fibonacci.h"
#include "BigInt.h"

//class Workloads {
//private:
//    void computeFibWithTimer();
//
//
//};

void computeFibToN(const int n, bool lastPrint);
void stressTestAllCore(const int n);
void benchmarkSingleCore(const int n);

#endif //PROJECT_CLION_WORKLOADS_H
