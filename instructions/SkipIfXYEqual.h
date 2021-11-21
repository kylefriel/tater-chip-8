#include <cstdint>
#include "InstructionBase.h"

#ifndef _SKIPIFXYEQUAL_
#define _SKIPIFXYEQUAL_

class SkipIfXYEqual: public InstructionBase
{
    public:
        SkipIfXYEqual(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:        
        uint8_t theXReg;
        uint8_t theYReg;

    private:
        SkipIfXYEqual() {};        
};

#endif