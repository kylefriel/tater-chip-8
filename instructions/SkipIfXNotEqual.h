#include <cstdint>
#include "InstructionBase.h"

#ifndef _SKIPIFXNOTEQUAL_
#define _SKIPIFXNOTEQUAL_

class SkipIfXNotEqual: public InstructionBase
{
    public:
        SkipIfXNotEqual(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:
        uint8_t theValue;
        uint8_t theReg;

    private:
        SkipIfXNotEqual() {};        
};

#endif