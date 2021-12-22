#include "asmOperations.h"


double shortAdd(short a, short b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov ax, a;
                mov bx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                add ax, bx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov ax, a;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                add ax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsShortAdd(unsigned short a, unsigned short b, bool regsOrMem)

{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov ax, a;
                mov bx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                add ax, bx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov ax, a;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                add ax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double intAdd(int a, int b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                add eax, ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                add eax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsIntAdd(unsigned int a, unsigned int b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                add eax, ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                add eax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longAdd(long a, long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                add eax, ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                add eax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsLongAdd(unsigned long a, unsigned long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                add eax, ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                add eax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longLongAdd(long long a, long long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop edx;
                pop ebx;
                pop ecx;

                add eax, ebx;
                add edx, ecx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                push eax;
                push edx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop edx;
                add eax, dword ptr[b + 0];
                add edx, dword ptr[b + 4];

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsLongLongAdd(unsigned long long a, unsigned long long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop edx;
                pop ebx;
                pop ecx;

                add eax, ebx;
                add edx, ecx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                push eax;
                push edx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop edx;
                add eax, dword ptr[b + 0];
                add edx, dword ptr[b + 4];

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double floatAdd(float a, float b, bool regsOrMem){
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fadd

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fadd

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double doubleAdd(double a, double b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fadd

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fadd

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longDoubleAdd(long double a, long double b, bool regsOrMem)

{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fadd

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fadd

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Сложение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}




double shortSubtract(short a, short b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov ax, a;
                mov bx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                sub ax, bx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov ax, a;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                sub ax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsShortSubtract(unsigned short a, unsigned short b, bool regsOrMem)

{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov ax, a;
                mov bx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                sub ax, bx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov ax, a;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                sub ax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double intSubtract(int a, int b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                sub eax, ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                sub eax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsIntSubtract(unsigned int a, unsigned int b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                sub eax, ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                sub eax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longSubtract(long a, long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                sub eax, ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                sub eax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsLongSubtract(unsigned long a, unsigned long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                sub eax, ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                sub eax, b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longLongSubtract(long long a, long long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop edx;
                pop ebx;
                pop ecx;

                sub eax, ebx;
                sub edx, ecx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                push eax;
                push edx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop edx;
                sub eax, dword ptr[b + 0];
                sub edx, dword ptr[b + 4];

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsLongLongSubtract(unsigned long long a, unsigned long long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop edx;
                pop ebx;
                pop ecx;

                sub eax, ebx;
                sub edx, ecx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                push eax;
                push edx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop edx;
                sub eax, dword ptr[b + 0];
                sub edx, dword ptr[b + 4];

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double floatSubtract(float a, float b, bool regsOrMem) {
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fsub

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fsub

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double doubleSubtract(double a, double b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fsub

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fsub

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longDoubleSubtract(long double a, long double b, bool regsOrMem)

{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fsub

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fsub

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Вычитание " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}




double shortMultiply(short a, short b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov ax, a;
                mov bx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                mul bx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov ax, a;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                mul b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsShortMultiply(unsigned short a, unsigned short b, bool regsOrMem)

{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov ax, a;
                mov bx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                mul bx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov ax, a;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                mul b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double intMultiply(int a, int b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                mul ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                mul b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsIntMultiply(unsigned int a, unsigned int b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                mul ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                mul b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longMultiply(long a, long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                mul ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                mul b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsLongMultiply(unsigned long a, unsigned long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                mul ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                mul b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longLongMultiply(long long a, long long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    unsigned long long res = 0;

    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop edx;
                pop ecx;

                mov eax, ecx;
                mul edx;
                add dword ptr[res + 4], eax;

                pop eax;
                push eax;
                mul ecx;
                add dword ptr[res + 4], eax;

                pop ebx;
                mov eax, ebx;
                mul edx;
                add dword ptr[res + 0], eax;
                pop eax;
                mul ebx;
                add dword ptr[res + 0], eax;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop edx;
                pop ecx;

                mov eax, ecx;
                mul edx;
                add dword ptr[res + 4], eax;

                pop eax;
                push eax;
                mul ecx;
                add dword ptr[res + 4], eax;

                pop ebx;
                mov eax, ebx;
                mul edx;
                add dword ptr[res + 0], eax;
                pop eax;
                mul ebx;
                add dword ptr[res + 0], eax;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsLongLongMultiply(unsigned long long a, unsigned long long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;

    unsigned long long res=0;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop edx;
                pop ecx;

                mov eax, ecx;
                mul edx;
                add dword ptr[res + 4], eax;

                pop eax;
                push eax;
                mul ecx;
                add dword ptr[res + 4], eax;

                pop ebx;
                mov eax, ebx;
                mul edx;
                add dword ptr[res + 0], eax;
                pop eax;
                mul ebx;
                add dword ptr[res + 0], eax;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop edx;
                pop ecx;

                mov eax, ecx;
                mul edx;
                add dword ptr[res + 4], eax;

                pop eax;
                push eax;
                mul ecx;
                add dword ptr[res + 4], eax;

                pop ebx;
                mov eax, ebx;
                mul edx;
                add dword ptr[res + 0], eax;
                pop eax;
                mul ebx;
                add dword ptr[res + 0], eax;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double floatMultiply(float a, float b, bool regsOrMem) {
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fmul

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fmul

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double doubleMultiply(double a, double b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fmul

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fmul

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longDoubleMultiply(long double a, long double b, bool regsOrMem)

{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fmul

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fmul

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Умножение " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}




double shortDevide(short a, short b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov ax, a;
                mov bx, b;
                push ax;
                push bx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop ax;
                pop bx;
                cwd
                div bx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov ax, a;
                push ax;
                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop ax;
                cwd
                div b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsShortDevide(unsigned short a, unsigned short b, bool regsOrMem)

{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov ax, a;
                mov bx, b;
                push ax;
                push bx;
                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop ax;
                pop bx;
                cwd
                div bx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov ax, a;
                push ax
                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop ax;
                cwd
                div b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double intDevide(int a, int b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;
                push eax;
                push ebx;
                
                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop ebx;
                cwd
                div ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                cwd
                div b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsIntDevide(unsigned int a, unsigned int b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;
                push eax;
                push ebx;
                

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop ebx;
                cwd
                div ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                cwd
                div b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longDevide(long a, long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;
                push eax;
                push ebx;
                
                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop ebx;
                cwd
                div ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                cwd
                div b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsLongDevide(unsigned long a, unsigned long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, a;
                mov ebx, b;
                push eax;
                push ebx;
                
                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop ebx;
                cwd
                div ebx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, a;
                push eax;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                cwd
                div b;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longLongDevide(long long a, long long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    unsigned long long res = 0;

    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop ebx;

                cwd
                div ebx;

                pop edx;
                pop ecx;

                mov eax, edx;
                cwd
                div ecx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop ebx;

                cwd
                div ebx;

                pop edx;
                pop ecx;

                mov eax, edx;
                cwd
                div ecx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double unsLongLongDevide(unsigned long long a, unsigned long long b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;

    unsigned long long res = 0;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop ebx;

                cwd
                div ebx;

                pop edx;
                pop ecx;

                mov eax, edx;
                cwd
                div ecx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                mov eax, dword ptr[a + 0];
                mov edx, dword ptr[a + 4];
                mov ebx, dword ptr[b + 0];
                mov ecx, dword ptr[b + 4];

                push eax;
                push edx;
                push ebx;
                push ecx;

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                pop eax;
                pop ebx;
                cwd
                div ebx;

                pop edx;
                pop ecx;

                mov eax, edx;
                cwd
                div ecx;

                cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double floatDevide(float a, float b, bool regsOrMem) {
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fdiv

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fdiv

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double doubleDevide(double a, double b, bool regsOrMem)
{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fdiv

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fdiv

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}

double longDoubleDevide(long double a, long double b, bool regsOrMem)

{
    uint64_t Low[10], Up[10];
    uint64_t theLow, theUp;
    theLow = 0;
    theUp = 0;
    uint64_t c, d;
    for (int i = 0; i < 10; i++) {
        if (regsOrMem) {
            __asm { //registers
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fdiv

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        else {  //memory
            __asm {
                finit
                fld a
                fld b

                cpuid;      // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[c + 0], eax;
                mov dword ptr[c + 4], edx;

                fdiv

                    cpuid;       // serialize processor
                rdtsc;      // read time stamp counter
                mov dword ptr[d + 0], eax;
                mov dword ptr[d + 4], edx;
            }
        }
        Low[i] = c;
        Up[i] = d;
    }
    for (int i = 0; i < 10; i++) {
        theLow += Low[i];
        theUp += Up[i];
    }
    std::cout << std::endl << "Деление " << typeid(a).name() << " чисел ";
    regsOrMem ? std::cout << "ИЗ РЕГИСТРОВ " : std::cout << "ИЗ ПАМЯТИ ";
    std::cout << "заняло примерно " << (theUp - theLow) / 10 << " тактов, " << std::endl;
    std::cout << "что примерно равно " << std::setprecision(10) << std::fixed << (double)(theUp - theLow) / 10 / PROC_FREQ << " секунд" << std::endl;
    return (double)(theUp - theLow) / 10 / PROC_FREQ * 10000000000;
}
