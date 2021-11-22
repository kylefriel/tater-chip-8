#include <cstdint>
#include "InstructionBase.h"

#ifndef _SUBTRACT_
#define _SUBTRACT_

class Subtract: public InstructionBase
{
    public:
        Subtract(uint16_t minuendReg, uint16_t subtrahendReg, uint16_t differenceReg);

        virtual void Execute(Chip8* chip8);   
        virtual std::string GetClassName() {return typeid(*this).name();};     

    protected:
        uint16_t theMinuendReg;    
        uint16_t theSubtrahendReg;
        uint16_t theDifferenceReg;

    protected:
        Subtract() {};        
};

#endif