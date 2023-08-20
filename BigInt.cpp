//
// Created by Matei on 18/08/2023.
//

#include "BigInt.h"


BigInt::BigInt(unsigned long unit) {
    assert(unit < BASE2);
    units.push_back(unit);
}

BigInt::BigInt(BigInt big1, BigInt big2) {
    const unsigned long max_size = MAX(big1.units.size(), big2.units.size());

    big1.units.resize(max_size);
    big2.units.resize(max_size);
    units.resize(max_size);

    carry = 0;
    transform(big1.units.begin(), big1.units.end(), big2.units.begin(), units.begin(), *this);

    if(carry) units.push_back(carry);
}

unsigned long BigInt::operator()(const unsigned long n1, const unsigned long n2) {
    const unsigned long value = n1 + n2 + carry;
    carry = value / BASE2;

    return (value % BASE2);
}

//inline ostream& operator<< (ostream& os, const BigInt& ins_i) {
//    assert(!ins_i.units_.empty());
//
//    for(unsigned long i = (ins_i.units_.size() - 1); i; --i) {
//        os << ins_i.units_[i] << setw(BASE1 - 1) << setfill('0');
//    }
//
//    return os << ins_i.units_[0];
//}

unsigned long BigInt::carry (0);