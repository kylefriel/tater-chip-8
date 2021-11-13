#include "../Chip8.h"
#include "../Chip8Display.h"
#include "Display.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Display::Display(uint16_t opcode)
    :theXReg(SECOND_NIBBLE(opcode)),
     theYReg(THIRD_NIBBLE(opcode)),
     theNReg(FOURTH_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Display::Execute(Chip8* chip8)
{
    const uint16_t x           = (chip8->GetVReg(theXReg)%DISPLAY_WIDTH);
    const uint16_t y           = (chip8->GetVReg(theYReg)%DISPLAY_HEIGHT);
    const uint16_t pixelHeight = chip8->GetVReg(theNReg);        
    const uint16_t memIndex    = chip8->GetIReg();

    chip8->SetFlagReg(0);
    Chip8Display::Chip8DisplayGrid d = chip8->GetDisplay().GetDisplayGrid();

    for (int i = 0 ; i < pixelHeight ; i++)    
    {

    }

    chip8->GetDisplay().Draw();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%