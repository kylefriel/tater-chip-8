#include "../Chip8.h"
#include "SkipIfXYNotEqual.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SkipIfXYNotEqual::SkipIfXYNotEqual(uint16_t opcode)
    :theXReg(SECOND_NIBBLE(opcode)),
     theYReg(THIRD_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void SkipIfXYNotEqual::Execute(Chip8* chip8)
{
    uint8_t xRegVal = chip8->GetVReg(theXReg);
    uint8_t yRegVal = chip8->GetVReg(theYReg);
    if (xRegVal != yRegVal)
    {
        chip8->MovePcToNextInstruction();            
    }    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%