#include "../Chip8.h"
#include "SetXToDelayTimer.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SetXToDelayTimer::SetXToDelayTimer(uint16_t opcode)
    :theReg(SECOND_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void SetXToDelayTimer::Execute(Chip8* chip8)
{
    uint8_t value = chip8->GetDelayTimerCounter();
    chip8->SetVReg(theReg, value);    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%