//
// Created by Matei on 18/07/2023.
//

#include "FFT.h"

using namespace std;


void computeFFTRecursive(vector<complex<double>>& input, bool inverted) {
    int N = input.size();
    if(N <= 1) return;

    // Divide
    vector<complex<double>> even(N / 2), odd(N / 2);
    for(int i = 0; i < N / 2; i++) {
        even[i] = input[i * 2];
        odd[i] = input[i * 2 + 1];
    }

    // Conquer
    computeFFTRecursive(even, inverted);
    computeFFTRecursive(odd, inverted);

    // Combine
    double angle = 2 * PI / N * (inverted ? -1 : 1);
    complex<double> w(1), wn(cos(angle), sin(angle));

    for(int k = 0; k < N / 2; k++) {
        input[k] = even[k] + w * odd[k];
        input[k + N / 2] = even[k] - w * odd[k];

        if(inverted) {
            input[k] /= 2;
            input[k + N / 2] /= 2;
        }

        w *= wn;
    }
}

vector<int> multiplyPolynomialsFFT(vector<int> const& A, vector<int> const& B) {
    int N = 1;
    // cea mai mica putere a lui 2 > (A.size + B.size - 1)
    while(N < (A.size() + B.size()))
        N <<= 1;

    vector<complex<double>> FA(A.begin(), A.end());
    vector<complex<double>> FB(B.begin(), B.end());
    //A.resize(N);
    FA.resize(N);
    FB.resize(N);

    // evaluam polinoamele
    computeFFTRecursive(FA, false);
    computeFFTRecursive(FB, false);

    // multiplicam polinoamele
    for(int i = 0; i < N; i++)
        FA[i] *= FB[i];

    // aplicam inverse FFT pentru a afla coeficientii
    //                              converti produsul pointwise in coeficienti
    computeFFTRecursive(FA, true);

    // rotunjim coeficientii la int (erori pt complex)
    vector<int> result(N);
    for(int i = 0; i < N; i++)
        result[i] = round(FA[i].real());

    return result;
}

