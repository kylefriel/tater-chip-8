#include <cstdint>
#include "InstructionBase.h"

#ifndef _SHIFTRIGHT_
#define _SHIFTRIGHT_

class ShiftRight: public InstructionBase
{
    public:
        ShiftRight(uint16_t opcode);

        virtual void Execute(Chip8* chip8);   
        virtual std::string GetClassName() {return typeid(*this).name();};     

    protected:
        uint16_t theXReg;    
        uint16_t theYReg;

    private:
        ShiftRight() {};        
};

#endif