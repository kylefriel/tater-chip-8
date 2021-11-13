#include <cstdint>
#include "InstructionBase.h"

#ifndef _SETINDEX_
#define _SETINDEX_

class SetIndex: public InstructionBase
{
    public:
        SetIndex(uint16_t opcode);

        virtual void Execute(Chip8* chip8);        

    protected:        
        uint16_t theValue;

    private:
        SetIndex() {};        
};

#endif