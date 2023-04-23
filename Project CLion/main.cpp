#include <iostream>
#include <cmath>
#include <complex>
#include <vector>

#include <unistd.h>
#include <cpuid.h>

using namespace std;


int getThreadCount() {
    //return sysconf(_SC_NPROCESSORS_ONLN);

    unsigned int eax, ebx, ecx, edx;
    eax = 1;

    __get_cpuid(eax, &eax, &ebx, &ecx, &edx);

    return (ebx >> 17) & 0xff;
}

vector<complex<double>> DFT(vector<complex<double>> X) { // qubytes
    // number of samples
    int N = X.size();
    int K = N;

    // allocate memory for internals
    complex<double> intSum;

    // allocate memory for output
    vector<complex<double>> output;
    output.reserve(K);

    // loop through each k
    for(int k = 0; k < K; k++) {
        // loop through each n
        for(int n = 0; n < N; n++) {
            double realPart = cos(((2 * M_PI) / N) * k * n);
            double imagPart = sin(((2 * M_PI) / N) * k * n);

            complex<double> w (realPart, -imagPart);
            intSum += X[n] * w;
        }

        output.push_back(intSum);
    }

    return output;
}

int main() {
    cout << getThreadCount();

    return 0;
}