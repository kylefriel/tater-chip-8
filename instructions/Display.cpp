#include "../Chip8.h"
#include "Display.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Display::Display(uint16_t xReg, uint16_t yReg, uint16_t nReg)
    :theXReg(xReg),
     theYReg(yReg),
     theNReg(nReg)
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Display::Execute(Chip8* chip8)
{
    uint16_t x = chip8->GetVReg(theXReg);
    uint16_t y = chip8->GetVReg(theYReg);
    uint16_t n = chip8->GetVReg(theNReg);

    chip8->GetDisplay().Draw(x, y, n);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%