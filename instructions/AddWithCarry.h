#include <cstdint>
#include "InstructionBase.h"

#ifndef _ADDWITHCARRY_
#define _ADDWITHCARRY_

class AddWithCarry: public InstructionBase
{
    public:
        AddWithCarry(uint16_t opcode);

        virtual void Execute(Chip8* chip8);   
        virtual std::string GetClassName() {return typeid(*this).name();};     

    protected:
        uint16_t theXReg;    
        uint16_t theYReg;

    private:
        AddWithCarry() {};        
};

#endif