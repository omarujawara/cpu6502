#pragma once
#include "Datatypes.h"
#include <cassert>
struct Memory
{
    static constexpr u32 MAX_MEM = (1024 * 64); // 64 kilobytes(KB) - 64,536 bytes max memory 
    byte data[MAX_MEM]{};                       // Initialize all to zero

    void Initialize();

    // operator [] overloading
    // Read 1 byte
    byte operator[](u32 index) const
    {
        assert(index < MAX_MEM && "Array index out of bounds");
        return data[index];
    }
    // Write 1 byte
    byte& operator[](u32 index)
    {
        assert(index < MAX_MEM && "Array index out of bounds");
        return data[index];
    }
};