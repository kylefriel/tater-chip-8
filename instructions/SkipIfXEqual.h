#include <cstdint>
#include "InstructionBase.h"

#ifndef _SKIPIFXEQUAL_
#define _SKIPIFXEQUAL_

class SkipIfXEqual: public InstructionBase
{
    public:
        SkipIfXEqual(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:
        uint8_t theValue;
        uint8_t theReg;

    private:
        SkipIfXEqual() {};        
};

#endif