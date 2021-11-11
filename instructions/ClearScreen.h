#include "InstructionBase.h"

#ifndef _CLEARSCREEN_
#define _CLEARSCREEN_

class ClearScreen: public InstructionBase
{
    public:
        ClearScreen();

        virtual void Execute(Chip8* chip8);        
};

#endif