#include <cstdint>
#include "InstructionBase.h"

#ifndef _SETREG_
#define _SETREG_

class SetReg: public InstructionBase
{
    public:
        SetReg(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:
        uint16_t theReg;    
        uint8_t theValue;

    private:
        SetReg() {};        
};

#endif