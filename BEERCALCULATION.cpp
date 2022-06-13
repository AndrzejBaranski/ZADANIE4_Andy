//
// Created by allti on 13.06.2022.
//
#include "pch_andy.h"
#include "BEERCALCULATION.h"

berResults calculateBer(std::string fpath1, std::string fpath2)
{
    std::fstream f1, f2; //handlers to files
    berResults results;
    results.t1 = 0;
    results.t2 = 0;
    results.ber = 0;
    results.err = 0;
    results.tot = 0;

    saveLog("Calculating BER...");
    f1.open(fpath1.c_str(), std::ios::binary | std::ios::in);
    f2.open(fpath2.c_str(), std::ios::binary | std::ios::in);
    char a = 0x00;
    char b = 0x00;
    results.t1 = clock();

    while (!f1.eof())
    {
        f1 >> a; //read 1 char from file 1
        f2 >> b; //read 1 char from file 2
        if (!f1.eof()) // till the end of the 1st file
        {
            results.err += hammingDistance(a, b); //add to the .err the number of different bits
            results.tot += 8; //add to the .tot the number of compared bits
        }
    }

    results.ber = (float)results.err / results.tot; // calculate ber
    results.t2 = clock();
    saveLog("BER calculations are done");
    return results; //return structure with all results
}