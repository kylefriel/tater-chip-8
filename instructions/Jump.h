#include <cstdint>
#include "InstructionBase.h"

#ifndef _JUMP_
#define _JUMP_

class Jump: public InstructionBase
{
    public:
        Jump(uint16_t opcode);

        virtual void Execute(Chip8* chip8);        

    protected:
        uint16_t theJumpPc;    

    private:
        Jump() {};        
};

#endif