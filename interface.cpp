//
// Created by Matei on 05/08/2023.
//

#include "interface.h"

void mainMenu() {
    std::cout << std::setw(40) << std::right << "Welcome to CPU Stress Test & Benchmark Tool\n";
    std::cout << std::setw(40) << std::right << "-------------------------------------------\n";
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

}