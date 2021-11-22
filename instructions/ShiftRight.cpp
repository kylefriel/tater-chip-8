#include "../Chip8.h"
#include "ShiftRight.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
ShiftRight::ShiftRight(uint16_t opcode)
    :theXReg(SECOND_NIBBLE(opcode)),
     theYReg(THIRD_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void ShiftRight::Execute(Chip8* chip8)
{
    uint8_t valX = chip8->GetVReg(theXReg);
    uint16_t flag = (valX & 0x1 == 0x1) ? 1 : 0;
    valX >>= 1;

    chip8->SetVReg(theXReg, valX);
    chip8->SetFlagReg(flag);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%