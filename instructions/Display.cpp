#include <bitset>
#include "../Chip8.h"
#include "../Chip8SdlWrapper.h"
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

    for (uint8_t y = yStart ; memIndex < memEnd ; memIndex++, y++)  
    {
        uint8_t spriteData = chip8->GetMemory(memIndex);        

        std::bitset<8> bits(spriteData);

        for (uint8_t bit = 0, x = xStart ; bit < 8 ; bit++, x++)   
        {                            
            bool isPixelOn = bits.test(0x7 - bit);
            if (x < DISPLAY_WIDTH && y < DISPLAY_HEIGHT)
            {
                if (isPixelOn)
                {                    
                    if (chip8->GetSdl().GetGridPointState(x, y))
                    {
                        // display pixel is already on and sprite data is on so flip it
                        chip8->GetSdl().SetGridPointState(x, y, false);
                        chip8->SetFlagReg(1);
                    }
                    else
                    {
                        // turn on the pixel on                        
                        chip8->GetSdl().SetGridPointState(x, y, true);
                    }
                }
            }
        } 
    }    

    chip8->GetSdl().Draw();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%