#include <stdio.h>
#include "CPU.h"
#include "memory.h"

void CPU::Reset(Memory& mem)
{
    PC = 0xFFFC;
    SP = 0x0100;
    D = 0;
    C = Z = I = D = B = V = N = 0;
    A = X = Y = 0;
    mem.Initialize();
}

byte CPU::FetchByte(u32& cycles, Memory& memory)
{
    byte Data = memory[PC];
    PC++;
    cycles--;
    return Data;
}

void CPU::Execute(u32 cycles, Memory& memory)
{
    while (cycles > 0)
    {
        byte Instruction = FetchByte(cycles, memory);
        switch (Instruction)
        {
        case INS_LDA_IM:
        {
            byte Value = FetchByte(cycles, memory);
            A = Value;                // set A register to Value
            Z = (A == 0);             // Set if A = 0
            N = (A & 0b10000000) > 0; // Set if bit 7 of A is set
        }
        break;

        default:
            printf("Instruction %d, not handled", Instruction);
            break;
        }
    }
}