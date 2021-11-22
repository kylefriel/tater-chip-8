#include "../Chip8.h"
#include "AddWithCarry.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
AddWithCarry::AddWithCarry(uint16_t opcode)
    :theXReg(SECOND_NIBBLE(opcode)),
     theYReg(THIRD_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void AddWithCarry::Execute(Chip8* chip8)
{
    uint8_t valX = chip8->GetVReg(theXReg);
    uint8_t valY = chip8->GetVReg(theYReg);
    uint8_t newVal;    

    if (__builtin_add_overflow(valX, valY, &newVal))
    {
        // overflow detected
        chip8->SetFlagReg(1);
    }
    else
    {
        // no overflow detected
        chip8->SetFlagReg(0);
    }

    chip8->SetVReg(theXReg, newVal);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%