#include <cstdint>
#include "InstructionBase.h"

#ifndef _BINARYAND_
#define _BINARYAND_

class BinaryAnd: public InstructionBase
{
    public:
        BinaryAnd(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:
        uint8_t theXReg;
        uint8_t theYReg;

    private:
        BinaryAnd() {};        
};

#endif