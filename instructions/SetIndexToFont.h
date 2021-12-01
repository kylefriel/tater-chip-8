#include <cstdint>
#include "InstructionBase.h"

#ifndef _SETINDEXTOFONT_
#define _SETINDEXTOFONT_

class SetIndexToFont: public InstructionBase
{
    public:
        SetIndexToFont(uint16_t opcode);

        virtual void Execute(Chip8* chip8);  
        virtual std::string GetClassName() {return typeid(*this).name();};      

    protected:        
        uint16_t theReg;

    private:
        SetIndexToFont() {};        
};

#endif