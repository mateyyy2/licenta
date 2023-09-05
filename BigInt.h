//
// Created by Matei on 18/08/2023.
//

#ifndef PROJECT_CLION_BIGINT_H
#define PROJECT_CLION_BIGINT_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <iomanip>

class BigInt {
private:
    int* carry;
    int* digits;
    int size;
    bool isNegative;

public:
    BigInt();                       // null
    BigInt(const BigInt& big);      // copy
    BigInt(int size);               // init size
    BigInt(long value, int size);   // init value + size
    ~BigInt();

    int getSize() const;
    int getDigit(int index) const;
    int* getDigitsCopy() const;
    int* getCarryCopy() const;
    bool isNegativeNumber() const;

    void print() const;
    void printCarry() const;

    int getMostSignificantDigit() const;
    void setDigits(int* digits);
    bool setDigit(int value, int index);
    bool hasCarry();

    //void rightShift();
    BigInt & operator=(const BigInt& rhs);
    BigInt & operator+=(const BigInt& x);
    BigInt & operator-=(const BigInt& x);
    BigInt & operator*=(const int& x);


};

//inline BigInt operator+(BigInt lhs, const BigInt& x);
//inline BigInt operator-(BigInt lhs, const BigInt& x);
//inline BigInt operator*(BigInt lhs, const int& x);

inline BigInt operator+(BigInt lhs, const BigInt &x) {
    lhs += x;
    return lhs;
}

inline BigInt operator-(BigInt lhs, const BigInt &x) {
    lhs -= x;
    return lhs;
}

inline BigInt operator*(BigInt lhs, const int &x) {
    lhs *= x;
    return lhs;
}



#endif //PROJECT_CLION_BIGINT_H
