//
// Created by Matei on 05/09/2023.
//

#include "workloads.h"

using namespace std;

void computeFibToN(const int n) {
    //auto start = chrono::high_resolution_clock::now();
    Fibonacci fib(0);

    for(int i = 0; i <= n; i++) {
        fib.getFib(i);
    }
}

void stressTestWithIterations(const int n) {
    cout << "\nStress Test\n";
    cout << "Starting " << thread::hardware_concurrency() << " workers...\n\n";

    for(int iter = 1; iter <= n; iter++) {
        vector<thread> threads;
        auto start = chrono::high_resolution_clock::now();

        for(int i = 0; i < thread::hardware_concurrency(); i++) {
            threads.push_back(thread(computeFibToN, 1000));
        }

        for(auto& t : threads) { t.join(); }

        auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start);
        cout << left << "Iteration: " << iter << right << setw(40) << "Elapsed Test Time: " << duration.count() << " ms\n";
    }
}