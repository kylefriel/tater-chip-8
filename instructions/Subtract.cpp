#include "../Chip8.h"
#include "Subtract.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Subtract::Subtract(uint16_t minuendReg, uint16_t subtrahendReg, uint16_t differenceReg)
    :theMinuendReg(minuendReg),
     theSubtrahendReg(subtrahendReg),
     theDifferenceReg(differenceReg)
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Subtract::Execute(Chip8* chip8)
{
    uint8_t valMinuend    = chip8->GetVReg(theMinuendReg);
    uint8_t valSubtrahend = chip8->GetVReg(theSubtrahendReg);
    uint8_t newVal;    

    if (__builtin_sub_overflow(valMinuend, valSubtrahend, &newVal))
    {
        // overflow detected
        chip8->SetFlagReg(0);
    }
    else
    {
        // no overflow detected
        chip8->SetFlagReg(1);
    }

    chip8->SetVReg(theDifferenceReg, newVal);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%