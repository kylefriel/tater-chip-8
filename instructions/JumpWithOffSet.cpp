#include "../Chip8.h"
#include "JumpWithOffSet.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
JumpWithOffSet::JumpWithOffSet(uint16_t opcode)
    :theJumpPc(LS_THREE_NIBBLES(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void JumpWithOffSet::Execute(Chip8* chip8)
{
    uint8_t val = chip8->GetVReg(0);
    chip8->SetPc(theJumpPc + val);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%