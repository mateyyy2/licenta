#include <iostream>
#include <cmath>

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

int main() {
    cout << getThreadCount();

    return 0;
}