#define PROC_FREQ 23000000000
#define THENUMBER 2001
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <chrono>
#include <iomanip>
#include <stdint.h>
#include "asmOperations.h"


//  Windows

#include <intrin.h>
uint64_t rdtsc() {
    return __rdtsc();
}


inline uint64_t clockCycleCount()
{
    uint64_t c;
    __asm {
        cpuid       // serialize processor
        rdtsc       // read time stamp counter
        mov dword ptr[c + 0], eax
        mov dword ptr[c + 4], edx
    }
    return c;
}

int main()
{
    setlocale(LC_ALL, "rus");
    short shortInt_number1 = THENUMBER, shortInt_number2 = THENUMBER;
    unsigned short unsShortInt_number1 = THENUMBER, unsShortInt_number2 = THENUMBER;
    int int_number1 = THENUMBER, int_number2 = THENUMBER;
    unsigned int unsInt_number1 = THENUMBER, unsInt_number2 = THENUMBER;
    long longInt_number1 = THENUMBER, longInt_number2 = THENUMBER;
    unsigned long unsLong_number1 = THENUMBER, unsLong_number2 = THENUMBER;
    long long longLong_number1 = THENUMBER, longLong_number2 = THENUMBER;
    unsigned long long unsLongLong_number1 = THENUMBER, unsLongLong_number2 = THENUMBER;

    float float_number1 = THENUMBER, float_number2 = THENUMBER;
    double double_number1 = THENUMBER, double_number2 = THENUMBER;
    long double longDouble_number1 = THENUMBER, longDouble_number2 = THENUMBER;

    int regADDres[11];
    int regSUBres[11];
    int regMULres[11];
    int regDEVres[11];

    regADDres[0] = shortAdd(shortInt_number1, shortInt_number2, registers);
    regADDres[1] = unsShortAdd(unsShortInt_number1, unsShortInt_number2, registers);
    regADDres[2] = intAdd(int_number1, int_number2, registers);
    regADDres[3] = unsIntAdd(unsInt_number1, unsInt_number2, registers);
    regADDres[4] = longAdd(longInt_number1, longInt_number2, registers);
    regADDres[5] = unsLongAdd(unsLong_number1, unsLong_number2, registers);
    regADDres[6] = longLongAdd(longLong_number1, longLong_number2, registers);
    regADDres[7] = unsLongLongAdd(unsLongLong_number1, unsLongLong_number2, registers);
    regADDres[8] = floatAdd(float_number1, float_number2, registers);
    regADDres[9] = doubleAdd(double_number1, double_number2, registers);
    regADDres[10] = longDoubleAdd(longDouble_number1, longDouble_number2, registers);
    
    regSUBres[0] = shortSubtract(shortInt_number1, shortInt_number2, registers);
    regSUBres[1] = unsShortSubtract(unsShortInt_number1, unsShortInt_number2, registers);
    regSUBres[2] = intSubtract(int_number1, int_number2, registers);
    regSUBres[3] = unsIntSubtract(unsInt_number1, unsInt_number2, registers);
    regSUBres[4] = longSubtract(longInt_number1, longInt_number2, registers);
    regSUBres[5] = unsLongSubtract(unsLong_number1, unsLong_number2, registers);
    regSUBres[6] = longLongSubtract(longLong_number1, longLong_number2, registers);
    regSUBres[7] = unsLongLongSubtract(unsLongLong_number1, unsLongLong_number2, registers);
    regSUBres[8] = floatSubtract(float_number1, float_number2, registers);
    regSUBres[9] = doubleSubtract(double_number1, double_number2, registers);
    regSUBres[10] = longDoubleSubtract(longDouble_number1, longDouble_number2, registers);
                   
                   
    regMULres[0] = shortMultiply(shortInt_number1, shortInt_number2, registers);
    regMULres[1] = unsShortMultiply(unsShortInt_number1, unsShortInt_number2, registers);
    regMULres[2] = intMultiply(int_number1, int_number2, registers);
    regMULres[3] = unsIntMultiply(unsInt_number1, unsInt_number2, registers);
    regMULres[4] = longMultiply(longInt_number1, longInt_number2, registers);
    regMULres[5] = unsLongMultiply(unsLong_number1, unsLong_number2, registers);
    regMULres[6] = longLongMultiply(longLong_number1, longLong_number2, registers);
    regMULres[7] = unsLongLongMultiply(unsLongLong_number1, unsLongLong_number2, registers);
    regMULres[8] = floatMultiply(float_number1, float_number2, registers);
    regMULres[9] = doubleMultiply(double_number1, double_number2, registers);
    regMULres[10] = longDoubleMultiply(longDouble_number1, longDouble_number2, registers);
                   
    regDEVres[0] = shortDevide(shortInt_number1, shortInt_number2, registers);
    regDEVres[1] = unsShortDevide(unsShortInt_number1, unsShortInt_number2, registers);
    regDEVres[2] = intDevide(int_number1, int_number2, registers);
    regDEVres[3] = unsIntDevide(unsInt_number1, unsInt_number2, registers);
    regDEVres[4] = longDevide(longInt_number1, longInt_number2, registers);
    regDEVres[5] = unsLongDevide(unsLong_number1, unsLong_number2, registers);
    regDEVres[6] = longLongDevide(longLong_number1, longLong_number2, registers);
    regDEVres[7] = unsLongLongDevide(unsLongLong_number1, unsLongLong_number2, registers);
    regDEVres[8] = floatDevide(float_number1, float_number2, registers);
    regDEVres[9] = doubleDevide(double_number1, double_number2, registers);
    regDEVres[10] = longDoubleDevide(longDouble_number1, longDouble_number2, registers);

    int memADDres[11];
    int memSUBres[11];
    int memMULres[11];
    int memDEVres[11];

    memADDres[0] = shortAdd(shortInt_number1, shortInt_number2, memory);
    memADDres[1] = unsShortAdd(unsShortInt_number1, unsShortInt_number2, memory);
    memADDres[2] = intAdd(int_number1, int_number2, memory);
    memADDres[3] = unsIntAdd(unsInt_number1, unsInt_number2, memory);
    memADDres[4] = longAdd(longInt_number1, longInt_number2, memory);
    memADDres[5] = unsLongAdd(unsLong_number1, unsLong_number2, memory);
    memADDres[6] = longLongAdd(longLong_number1, longLong_number2, memory);
    memADDres[7] = unsLongLongAdd(unsLongLong_number1, unsLongLong_number2, memory);
    memADDres[8] = floatAdd(float_number1, float_number2, memory);
    memADDres[9] = doubleAdd(double_number1, double_number2, memory);
    memADDres[10] = longDoubleAdd(longDouble_number1, longDouble_number2, memory);
    
    memSUBres[0] = shortSubtract(shortInt_number1, shortInt_number2, memory);
    memSUBres[1] = unsShortSubtract(unsShortInt_number1, unsShortInt_number2, memory);
    memSUBres[2] = intSubtract(int_number1, int_number2, memory);
    memSUBres[3] = unsIntSubtract(unsInt_number1, unsInt_number2, memory);
    memSUBres[4] = longSubtract(longInt_number1, longInt_number2, memory);
    memSUBres[5] = unsLongSubtract(unsLong_number1, unsLong_number2, memory);
    memSUBres[6] = longLongSubtract(longLong_number1, longLong_number2, memory);
    memSUBres[7] = unsLongLongSubtract(unsLongLong_number1, unsLongLong_number2, memory);
    memSUBres[8] = floatSubtract(float_number1, float_number2, memory);
    memSUBres[9] = doubleSubtract(double_number1, double_number2, memory);
    memSUBres[10] = longDoubleSubtract(longDouble_number1, longDouble_number2, memory);
                   
                   
    memMULres[0] = shortMultiply(shortInt_number1, shortInt_number2, memory);
    memMULres[1] = unsShortMultiply(unsShortInt_number1, unsShortInt_number2, memory);
    memMULres[2] = intMultiply(int_number1, int_number2, memory);
    memMULres[3] = unsIntMultiply(unsInt_number1, unsInt_number2, memory);
    memMULres[4] = longMultiply(longInt_number1, longInt_number2, memory);
    memMULres[5] = unsLongMultiply(unsLong_number1, unsLong_number2, memory);
    memMULres[6] = longLongMultiply(longLong_number1, longLong_number2, memory);
    memMULres[7] = unsLongLongMultiply(unsLongLong_number1, unsLongLong_number2, memory);
    memMULres[8] = floatMultiply(float_number1, float_number2, memory);
    memMULres[9] = doubleMultiply(double_number1, double_number2, memory);
    memMULres[10] = longDoubleMultiply(longDouble_number1, longDouble_number2, memory);
                   
    memDEVres[0] = shortDevide(shortInt_number1, shortInt_number2, memory);
    memDEVres[1] = unsShortDevide(unsShortInt_number1, unsShortInt_number2, memory);
    memDEVres[2] = intDevide(int_number1, int_number2, memory);
    memDEVres[3] = unsIntDevide(unsInt_number1, unsInt_number2, memory);
    memDEVres[4] = longDevide(longInt_number1, longInt_number2, memory);
    memDEVres[5] = unsLongDevide(unsLong_number1, unsLong_number2, memory);
    memDEVres[6] = longLongDevide(longLong_number1, longLong_number2, memory);
    memDEVres[7] = unsLongLongDevide(unsLongLong_number1, unsLongLong_number2, memory);
    memDEVres[8] = floatDevide(float_number1, float_number2, memory);
    memDEVres[9] = doubleDevide(double_number1, double_number2, memory);
    memDEVres[10] = longDoubleDevide(longDouble_number1, longDouble_number2, memory);

    std::ofstream batch;

    batch.open("mybatchfile.bat", std::ios::out);

    batch << "@echo OFF" << std::endl;
    batch << "g++ plots.cpp pbPlots.cpp supportLib.cpp -lm -std=gnu++11 -o plots.exe" << std::endl;
    batch << ".\\plots" << " " << regADDres[0] << " " << regADDres[1] << " " << regADDres[2] << " " << regADDres[3] << " " << regADDres[4] << " " << regADDres[5] << " " << regADDres[6] << " " << regADDres[7] << " " << regADDres[8] << " " << regADDres[9] << " " << regADDres[10] << " "
                               << regSUBres[0] << " " << regSUBres[1] << " " << regSUBres[2] << " " << regSUBres[3] << " " << regSUBres[4] << " " << regSUBres[5] << " " << regSUBres[6] << " " << regSUBres[7] << " " << regSUBres[8] << " " << regSUBres[9] << " " << regSUBres[10] << " "
                               << regMULres[0] << " " << regMULres[1] << " " << regMULres[2] << " " << regMULres[3] << " " << regMULres[4] << " " << regMULres[5] << " " << regMULres[6] << " " << regMULres[7] << " " << regMULres[8] << " " << regMULres[9] << " " << regMULres[10] << " "
                               << regDEVres[0] << " " << regDEVres[1] << " " << regDEVres[2] << " " << regDEVres[3] << " " << regDEVres[4] << " " << regDEVres[5] << " " << regDEVres[6] << " " << regDEVres[7] << " " << regDEVres[8] << " " << regDEVres[9] << " " << regDEVres[10] << " "
                               << memADDres[0] << " " << memADDres[1] << " " << memADDres[2] << " " << memADDres[3] << " " << memADDres[4] << " " << memADDres[5] << " " << memADDres[6] << " " << memADDres[7] << " " << memADDres[8] << " " << memADDres[9] << " " << memADDres[10] << " "
                               << memSUBres[0] << " " << memSUBres[1] << " " << memSUBres[2] << " " << memSUBres[3] << " " << memSUBres[4] << " " << memSUBres[5] << " " << memSUBres[6] << " " << memSUBres[7] << " " << memSUBres[8] << " " << memSUBres[9] << " " << memSUBres[10] << " "
                               << memMULres[0] << " " << memMULres[1] << " " << memMULres[2] << " " << memMULres[3] << " " << memMULres[4] << " " << memMULres[5] << " " << memMULres[6] << " " << memMULres[7] << " " << memMULres[8] << " " << memMULres[9] << " " << memMULres[10] << " "
                               << memDEVres[0] << " " << memDEVres[1] << " " << memDEVres[2] << " " << memDEVres[3] << " " << memDEVres[4] << " " << memDEVres[5] << " " << memDEVres[6] << " " << memDEVres[7] << " " << memDEVres[8] << " " << memDEVres[9] << " " << memDEVres[10] << " "
        << std::endl;
    batch << "exit /b " << std::endl;

    batch.close();
    int retCode = system("mybatchfile.bat");
    //cout << "the return code is: " << retCode << endl;
    system("System_Performance1.png");
    system("System_Performance2.png");

    return 0;
}