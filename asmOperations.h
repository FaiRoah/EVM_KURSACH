#pragma once
#define PROC_FREQ 23000000000
#include <iostream>
#include <Windows.h>
#include <iomanip> 
#include <stdint.h>
#include <intrin.h>

enum MemoryOrRegisters
{
    memory = 0,
    registers = 1
};



double shortAdd(short a, short b, bool regsOrMem);

double unsShortAdd(unsigned short a, unsigned short b, bool regsOrMem);

double intAdd(int a, int b, bool regsOrMem);

double unsIntAdd(unsigned int a, unsigned int b, bool regsOrMem);

double longAdd(long a, long b, bool regsOrMem);

double unsLongAdd(unsigned long a, unsigned long b, bool regsOrMem);

double longLongAdd(long long a, long long b, bool regsOrMem);

double unsLongLongAdd(unsigned long long a, unsigned long long b, bool regsOrMem);

double floatAdd(float a, float b, bool regsOrMem); 

double doubleAdd(double a, double b, bool regsOrMem);

double longDoubleAdd(long double a, long double b, bool regsOrMem);




double shortSubtract(short a, short b, bool regsOrMem);

double unsShortSubtract(unsigned short a, unsigned short b, bool regsOrMem);

double intSubtract(int a, int b, bool regsOrMem);

double unsIntSubtract(unsigned int a, unsigned int b, bool regsOrMem);

double longSubtract(long a, long b, bool regsOrMem);

double unsLongSubtract(unsigned long a, unsigned long b, bool regsOrMem);

double longLongSubtract(long long a, long long b, bool regsOrMem);

double unsLongLongSubtract(unsigned long long a, unsigned long long b, bool regsOrMem);

double floatSubtract(float a, float b, bool regsOrMem);

double doubleSubtract(double a, double b, bool regsOrMem);

double longDoubleSubtract(long double a, long double b, bool regsOrMem);




double shortMultiply(short a, short b, bool regsOrMem);

double unsShortMultiply(unsigned short a, unsigned short b, bool regsOrMem);

double intMultiply(int a, int b, bool regsOrMem);

double unsIntMultiply(unsigned int a, unsigned int b, bool regsOrMem);

double longMultiply(long a, long b, bool regsOrMem);

double unsLongMultiply(unsigned long a, unsigned long b, bool regsOrMem);

double longLongMultiply(long long a, long long b, bool regsOrMem);

double unsLongLongMultiply(unsigned long long a, unsigned long long b, bool regsOrMem);

double floatMultiply(float a, float b, bool regsOrMem);

double doubleMultiply(double a, double b, bool regsOrMem);

double longDoubleMultiply(long double a, long double b, bool regsOrMem);




double shortDevide(short a, short b, bool regsOrMem);

double unsShortDevide(unsigned short a, unsigned short b, bool regsOrMem);

double intDevide(int a, int b, bool regsOrMem);

double unsIntDevide(unsigned int a, unsigned int b, bool regsOrMem);

double longDevide(long a, long b, bool regsOrMem);

double unsLongDevide(unsigned long a, unsigned long b, bool regsOrMem);

double longLongDevide(long long a, long long b, bool regsOrMem);

double unsLongLongDevide(unsigned long long a, unsigned long long b, bool regsOrMem);

double floatDevide(float a, float b, bool regsOrMem);

double doubleDevide(double a, double b, bool regsOrMem);

double longDoubleDevide(long double a, long double b, bool regsOrMem);