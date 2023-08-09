//
// Created by Matei on 05/08/2023.
//

#include "interface.h"
#include "sysinfo.h"

#include <iomanip>
#include <iostream>

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mainMenu() {
    std::cout << std::setw(5) << std::left << "1." << std::right << "Stress Test\n";
    std::cout << std::setw(5) << std::left << "2." << std::right << "Benchmark\n";
    std::cout << std::setw(5) << std::left << "3." << std::right << "SysInfo\n";
    std::cout << std::setw(5) << std::left << "4." << std::right << "Exit\n";
    std::cout << "Please enter your choice (1-4): ";
}

void stressTestMenu() {

}

void benchmarkMenu() {

}

void sysInfoMenu() {
    CPUInfo cinfo;

    clear();
    cout << std::setw(5) << std::left << "CPU Vendor = " << std::right << cinfo.vendor() << endl;
    cout << std::setw(5) << std::left << "CPU Model = " << std::right << cinfo.model() << endl;
    cout << std::setw(5) << std::left << "CPU Core Count = " << std::right << cinfo.cores() << endl;
    cout << std::setw(5) << std::left << "CPU Thread Count = " << std::right << cinfo.logicalCpus() << endl;
    cout << std::setw(5) << std::left << "CPU Hyper Threaded = " << std::right << cinfo.isHyperThreaded() << endl;
    cout << endl;
}