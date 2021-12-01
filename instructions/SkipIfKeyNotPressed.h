#include <cstdint>
#include "InstructionBase.h"

#ifndef _SKIPIFKEYNOTPRESSED_
#define _SKIPIFKEYNOTPRESSED_

class SkipIfKeyNotPressed: public InstructionBase
{
    public:
        SkipIfKeyNotPressed(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:        
        uint8_t theReg;

    private:
        SkipIfKeyNotPressed() {};        
};

#endif