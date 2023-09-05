//
// Created by Matei on 18/08/2023.
//

#include "BigInt.h"


BigInt::BigInt() {
    this->carry = NULL;
    this->digits = NULL;
    this->size = 0;
    this->isNegative = false;
}

BigInt::BigInt(const BigInt& big) {
    this->digits = new int[big.getSize()];
    this->size = big.getSize();
    this->isNegative = big.isNegativeNumber();
//    this->digits = big.getDigitsCopy();
    this->carry = big.getCarryCopy();

    int *copyDigits = big.getDigitsCopy();
    for(int i = 0; i < this->size; i++) {
        this->digits[i] = copyDigits[i];
    }

    delete[] copyDigits;
}

BigInt::BigInt(int size) {
    this->carry = NULL;
    this->digits = new int[size];
    for(int i = 0; i < size; i++) { this->digits[i] = 0; }
    this->size = size;
    this->isNegative = false;
}

BigInt::BigInt(long value, int size) {
    int i;

    this->carry = NULL;
    this->digits = new int[size];
    this->size = size;
    for(i = 0; i < size; i++) {
        this->digits[i] = value % 10;
        value /= 10;
    }
    this->isNegative = false;
}

BigInt::~BigInt() {
    delete[] this->digits;
    if(this->carry != NULL) { delete[] this->carry; }
}

int BigInt::getSize() const {
    return this->size;
}

int BigInt::getDigit(int index) const {
    return this->digits[index];
}

int* BigInt::getDigitsCopy() const {
    int* digitsCopy = new int[this->size];

    for(int i = 0; i < this->size; i++) {
        digitsCopy[i] = this->digits[i];
    }

    return digitsCopy;
}

int* BigInt::getCarryCopy() const {
    if(this->carry != NULL) {
        int* carryCopy = new int[this->size];

        for(int i = 0; i < this->size; i++) {
            carryCopy[i] = this->carry[i];
        }

        return carryCopy;
    }

    return NULL;
}

bool BigInt::isNegativeNumber() const {
    return this->isNegative;
}

void BigInt::print() const {
    for(int i = this->size - 1; i >= 0; i--) {
        if(this->digits[i] != 0)
            std::cout << this->digits[i];
    }
    std::cout << std::endl;
}

void BigInt::printCarry() const {
    if(this->carry != NULL) {
        for (int i = this->size - 1; i >= 0; i--) { std::cout << this->carry[i]; }
        std::cout << std::endl;
    }
    else { std::cout << "0\n"; }
}

int BigInt::getMostSignificantDigit() const {
    for(int i = this->size - 1; i >= 0; i--) {
        if(digits[i] > 0) { return i; }
    }

    return 0;
}

void BigInt::setDigits(int* digits) {
    delete[] this->digits;
    this->digits = digits;
    this->size = sizeof(digits) / sizeof(int);
}

bool BigInt::setDigit(int value, int index) {
    int sig = this->getMostSignificantDigit();

    if(value < 10 && value >= 0 && index >= 0 && index <= sig) {
        this->digits[index] = value;
        return true;
    }

    return false;
}

bool BigInt::hasCarry() {
    if(this->carry != NULL) {
        for(int i = 0; i < this->size; i++) {
            if(this->carry[i] > 0) return true;
        }
    }

    return false;
}

BigInt &BigInt::operator=(const BigInt &rhs) {
    if(this == &rhs)
        return *this;

    delete[] this->digits;

    this->size = rhs.getSize();
    this->digits = rhs.getDigitsCopy();
    this->isNegative = rhs.isNegativeNumber();
    this->carry = rhs.getCarryCopy();

    return *this;
}

BigInt &BigInt::operator+=(const BigInt &x) {
    int i, newValue, carry = 0;

    if(this->size != x.getSize()) {
        std::cout << "Mismatched BigInt sizes in += operator.\n";
        return *(new BigInt(0, 1));
    }

    for(i = 0; i < this->size; i++) {
        newValue = this->digits[i] + x.getDigit(i) + carry;

        this->digits[i] = newValue % 10;
        if(newValue >= 10)
            carry = newValue / 10;
        else
            carry = 0;
    }

    if(carry > 0) {
        std::cout << "Overflow in += operator.\n";
    }

    return *this;
}

BigInt &BigInt::operator-=(const BigInt &x) {
    int thisSig = this->getMostSignificantDigit();
    int xSig = x.getMostSignificantDigit();
    bool thisLarger = true;
    int lastIndex = this->size - 1;
    int *digitsCopy = x.getDigitsCopy();

    int *largeRef, *smallRef;

//    if(this->size != x.getSize()) {
//        std::cout << "Mismatched BigInt sizes in -= operator.\n";
//        return *(new BigInt(0, 1));
//    }

    if(xSig > thisSig) { thisLarger = false; }
    else if(xSig == thisSig) {
        for(int i = thisSig; i >= 0; i--) {
            if(this->digits[i] < digitsCopy[i]) {
                thisLarger = false;
                this->isNegative = true;
                break;
            }
            else if(this->digits[i] > digitsCopy[i]) { break; }
        }
    }

    if(thisLarger) {
        largeRef = this->digits;
        smallRef = digitsCopy;
    } else {
        largeRef = digitsCopy;
        smallRef = this->digits;
    }

    int newValue;
    for(int i = 0; i < this->size - 1; i++) {
        newValue = largeRef[i] - smallRef[i];

        if(newValue < 0) {
            largeRef[i] = newValue + 10;
            largeRef[i + 1] -= 1;
        } else {
            largeRef[i] = newValue;
        }
    }

    newValue = largeRef[lastIndex] - smallRef[lastIndex];
    largeRef[lastIndex] = newValue;

    if(largeRef != this->digits) {
        for(int i = 0; i < this->size; i++)
            this->digits[i] = largeRef[i];
    }
    delete[] digitsCopy;

    return *this;
}

BigInt &BigInt::operator*=(const int &x) {
    int newValue, carry = 0;

    for(int i = 0; i < this->size; i++) {
        newValue = digits[i] * x + carry;
        this->digits[i] = newValue % 10;

        if(newValue >= 10)
            carry = newValue / 10;
        else
            carry = 0;
    }

    return *this;
}


//inline BigInt operator+(BigInt lhs, const BigInt &x) {
//    lhs += x;
//    return lhs;
//}
//
//inline BigInt operator-(BigInt lhs, const BigInt &x) {
//    lhs -= x;
//    return lhs;
//}
//
//inline BigInt operator*(BigInt lhs, const int &x) {
//    lhs *= x;
//    return lhs;
//}