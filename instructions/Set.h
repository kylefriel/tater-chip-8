#include <cstdint>
#include "InstructionBase.h"

#ifndef _SET_
#define _SET_

class Set: public InstructionBase
{
    public:
        Set(uint16_t opcode);

        virtual void Execute(Chip8* chip8);        

    protected:
        uint16_t theReg;    
        uint8_t theValue;

    private:
        Set() {};        
};

#endif