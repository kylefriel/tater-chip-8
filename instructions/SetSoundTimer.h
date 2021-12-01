#include <cstdint>
#include "InstructionBase.h"

#ifndef _SETSOUNDTIMER_
#define _SETSOUNDTIMER_

class SetSoundTimer: public InstructionBase
{
    public:
        SetSoundTimer(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:
        uint16_t theReg;            

    private:
        SetSoundTimer() {};        
};

#endif