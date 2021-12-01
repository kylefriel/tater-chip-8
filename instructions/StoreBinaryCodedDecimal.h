#include <cstdint>
#include "InstructionBase.h"

#ifndef _STOREBINARYCODEDDECIMAL_
#define _STOREBINARYCODEDDECIMAL_

class StoreBinaryCodedDecimal: public InstructionBase
{
    public:
        StoreBinaryCodedDecimal(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:        
        uint8_t theReg;

    private:
        StoreBinaryCodedDecimal() {};        
};

#endif