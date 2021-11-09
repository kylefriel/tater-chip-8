#include "InstructionBase.h"

#ifndef _DISPLAY_
#define _DISPLAY_

class Display: public InstructionBase
{
    public:
        Display(uint16_t xReg, uint16_t yReg, uint16_t nReg);

        virtual void Execute(Chip8* chip8);

    protected:
        int theXReg;
        int theYReg;        
        int theNReg;        

    private:
        Display() {};
};

#endif