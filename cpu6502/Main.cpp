#include <stdio.h>
#include "Memory.h"
#include "CPU.h"

int main()
{
    puts("6502 Processor\n");

    Memory mem;
    CPU cpu;
    // cpu.Reset(mem);
    // Test
    // mem[0xFFFC] = CPU::INS_LDA_IM;
    // mem[0xfffd] = 0x42;
    // End Test
    // cpu.Execute(2, mem);
}

 