#include <cstdint>
#include "InstructionBase.h"

#ifndef _SKIPIFKEYPRESSED_
#define _SKIPIFKEYPRESSED_

class SkipIfKeyPressed: public InstructionBase
{
    public:
        SkipIfKeyPressed(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:        
        uint8_t theReg;

    private:
        SkipIfKeyPressed() {};        
};

#endif