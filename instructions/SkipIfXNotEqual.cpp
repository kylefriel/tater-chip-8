#include "../Chip8.h"
#include "SkipIfXNotEqual.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SkipIfXNotEqual::SkipIfXNotEqual(uint16_t opcode)
    :theReg(SECOND_NIBBLE(opcode)),
     theValue(LS_BYTE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void SkipIfXNotEqual::Execute(Chip8* chip8)
{
    uint8_t regVal = chip8->GetVReg(theReg);
    if (regVal != theValue)
    {
        chip8->MovePcToNextInstruction();            
    }    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%