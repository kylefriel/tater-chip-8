#include <cstdint>
#include "InstructionBase.h"

#ifndef _SHIFTLEFT_
#define _SHIFTLEFT_

class ShiftLeft: public InstructionBase
{
    public:
        ShiftLeft(uint16_t opcode);

        virtual void Execute(Chip8* chip8);   
        virtual std::string GetClassName() {return typeid(*this).name();};     

    protected:
        uint16_t theXReg;    
        uint16_t theYReg;

    private:
        ShiftLeft() {};        
};

#endif