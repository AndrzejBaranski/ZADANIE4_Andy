#include "pch_andy.h"

struct berResults
{
    double tot; //total number of bits
    double err; //error bits (different bits)
    float ber;  //ber calc result
    clock_t t1; //calc start time
    clock_t t2; //calc stop time
};

uint8_t hammingDistance(uint8_t n1, uint8_t n2);
void createFile1(const std::string name, const int count, const char value);
berResults calculateBer(std::string fpath1, std::string fpath2);
void printResult(berResults results);

int main(int argc, char * argv[])
{
    std::string fpath1; //path to file 1
    std::string fpath2; //path to file 2
    berResults results;

    openLog("log.log"); //create log.log file for logging purposes
    if (argc != 3) //check the number of arguments
    {
        saveLog("User did not provide path to the files.");
        saveLog("Creating the test files for user...");
        //test 1
        createFile1("test1_file1.bin", 100, 0xFF); //1111 1111
        createFile1("test1_file2.bin", 100, 0xFE); //1111 1110
        //test 2

        /*
            missing function to change 10 bits in the file
        */

        //test 3
        //createFile1("test3_file1.bin",400000000,0x55);
        //createFile1("test3_file2.bin",400000000,0x50);
        saveLog("Test files are prepared");
        saveLog("Re-run with correct arguments ie: ./task_iv_ber.exe test1_file1.bin test1_file2.bin");
    }
    else //arguments are passed correctly
    {
        fpath1 = argv[1];
        fpath2 = argv[2];

        saveLog("Processing test files");
        results = calculateBer(fpath1, fpath2);
        printResult(results);
    }

    closeLog();
    return 0;
}

uint8_t hammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2; // XOR
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    return setBits;
}

void createFile1(const std::string name, const int count, const char value)
{
    std::fstream f;
    f.open(name.c_str(), std::ios::binary | std::ios::out);
    for (int i = 0; i < count; i++)
    {
        f.write((char*)&value,1);
    }
    f.close();
}

void printResult(berResults results)
{
    std::stringstream message;
    message << "Results are: " << std::endl;
    message << "BER: " << results.ber << std::endl;
    message << "Tot: " << results.tot << std::endl;
    message << "Err: " << results.err << std::endl;
    message << "Calc time: " << ((float)results.t2 - results.t1) / CLOCKS_PER_SEC << " sec " << std::endl;
    saveLog(message.str());
}