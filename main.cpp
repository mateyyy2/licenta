#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <iomanip>

#include <chrono>
#include <thread>

#include <unistd.h>
#include <cpuid.h>

#include <omp.h>

#include "interface.h"
#include "BigFibonacci.h"
#include "MillerRabin.h"
#include "FFT.h"


using namespace std;

typedef vector<vector<vector<int>>> matrix;

// old
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
    complex<double> intSum = 0;

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







// new
//const double PI = acos(-1);

vector<complex<double>> computeDFT(const vector<complex<double>>& input) {
    int N = input.size();
    vector<complex<double>> output(N);

    for(int k = 0; k < N; k++) {
        complex<double> sum(0, 0);

        for(int n = 0; n < N; n++) {
            double angle = 2 * PI * k * n / N;

            complex<double> exp_term(cos(angle), -sin(angle));
            sum += input[n] * exp_term;
        }

        output[k] = sum;
    }

    return output;
}

//vector<complex<double>> computeDFT(const vector<complex<double>>& input) {
//    int N = input.size();
//    std::vector<std::complex<double>> output(N);
//
//    for (int k = 0; k < N; ++k) {
//        for (int n = 0; n < N; ++n) {
//            double theta = 2 * PI * n * k / N;
//            std::complex<double> W_n_k(std::cos(theta), -std::sin(theta));
//            output[k] += input[n] * W_n_k;
//        }
//    }
//
//    return output;
//}

//void computeFFTRecursive(vector<complex<double>>& input) {
//    int N = input.size();
//    //cout << "N = " << N << endl;
//    if(N <= 1) return;
//
//    // Divide
//    vector<complex<double>> even(N/2), odd(N/2);
//    for(int i = 0; i < N / 2; i++) {
//        even[i] = input[i * 2];
//        odd[i] = input[i * 2 + 1];
//    }
//
//    // Conquer
//    computeFFTRecursive(even);
//    computeFFTRecursive(odd);
//
//    // Combine
//    for(int k = 0; k < N / 2; k++) {
//        complex<double> t = polar(1.0, -2 * PI * k / N) * odd[k];
//
//        input[k] = even[k] + t;
//        input[k + N / 2] = even[k] - t;
//    }
//
//}
//    for(int i = 0; i < N; i++)
//        input[i] /= N;


//void computeFFTRecursive(vector<complex<double>>& input, double scale = 1.0) {
//    int N = input.size();
//    //cout << "N = " << N << endl;
//    if(N <= 1) return;
//
//    // Divide
//    vector<complex<double>> even(N/2), odd(N/2);
//    for(int i = 0; i < N / 2; i++) {
//        even[i] = input[i * 2];
//        odd[i] = input[i * 2 + 1];
//    }
//
//    // Conquer
//    computeFFTRecursive(even, scale * 2.0);
//    computeFFTRecursive(odd, scale * 2.0);
//
//    // Combine
//    for(int k = 0; k < N / 2; k++) {
//        complex<double> t = polar(1.0, -2 * PI * k / N) * odd[k];
//
//        input[k] = even[k] + t;
//        input[k + N / 2] = even[k] - t;
//    }
//
//    for(int i = 0; i < N; i++)
//        input[i] /= scale;
//}

// cp-algorithms FFT
void CP_FFT(vector<complex<double>>& input) {
    int N = input.size();
    if(N == 1) return;

    vector<complex<double>> even(N / 2), odd(N / 2);
    for(int i = 0; 2 * i < N; i++) {
        even[i] = input[2 * i];
        odd[i] = input[2 * i + 1];
    }

    CP_FFT(even);
    CP_FFT(odd);

    double angle = 2 * PI / N;
    complex<double> w(1), wn(cos(angle), sin(angle));

    for(int i = 0; i < N / 2; i++) {
        input[i] = even[i] + w * odd[i];
        input[i + N / 2] = even[i] - w * odd[i];

        w *= wn;
    }
}

//void computeFFTRecursive(vector<complex<double>>& input, bool inverted) {
//    int N = input.size();
//    if(N <= 1) return;
//
//    // Divide
//    vector<complex<double>> even(N / 2), odd(N / 2);
//    for(int i = 0; i < N / 2; i++) {
//        even[i] = input[i * 2];
//        odd[i] = input[i * 2 + 1];
//    }
//
//    // Conquer
//    computeFFTRecursive(even, inverted);
//    computeFFTRecursive(odd, inverted);
//
//    // Combine
//    double angle = 2 * PI / N * (inverted ? -1 : 1);
//    complex<double> w(1), wn(cos(angle), sin(angle));
//
//    for(int k = 0; k < N / 2; k++) {
//        input[k] = even[k] + w * odd[k];
//        input[k + N / 2] = even[k] - w * odd[k];
//
//        if(inverted) {
//            input[k] /= 2;
//            input[k + N / 2] /= 2;
//        }
//
//        w *= wn;
//    }
//}

