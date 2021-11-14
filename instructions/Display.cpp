#include "../Chip8.h"
#include "../Chip8Display.h"
#include "Display.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Display::Display(uint16_t opcode)
    :theXReg(SECOND_NIBBLE(opcode)),
     theYReg(THIRD_NIBBLE(opcode)),
     thePixelHeight(FOURTH_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Display::Display() 
    :theXReg(0),
     theYReg(0),
     thePixelHeight(0)
{
};
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Display::Execute(Chip8* chip8)
{
    const uint16_t xStart      = (chip8->GetVReg(theXReg)%DISPLAY_WIDTH);
    const uint16_t yStart      = (chip8->GetVReg(theYReg)%DISPLAY_HEIGHT);    
    uint16_t memIndex          = chip8->GetIReg();
    const uint16_t memEnd      = memIndex + thePixelHeight;

    chip8->SetFlagReg(0);
    Chip8Display::Chip8DisplayGrid d = chip8->GetDisplay().GetDisplayGrid();

    for (uint8_t y = yStart ; memIndex < memEnd ; memIndex++, y++)  
    {
        uint8_t spriteData = chip8->GetMemory(memIndex);        
        for (uint8_t bit = 0, x = xStart ; bit < sizeof(uint8_t) ; bit++, x++)   
        {
            bool isPixelOn = GetPixelStateFromSprite(spriteData, bit);
            if (x < DISPLAY_WIDTH && y < DISPLAY_HEIGHT)
            {
                if (isPixelOn)
                {
                    if (d[x][y])
                    {
                        // display pixel is already on and sprite data is on so flip it
                        d[x][y] = false;
                        chip8->SetFlagReg(1);
                    }
                    else
                    {
                        // turn on the pixel on
                        d[x][y] = true;
                    }
                }
            }
        } 
    }    

    chip8->GetDisplay().Draw();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Display::GetPixelStateFromSprite(uint8_t sprite, uint8_t index)
{
    // get the state of the bit as a boolean    
    return (0 == sprite & (1 >> index)) ? false : true;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%