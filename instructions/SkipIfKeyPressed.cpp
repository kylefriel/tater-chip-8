#include "../Chip8.h"
#include "SkipIfKeyPressed.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SkipIfKeyPressed::SkipIfKeyPressed(uint16_t opcode)
    :theReg(SECOND_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void SkipIfKeyPressed::Execute(Chip8* chip8)
{
    uint8_t key = chip8->GetVReg(theReg);

    if (chip8->GetSdl().KeyPressed(key))    
    {
        chip8->MovePcToNextInstruction();            
    }    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%