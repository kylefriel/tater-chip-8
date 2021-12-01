#include <cstdint>
#include "InstructionBase.h"

#ifndef _GETKEY_
#define _GETKEY_

class GetKey: public InstructionBase
{
    public:
        GetKey(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:        
        uint8_t theReg;

    private:
        GetKey() {};        
};

#endif