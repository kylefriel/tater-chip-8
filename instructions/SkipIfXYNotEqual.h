#include <cstdint>
#include "InstructionBase.h"

#ifndef _SKIPIFXYNOTEQUAL_
#define _SKIPIFXYNOTEQUAL_

class SkipIfXYNotEqual: public InstructionBase
{
    public:
        SkipIfXYNotEqual(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:        
        uint8_t theXReg;
        uint8_t theYReg;

    private:
        SkipIfXYNotEqual() {};        
};

#endif