//vector<int> multiplyPolynomialsFFT(vector<int> const& A, vector<int> const& B) {
//    int N = 1;
//    // cea mai mica putere a lui 2 > (A.size + B.size - 1)
//    while(N < (A.size() + B.size()))
//        N <<= 1;
//
//    vector<complex<double>> FA(A.begin(), A.end());
//    vector<complex<double>> FB(B.begin(), B.end());
//    //A.resize(N);
//    FA.resize(N);
//    FB.resize(N);
//
//    // evaluam polinoamele
//    computeFFTRecursive(FA, false);
//    computeFFTRecursive(FB, false);
//
//    // multiplicam polinoamele
//    for(int i = 0; i < N; i++)
//        FA[i] *= FB[i];
//
//    // aplicam inverse FFT pentru a afla coeficientii
//    //                              converti produsul pointwise in coeficienti
//    computeFFTRecursive(FA, true);
//
//    // rotunjim coeficientii la int (erori pt complex)
//    vector<int> result(N);
//    for(int i = 0; i < N; i++)
//        result[i] = round(FA[i].real());
//
//    return result;
//}

//vector<long long> multiplyLargeNumbersFFT(const vector<long long>& a, const vector<long long>& b) {
//
//}

//vector<int> addPolynomials(vector<int>& A, vector<int>& B) {
//    vector<int> result(max(B.size(), B.size()));
//
//    for(int i = 0; i < A.size(); i++) {
//        result[i] += A[i];
//    }
//    for(int i = 0; i < B.size(); i++) {
//        result[i] += B[i];
//    }
//
//    return result;
//}
//
//matrix multiplyMatrix(matrix &A, matrix &B) {
//    int n = A.size();
//
//}

//void computeFFTRecursive_helper(vector<complex<double>>& input, int N, int s) {
//    if(N <= 1) return;
//
//    // Divide
//    vector<complex<double>> even(N/2), odd(N/2);
//    for(int i = 0; i < N / 2; i++) {
//        even[i] = input[i * 2 * s];
//        odd[i] = input[(i * 2 + 1) * s];
//    }
//
//    // Conquer
//    computeFFTRecursive_helper(even, N / 2, s * 2);
//    computeFFTRecursive_helper(odd, N / 2, s * 2);
//
//    // Combine
//    for(int k = 0; k < N / 2; k++) {
//        complex<double> t = polar(1.0, -2 * PI * k / N) * odd[k];
//
//        input[k * s] = even[k] + t;
//        input[(k + N / 2) * s] = even[k] - t;
//    }
//}
//
//vector<complex<double>> computeFFTRecursive(vector<complex<double>> input) {
//    int N = input.size();
//
//    // ensure that N is a power of 2
//    int powerOfTwo = 1;
//    while(powerOfTwo < N) powerOfTwo *= 2;
//    input.resize(powerOfTwo);
//
//    computeFFTRecursive_helper(input, powerOfTwo, 1);
//
//    for(int i = 0; i < powerOfTwo; i++) {
//        input[i] /= powerOfTwo;
//    }
//
//    return input;
//}

// Fibonacci

// Function to add two large numbers represented as vectors
vector<int> add(const vector<int>& a, const vector<int>& b) {
    vector<int> result(max(a.size(), b.size()));
    int carry = 0;
    for (int i = 0; i < result.size(); i++) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        result[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry) result.push_back(carry);
    return result;
}

// Function to multiply a large number (represented as a vector) by a small number
vector<int> multiply(const vector<int>& a, int b) {
    vector<int> result(a.size());
    int carry = 0;
    for (int i = 0; i < a.size(); i++) {
        int product = a[i] * b + carry;
        result[i] = product % 10;
        carry = product / 10;
    }
    if (carry) result.push_back(carry);
    return result;
}

vector<int> fib(int N)
{
    vector<vector<int>> F1(N+1);
    F1[1] = {1};
    F1[2] = {1};

    for (int i = 3; i <= N; i++) {
        F1[i] = add(F1[i-1], F1[i-2]);
    }

    return F1[N];
}

vector<int> fibOMP(int N) {
    vector<vector<int>> F1(N+1);
    F1[1] = {1};
    F1[2] = {1};

#pragma omp parallel
    {
#pragma omp single
        {
            for (int i = 3; i <= N; i++) {
#pragma omp task firstprivate(i)
                {
                    F1[i] = add(F1[i-1], F1[i-2]);
                }
            }
        }
    }
#pragma omp taskwait

    return F1[N];
}






