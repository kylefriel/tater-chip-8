#include <cstdint>
#include "InstructionBase.h"

#ifndef _BINARYOR_
#define _BINARYOR_

class BinaryOr: public InstructionBase
{
    public:
        BinaryOr(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:
        uint8_t theXReg;
        uint8_t theYReg;

    private:
        BinaryOr() {};        
};

#endif