#include "../Chip8.h"
#include "StoreBinaryCodedDecimal.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
StoreBinaryCodedDecimal::StoreBinaryCodedDecimal(uint16_t opcode)
    :theReg(SECOND_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void StoreBinaryCodedDecimal::Execute(Chip8* chip8)
{
    uint8_t value = chip8->GetVReg(theReg);    
    uint16_t memIndex = chip8->GetIReg();    

    chip8->SetMemory(memIndex, value / 100);
    chip8->SetMemory(memIndex + 1, (value % 100) / 10);
    chip8->SetMemory(memIndex + 2, value % 10);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%