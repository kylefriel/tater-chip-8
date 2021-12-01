#include <cstdint>
#include "InstructionBase.h"

#ifndef _LOADREGSFROMMEMORY_
#define _LOADREGSFROMMEMORY_

class LoadRegsFromMemory: public InstructionBase
{
    public:
        LoadRegsFromMemory(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:        
        uint8_t theMaxRegToStore;

    private:
        LoadRegsFromMemory() {};        
};

#endif