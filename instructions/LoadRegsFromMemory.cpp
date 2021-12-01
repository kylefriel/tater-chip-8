#include "../Chip8.h"
#include "LoadRegsFromMemory.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
LoadRegsFromMemory::LoadRegsFromMemory(uint16_t opcode)
    :theMaxRegToStore(SECOND_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void LoadRegsFromMemory::Execute(Chip8* chip8)
{
    uint16_t memIndex = chip8->GetIReg();
    for (uint8_t r = 0 ; r <= theMaxRegToStore ; r++, memIndex++)    
    {
        uint8_t value = chip8->GetMemory(memIndex);
        chip8->SetVReg(r, value);                        
    }    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%