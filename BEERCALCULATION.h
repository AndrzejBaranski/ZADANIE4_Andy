//
// Created by allti on 13.06.2022.
//

#ifndef BER_KALKULATOR_CALCULATERESULLT_H
#define BER_KALKULATOR_CALCULATERESULLT_H

#include <string>
#include <vector>
#include <time.h>


struct testData
{
    std::vector<char> data1;
    std::vector<char> data2;
    size_t volume;
};
testData loadDataFromFile(std::string  path1, std::string  path2);
std::string timeConverter(int seconds);
void test_1();
void test_2();
void test_3();

#endif //BER_KALKULATOR_CALCULATERESULLT_H

