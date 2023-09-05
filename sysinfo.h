//
// Created by Matei on 07/08/2023.
//

#ifndef PROJECT_CLION_SYSINFO_H
#define PROJECT_CLION_SYSINFO_H

#include <iostream>
#include <string>
#include <algorithm>

#ifdef _WIN32
#include <limits.h>
#include <intrin.h>
#else
#include <stdint.h>
#endif

#define MAX_INTEL_TOP_LVL 4

using namespace std;

class CPUID {
    uint32_t regs[4];

public:
    inline explicit CPUID(unsigned funcID, unsigned subFuncID) {
#ifdef _WIN32
        __cpuidex((int *)regs, (int)funcID, (int)subFuncID);

#else
        asm volatile("cpuid": "=a" (regs[0]), "=b" (regs[1]), "=c" (regs[2]), "=d" (regs[3])
                    : "a" (funcID), "c" (subFuncID));
#endif
    }

    const uint32_t &EAX() const { return regs[0]; }
    const uint32_t &EBX() const { return regs[1]; }
    const uint32_t &ECX() const { return regs[2]; }
    const uint32_t &EDX() const { return regs[3]; }

};

class CPUInfo {
private:
    static const uint32_t SSE_POS   = 0x02000000;
    static const uint32_t SSE2_POS  = 0x04000000;
    static const uint32_t SSE3_POS  = 0x00000001;
    static const uint32_t SSE41_POS = 0x00080000;
    static const uint32_t SSE42_POS = 0x00100000;
    static const uint32_t AVX_POS   = 0x10000000;
    static const uint32_t AVX2_POS  = 0x00000020;
    static const uint32_t LVL_NUM   = 0x000000FF;
    static const uint32_t LVL_TYPE  = 0x0000FF00;
    static const uint32_t LVL_CORES = 0x0000FFFF;

    // CPU Attributes
    string mVendorID;
    string mModelName;
    int    mNumSMT;
    int    mNumCores;
    int    mNumLogCpus;
    bool   mIsHTT;
    bool   mIsSSE;
    bool   mIsSSE2;
    bool   mIsSSE3;
    bool   mIsSSE41;
    bool   mIsSSE42;
    bool   mIsAVX;
    bool   mIsAVX2;

public:
    CPUInfo();
    string vendor()             const { return mVendorID; }
    string  model()             const { return mModelName;  }
    int     cores()             const { return mNumCores;   }
    int     logicalCpus()       const { return mNumLogCpus; }
    bool    isHyperThreaded()   const { return mIsHTT;      }
    bool    isSSE()             const { return mIsSSE;      }
    bool    isSSE2()            const { return mIsSSE2;     }
    bool    isSSE3()            const { return mIsSSE3;     }
    bool    isSSE41()           const { return mIsSSE41;    }
    bool    isSSE42()           const { return mIsSSE42;    }
    bool    isAVX()             const { return mIsAVX;      }
    bool    isAVX2()            const { return mIsAVX2;     }
};

#endif //PROJECT_CLION_SYSINFO_H
