#include <cstdint>
#include "InstructionBase.h"

#ifndef _LOGICALXOR_
#define _LOGICALXOR_

class LogicalXor: public InstructionBase
{
    public:
        LogicalXor(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:
        uint8_t theXReg;
        uint8_t theYReg;

    private:
        LogicalXor() {};        
};

#endif