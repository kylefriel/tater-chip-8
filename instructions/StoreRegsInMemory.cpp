#include "../Chip8.h"
#include "StoreRegsInMemory.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
StoreRegsInMemory::StoreRegsInMemory(uint16_t opcode)
    :theMaxRegToStore(SECOND_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void StoreRegsInMemory::Execute(Chip8* chip8)
{
    uint16_t memIndex = chip8->GetIReg();
    for (uint8_t r = 0 ; r <= theMaxRegToStore ; r++, memIndex++)    
    {
        uint8_t value = chip8->GetVReg(r);                
        chip8->SetMemory(memIndex, value);
    }    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%