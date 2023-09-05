//
// Created by Matei on 05/09/2023.
//

#include "workloads.h"

using namespace std;

void computeFibToN(const int n, bool lastPrint) {
    //auto start = chrono::high_resolution_clock::now();
    //cout << "Starting worker " << this_thread::get_id() << "...\n";
    Fibonacci fib(0);

    for(int i = 0; i <= n; i++) {
        fib.getFib(i);

        if(i == n && lastPrint == true) { fib.showFib(i); }
    }
}

void stressTestAllCore(const int n) {
    cout << "\nAll-Core Stress Test\n";
    cout << "Computing the 10000th Fibonacci term for 10 iterations.\n\n";
    cout << "Starting " << thread::hardware_concurrency() << " workers...\n\n";

    for(int iter = 1; iter <= n; iter++) {
        vector<thread> threads;
        auto start = chrono::high_resolution_clock::now();

        for(int i = 0; i < thread::hardware_concurrency(); i++) {
            threads.emplace_back(thread(computeFibToN, 10000, false));
        }

        for(auto& t : threads) { t.join(); }

        auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start);
        cout << left << "Iteration: " << iter << right << setw(40) << "Elapsed Test Time: " << duration.count() << " ms\n";
    }
}

void benchmarkSingleCore(const int n) {
    cout << "\nSingle-Core Benchmark\n";
    cout << "Computing the 5000th Fibonacci term on one physical core.\n\n";

    thread worker(computeFibToN, n, true);
    cout << "Starting worker...\n\n";

    auto start = chrono::high_resolution_clock::now();

    worker.join();

    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start);
    cout << "\nComputed the 5000th Fibonacci term in " << duration.count() << " ms.\n\n";
}