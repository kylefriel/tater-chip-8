#include <cstdint>
#include "Subtract.h"

#ifndef _SUBTRACTYFROMX_
#define _SUBTRACTYFROMX_

class SubtractYfromX: public Subtract
{
    public:
        SubtractYfromX(uint16_t opcode);        
        virtual std::string GetClassName() {return typeid(*this).name();};         

    private:
        SubtractYfromX() {};        
};

#endif