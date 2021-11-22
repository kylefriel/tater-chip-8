#include <cstdint>
#include "InstructionBase.h"

#ifndef _RANDOM_
#define _RANDOM_

class Random: public InstructionBase
{
    public:
        Random(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:
        uint8_t theXReg;
        uint8_t theNnVal;

    private:
        Random() {};        
};

#endif