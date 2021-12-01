#include <cstdint>
#include "InstructionBase.h"

#ifndef _JUMPWITHOFFSET_
#define _JUMPWITHOFFSET_

class JumpWithOffSet: public InstructionBase
{
    public:
        JumpWithOffSet(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:
        uint16_t theJumpPc;    

    private:
        JumpWithOffSet() {};        
};

#endif