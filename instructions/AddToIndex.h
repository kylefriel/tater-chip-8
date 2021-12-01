#include <cstdint>
#include "InstructionBase.h"

#ifndef _ADDTOINDEX_
#define _ADDTOINDEX_

class AddToIndex: public InstructionBase
{
    public:
        AddToIndex(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:        
        uint16_t theReg;

    private:
        AddToIndex() {};        
};

#endif