#include <cstdint>
#include "Subtract.h"

#ifndef _SUBTRACTXFROMY_
#define _SUBTRACTXFROMY_

class SubtractXfromY: public Subtract
{
    public:
        SubtractXfromY(uint16_t opcode);        
        virtual std::string GetClassName() {return typeid(*this).name();};         

    private:
        SubtractXfromY() {};        
};

#endif