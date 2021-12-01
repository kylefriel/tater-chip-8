#include <cstdint>
#include "InstructionBase.h"

#ifndef _SETXTODELAYTIMER_
#define _SETXTODELAYTIMER_

class SetXToDelayTimer: public InstructionBase
{
    public:
        SetXToDelayTimer(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:
        uint16_t theReg;            

    private:
        SetXToDelayTimer() {};        
};

#endif