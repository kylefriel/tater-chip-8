#include <cstdint>
#include "InstructionBase.h"

#ifndef _DISPLAY_
#define _DISPLAY_

class Display: public InstructionBase
{
    public:
        Display (uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:        
    
    protected:
        const uint16_t theXReg;
        const uint16_t theYReg;        
        const uint8_t thePixelHeight;        

    private:
        Display();

};

#endif