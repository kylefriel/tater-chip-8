#include "../Chip8.h"
#include "Add.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Add::Add(uint16_t opcode)
    :theReg(SECOND_NIBBLE(opcode)),
     theValue(opcode & 0x00ff)
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Add::Execute(Chip8* chip8)
{    
    uint8_t initRegValue = chip8->GetVReg(theReg);
    chip8->SetVReg(theReg, initRegValue + theValue);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%