//
// Created by Matei on 18/08/2023.
//

#include "BigInt.h"


BigInt::BigInt(unsigned long unit_i) {
    assert(unit_i < BASE2);
    units_.push_back(unit_i);
}

BigInt::BigInt(BigInt big1_i, BigInt big2_i) {
    const unsigned long max_size = MAX(big1_i.units_.size(), big2_i.units_.size());

    big1_i.units_.resize(max_size);
    big2_i.units_.resize(max_size);
    units_.resize(max_size);

    head_s = 0;
    transform(big1_i.units_.begin(), big1_i.units_.end(), big2_i.units_.begin(), units_.begin(), *this);

    if(head_s) units_.push_back(head_s);
}

unsigned long BigInt::operator()(const unsigned long n1, const unsigned long n2) {
    const unsigned long value = n1 + n2 + head_s;
    head_s = value / BASE2;

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

unsigned long BigInt::head_s (0);