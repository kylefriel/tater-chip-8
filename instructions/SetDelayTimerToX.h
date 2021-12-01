#include <cstdint>
#include "InstructionBase.h"

#ifndef _SETDELAYTIMERTOX_
#define _SETDELAYTIMERTOX_

class SetDelayTimerToX: public InstructionBase
{
    public:
        SetDelayTimerToX(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:
        uint16_t theReg;            

    private:
        SetDelayTimerToX() {};        
};

#endif