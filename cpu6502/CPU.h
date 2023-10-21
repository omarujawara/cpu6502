#pragma once
#include "Datatypes.h"
#include "Memory.h"

// 6502 Proccessor
struct CPU
{
    word PC; // Program Counter
    word SP; // Stack Pointer

    // Three 8 bits registers 
    byte A; // A -> Accumulator
    byte X; // X -> Index Register X
    byte Y; // Y -> Index Register Y

    /*
        Proccessor Status Flags
        Using the bit-field feature to occupy 1 bit for each flag
    */
    byte C : 1; // CARRY FLAG 0=FALSE 1=TRUE
    byte Z : 1; // ZERO FLAG 0=RESULT NOT ZERO 1=RESULT ZERO
    byte I : 1; // IRQ DISABLE FLAG 0=ENABLE 1=DISABLE
    byte D : 1; // DECIMAL MODE FLAG 0=FALSE 1=TRUE
    byte B : 1; // BREAK COMMAND FLAG 0= NO BREAK 1=BREAK
    byte V : 1; // OVERFLOW FLAG 0=FALSE 1=TRUE
    byte N : 1; // MEGATIVE FLAGE 0=POSITIVE 1=NEGATIVE

    // opcodes
     static constexpr byte INS_LDA_IM = 0xA9; // Load Accumulator (Immediate)

    // Methods
   void Reset(Memory& mem);

   byte FetchByte(u32& cycles, Memory& memory);

   void Execute(u32 cycles, Memory& memory);

};
