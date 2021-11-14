#include <cstdint>
#include "InstructionBase.h"

#ifndef _SET_
#define _SET_

class Set: public InstructionBase
{
    public:
        Set(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:
        uint16_t theReg;    
        uint8_t theValue;

    private:
        Set() {};        
};

#endif