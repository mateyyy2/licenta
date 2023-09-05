//
// Created by Matei on 05/08/2023.
//

#include "interface.h"
#include "sysinfo.h"
#include "Fibonacci.h"
//#include "benchmark.h"
#include "workloads.h"

#include <iomanip>
#include <iostream>

using namespace std;

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mainMenu() {
    //clear();

    //cout << "Evaluarea performantei procesoarelor x86-64\n\n";

//    system("Color 07");
    std::cout << std::setw(5) << std::left << "1.";// << std::right << "Stress Test\n";
    //system("Color 0A");
    cout << std::right << "Stress Test\n";
    //system("Color 07");
    std::cout << std::setw(5) << std::left << "2." << std::right << "Benchmark\n";
    std::cout << std::setw(5) << std::left << "3." << std::right << "SysInfo\n";
    std::cout << std::setw(5) << std::left << "4." << std::right << "Exit\n\n";
    std::cout << "Please enter your choice (1-4): ";
}

void stressTestMenu() {
    clear();

    int opt;
    do {
        //system("Color 04");
        std::cout << std::setw(5) << std::left << "1." << std::right << "Run stress test on all cores\n";
        std::cout << std::setw(5) << std::left << "2." << std::right << "Go back to main menu\n\n";
        std::cout << "Please enter your choice (1-2): ";

        cin >> opt;

        switch(opt) {
            case 1: stressTestWithIterations(10); break;
            case 2: clear(); break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }


    } while(opt != 2);

    //cout << setw(5) << std::left << "1." << std::right << setw(10) << "Stress Test";

    //stressTest();
}

void benchmarkMenu() {
    clear();

    int opt;
    do {
        //system("Color 04");
        std::cout << std::setw(5) << std::left << "1." << std::right << "Single-threaded benchmark\n";
        std::cout << std::setw(5) << std::left << "2." << std::right << "Multi-threaded benchmark\n";
        std::cout << std::setw(5) << std::left << "3." << std::right << "Go back to main menu\n\n";
        std::cout << "Please enter your choice (1-3): ";

        cin >> opt;

        switch(opt) {
            case 1: benchmark(); break;
            case 2: cout << "Multi-threaded benchmark not yet available.\n"; break;
            case 3: clear(); break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }


    } while(opt != 3);

    //benchmark();
//    Fibonacci fn(1);
//    for(int i = 0; i < 100; i++) {
//        cout << "Fib(" << i << ") = ";
//        fn.showFib(i);
//    }
//
//    cout << endl << fn.getFib(9).getDigit(0) << fn.getFib(9).getDigit(1) << " " << fn.getFib(9).getMostSignificantDigit() << endl;
//
//    BigInt a(5420, 10);
//    cout << endl << a.getDigit(0) << " " << a.getMostSignificantDigit() << " " << a.getDigit(a.getMostSignificantDigit()) << endl;
//    //a += 1000;
//    BigInt b(10000, 10);
//    a += b;
//    cout << endl << a.getDigit(0) << " " << a.getMostSignificantDigit() << " " << a.getDigit(a.getMostSignificantDigit()) << endl;


//    BigInt fn(3254346, 1000);
//    fn.print();
}

void sysInfoMenu() {
    clear();

    cout << "Gathering system information...\n\n";

    CPUInfo cinfo;

    cout << std::setw(5) << std::left << "CPU Vendor = " << std::right << cinfo.vendor() << endl;
    cout << std::setw(5) << std::left << "CPU Model = " << std::right << cinfo.model() << endl;
    cout << std::setw(5) << std::left << "CPU Core Count = " << std::right << cinfo.cores() << endl;
    cout << std::setw(5) << std::left << "CPU Thread Count = " << std::right << cinfo.logicalCpus() << endl;
    cout << std::setw(5) << std::left << "CPU Hyper Threaded = " << std::right << std::boolalpha << cinfo.isHyperThreaded() << endl;

    cout << endl << "SIMD Extensions:" << endl;
    cout << setw(5) << left << "SSE = " << right << boolalpha << cinfo.isSSE() << endl;
    cout << setw(5) << left << "SSE2 = " << right << boolalpha << cinfo.isSSE2() << endl;
    cout << setw(5) << left << "SSE3 = " << right << boolalpha << cinfo.isSSE3() << endl;
    cout << setw(5) << left << "SSE41 = " << right << boolalpha << cinfo.isSSE41() << endl;
    cout << setw(5) << left << "SSE42 = " << right << boolalpha << cinfo.isSSE42() << endl;
    cout << setw(5) << left << "AVX = " << right << boolalpha << cinfo.isAVX() << endl;
    cout << setw(5) << left << "AVX2 = " << right << boolalpha << cinfo.isAVX2() << endl;

    cout << endl << "Go back to main menu? ";
    string opt;
    cin >> opt;
    clear();
}