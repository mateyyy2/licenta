//
// Created by Matei on 11/08/2023.
//

#include "BigFibonacci.h"

using namespace std;

//class BigInt {
//    friend ostream& operator<< (ostream& os, const BigInt& ins_i);
//
//
//};



BigInt Fibonacci::get_number(unsigned int n_i) {
    fibs_.reserve(n_i + 1);
    const unsigned int cur_size = fibs_.size();

    for(unsigned int i = cur_size; i <= n_i; i++) {
        switch(i) {
            case 0:
                fibs_.push_back(BigInt(0));
                break;
            case 1:
                if(fibs_.empty()) fibs_.push_back(BigInt(0));
                fibs_.push_back(BigInt(1));
                break;
            default:
                fibs_.push_back(BigInt(get_number(i - 2), get_number(i - 1)));
                break;
        }
    }

    assert(n_i < fibs_.size());

    return fibs_[n_i];
}

void Fibonacci::show_number(unsigned long n_i) {
    ostringstream oss;

    if(!(n_i < fibs_.size())) get_number(n_i);

    oss << "Fib [" << n_i << "] = " << fibs_[n_i] << endl;

    //cout << oss.str();
}

inline ostream& operator<< (ostream& os, const BigInt& ins_i) {
    assert(!ins_i.units_.empty());

    for(unsigned long i = (ins_i.units_.size() - 1); i; --i) {
        os << ins_i.units_[i] << setw(BASE1 - 1) << setfill('0');
    }

    return os << ins_i.units_[0];
}

//unsigned long BigInt::head_s (0);