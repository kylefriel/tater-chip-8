#include "../Chip8.h"
#include "AddToIndex.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
AddToIndex::AddToIndex(uint16_t opcode)
    :theReg(SECOND_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void AddToIndex::Execute(Chip8* chip8)
{
    uint8_t regVal = chip8->GetVReg(theReg);
    uint16_t currentIndex = chip8->GetIReg();
    uint16_t newIndex;

    if (__builtin_add_overflow(currentIndex, regVal, &newIndex))
    {
        // overflow detected
        chip8->SetFlagReg(1);
    }
    else
    {
        // no overflow detected
        chip8->SetFlagReg(0);
    }

    chip8->SetIReg(newIndex);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%