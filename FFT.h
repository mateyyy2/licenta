//
// Created by Matei on 18/07/2023.
//

#ifndef PROJECT_CLION_FFT_H
#define PROJECT_CLION_FFT_H

#include <iostream>
#include <complex>
#include <cmath>
#include <vector>

using namespace std;

const double PI = acos(-1);

void computeFFTRecursive(vector<complex<double>>& input, bool inverted);

#endif //PROJECT_CLION_FFT_H
