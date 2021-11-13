#include <cstdint>
#include "InstructionBase.h"

#ifndef _ADD_
#define _ADD_

class Add: public InstructionBase
{
    public:
        Add(uint16_t opcode);

        virtual void Execute(Chip8* chip8);        

    protected:
        uint16_t theReg;    
        uint8_t theValue;

    private:
        Add() {};        
};

#endif