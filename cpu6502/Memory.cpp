#include "Memory.h"

void Memory::Initialize() 
{
	for (u32 i = 0; i < MAX_MEM; ++i)
	{
		data[i] = 0;
	}
}