//
// Created by Matei on 05/08/2023.
//

#include "interface.h"
#include "sysinfo.h"
#include "BigFibonacci.h"

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

    std::cout << std::setw(5) << std::left << "1." << std::right << "Stress Test\n";
    std::cout << std::setw(5) << std::left << "2." << std::right << "Benchmark\n";
    std::cout << std::setw(5) << std::left << "3." << std::right << "SysInfo\n";
    std::cout << std::setw(5) << std::left << "4." << std::right << "Exit\n";
    std::cout << "Please enter your choice (1-4): ";
}

void stressTestMenu() {
//    Fibonacci fib(1000);
//    for (int i = 0; i < 1000; i++) {
//        fib.show_number(i);
//    }
    clear();

    //cout << setw(5) << std::left << "1." << std::right << setw(10) << "Stress Test";

    stressTest();
}

void benchmarkMenu() {
    //clear();

    Fibonacci fn(1);
    //fn.showFib(1);


//    BigInt fn(3254346, 1000);
//    fn.print();
}

void sysInfoMenu() {
    clear();

    CPUInfo cinfo;

    cout << std::setw(5) << std::left << "CPU Vendor = " << std::right << cinfo.vendor() << endl;
    cout << std::setw(5) << std::left << "CPU Model = " << std::right << cinfo.model() << endl;
    cout << std::setw(5) << std::left << "CPU Core Count = " << std::right << cinfo.cores() << endl;
    cout << std::setw(5) << std::left << "CPU Thread Count = " << std::right << cinfo.logicalCpus() << endl;
    cout << std::setw(5) << std::left << "CPU Hyper Threaded = " << std::right << cinfo.isHyperThreaded() << endl;

//    cout << std::setw(15) << std::left << "CPU Vendor " << std::setw(15) << std::left << "=" << std::right << cinfo.vendor() << endl;
//    cout << std::setw(15) << std::left << "CPU Model " << std::setw(15) << std::left << "=" <<  std::right << cinfo.model() << endl;
//    cout << std::setw(15) << std::left << "CPU Core Count " << std::setw(15) << std::left << "=" << std::setw(15) << std::right << cinfo.cores() << endl;
//    cout << std::setw(15) << std::left << "CPU Thread Count " << std::setw(15) << std::left << "="  << std::right << cinfo.logicalCpus() << endl;
//    cout << std::setw(15) << std::left << "CPU Hyper Threaded " << "=" << std::setw(15) << std::right << cinfo.isHyperThreaded() << endl;
    cout << endl;
}