//
// Created by allti on 13.06.2022.
//

#ifndef ZADANIE4_ANDY_BEERCALCULATION_H
#define ZADANIE4_ANDY_BEERCALCULATION_H

#include "pch_andy.h"

struct berResults
{
    double tot; //total number of bits
    double err; //error bits (different bits)
    float ber;  //ber calc result
    clock_t t1; //calc start time
    clock_t t2; //calc stop time
};

berResults calculateBer(std::string fpath1, std::string fpath2);

#endif //ZADANIE4_ANDY_BEERCALCULATION_H
