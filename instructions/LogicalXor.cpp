#include "../Chip8.h"
#include "LogicalXor.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
LogicalXor::LogicalXor(uint16_t opcode)
    :theXReg(SECOND_NIBBLE(opcode)),
     theYReg(THIRD_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void LogicalXor::Execute(Chip8* chip8)
{
    uint8_t val = (chip8->GetVReg(theXReg) ^ chip8->GetVReg(theYReg));
    chip8->SetVReg(theXReg, val);    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%