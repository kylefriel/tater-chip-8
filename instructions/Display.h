#include <cstdint>
#include "InstructionBase.h"

#ifndef _DISPLAY_
#define _DISPLAY_

class Display: public InstructionBase
{
    public:
        Display (uint16_t opcode);

        virtual void Execute(Chip8* chip8);

    protected:
        int theXReg;
        int theYReg;        
        int theNReg;        

    private:
        Display() {};
};

#endif