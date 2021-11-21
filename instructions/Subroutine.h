#include <cstdint>
#include "InstructionBase.h"

#ifndef _SUBROUTINE_
#define _SUBROUTINE_

class Subroutine: public InstructionBase
{
    public:
        Subroutine(uint16_t opcode);

        virtual void Execute(Chip8* chip8);        \
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:
        uint16_t theSubroutinePc;    

    private:
        Subroutine() {};        
};

#endif