std::vector<std::complex<double>> generateSinusoidalData(int size, double frequency) {
    std::vector<std::complex<double>> data(size);
    for (int i = 0; i < size; ++i) {
        double t = (double)i / size;
        double value = std::sin(2 * M_PI * frequency * t);
        data[i] = std::complex<double>(value, 0);
    }
    return data;
}

void workload() {
    vector<complex<double>> test = {
            {1, 0}, {1, 1}, {0, 1}, {-1, 1},
            {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
    };

    std::vector<int> datasetSizes = {1024, 2048, 4096};//, 8192, 16384, 32768};
    std::vector<double> frequencies = {10.5, 20.25, 40.75, 82.125};

    for(int size : datasetSizes) {
        for(double freq : frequencies) {
            vector<complex<double>> data = generateSinusoidalData(size, freq);

            computeFFTRecursive(data, false);

            cout << endl << "FFT Results: " << endl;
            for (const auto &val: data) {
                cout << val << endl;
            }

            computeFFTRecursive(data, true);
            cout << endl << "Inverted FFT Results: " << endl;
            for (const auto &val: data) {
                cout << val << endl;
            }
        }
    }

    for(int iterations = 0; iterations < 1000; iterations++) {
        computeFFTRecursive(test, false);

        cout << endl << "FFT Results: " << endl;
        for (const auto &val: test) {
            cout << val << endl;
        }

        computeFFTRecursive(test, true);
        cout << endl << "Inverted FFT Results: " << endl;
        for (const auto &val: test) {
            cout << val << endl;
        }
    }
}

int main() {
    //cout << getThreadCount() << endl;

    vector<complex<double>> input = {
            {1, 0}, {1, 1}, {0, 1}, {-1, 1},
            {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
    };

    vector<complex<double>> test = {1, 4, 9, 16};

    cout << endl << "Test Dataset: " << endl;
    for(const auto& val : test) {
        cout << val << endl;
    }

//    vector<complex<double>> outputDFT = computeDFT(input);
//    vector<complex<double>> outputDFTold = DFT(input);
//
//    vector<complex<double>> test = {1, 2, 3, 4};
//    vector<complex<double>> outputDFTtest = computeDFT(test);
//
//    cout << "DFT Results: " << endl;
//    for(const auto& val : outputDFTtest) {
//        cout << val << endl;
//    }

    //computeFFTRecursive(input);
    //FFT_recursive(input);
    //vector<complex<double>> outputFFT = computeFFTRecursive(input);
    //CP_FFT(input);
    //computeFFTRecursive(input);
    //computeFFTRecursive(input, false);

    unsigned int numThreads = thread::hardware_concurrency();
    vector<thread> threads;
    cout << "Hardware Concurrency = " << numThreads << endl;



//    chrono::time_point<chrono::high_resolution_clock> startPoint = chrono::high_resolution_clock::now();
//    auto start = chrono::time_point_cast<chrono::microseconds>(startPoint);
    //auto end = chrono::

//    for(unsigned int i = 0; i < numThreads; i++) {
//        threads.push_back(thread(workload));
//    }
//
//    for(auto &thread : threads) {
//        if(thread.joinable())
//            thread.join();
//    }

    //int numThreads = omp_get_max_threads();
//    vector<int> fibResult = fibOMP(250);
//    #pragma omp parallel
//    for(int i = 0; i < omp_get_max_threads(); i++) {
//        cout << "Thread " << omp_get_thread_num() << ": " << endl;
//        //fibResult = fibOMP(250);
//        for (auto it = fibResult.rbegin(); it != fibResult.rend(); ++it) {
//            cout << *it;
//        }
//        cout << endl;
//        workload();
//    }

//    computeFFTRecursive(test, false);
//
//    cout << endl << "FFT Results: " << endl;
//    for(const auto& val : test) {
//        cout << val << endl;
//    }
//
//    computeFFTRecursive(test, true);
//    cout << endl << "Inverted FFT Results: " << endl;
//    for(const auto& val : test) {
//        cout << val << endl;
//    }
//
//    cout << "Running workload...\n";
//    workload();
//    cout << "Workload finished.\n";
//
//    chrono::time_point<chrono::high_resolution_clock> endPoint = chrono::high_resolution_clock::now();
//    auto end = chrono::time_point_cast<chrono::microseconds>(endPoint);
//
//    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
//    auto sec = duration * 0.001;
//
//    cout << endl;
//    cout << duration.count() * 0.001 << " ms" << endl;
//    cout << sec.count() * 0.001 << " s" << endl;
//
//
//    cout << "\n\nthread count = " << thread::hardware_concurrency();


    //testfunct();

    int opt;
    do {
        mainMenu();
        cin >> opt;

        BigInt x(1325, 100);
        x.print();

        switch(opt) {
            case 1: stressTestMenu(); break;
            case 2: benchmarkMenu(); break;
            case 3: sysInfoMenu(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }

    } while (opt != 4);

    return 0;
}