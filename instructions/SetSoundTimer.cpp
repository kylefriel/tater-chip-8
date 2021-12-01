#include "../Chip8.h"
#include "SetSoundTimer.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SetSoundTimer::SetSoundTimer(uint16_t opcode)
    :theReg(SECOND_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void SetSoundTimer::Execute(Chip8* chip8)
{
    uint8_t value = chip8->GetVReg(theReg);
    chip8->SetSoundTimerCounter(value);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%