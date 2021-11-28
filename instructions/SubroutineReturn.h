#include <cstdint>
#include "InstructionBase.h"

#ifndef _SUBROUTINERETURN_
#define _SUBROUTINERETURN_

class SubroutineReturn: public InstructionBase
{
    public:
        SubroutineReturn();

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};        
};

#endif