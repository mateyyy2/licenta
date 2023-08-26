//
// Created by Matei on 16/08/2023.
//

#include "stressTest.h"

using namespace std;

atomic<bool> continueStressTest(true);

void fibonacciStartEnd(Fibonacci& fib, int start, int end) {
    while(continueStressTest) {
        for (int i = start; i < end; i++) {
            fib.showFib(i);
            //fib.showNumber(i);
        }
    }
}

void runFibonacci() {
    auto start = chrono::high_resolution_clock::now();
    //auto end = start;

//    while(chrono::duration_cast<chrono::minutes>(end - start).count() < 1) {
        //Fibonacci fib(10000);
        Fibonacci fib(2);
        for(int i = 0; i <= 4500; i++) {
            //fib.showNumber(i);
            //fib.getNumber(i);
            //fib.getFib(i);
            fib.getFib(i);
            if(i == 4500) {
                cout << "Worker has reached 25000th Fibonacci number.\n";
                fib.showFib(i);
                //cout << endl << fib.getNumber(i).getDigit(0);
            }
        }


        auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start);
        cout << "Thread " << this_thread::get_id() << " took: " << duration.count() << " ms.\n";
//        end = std::chrono::high_resolution_clock::now();
//    }
}

void stressTest() {
    //Fibonacci fib(10000);

    int numsPerThread = 10000 / thread::hardware_concurrency();
    vector<thread> threads;

//    atomic<bool> continueStressTest(true);

    for(int i = 0; i < thread::hardware_concurrency(); i++) {
        cout << "Worker " << i << " started.\n";

        int start = i * numsPerThread;
        int end = (i == thread::hardware_concurrency() - 1) ? 10000 : start + numsPerThread;

        //threads.push_back(thread(fib.show_number))
        //threads.push_back(thread(fibonacciStartEnd, ref(fib), start, end));
        threads.push_back(thread(runFibonacci));
    }
//    this_thread::sleep_for(chrono::seconds(15));
//    continueStressTest = false;

    for(auto& t : threads) {
        t.join();
    }
}