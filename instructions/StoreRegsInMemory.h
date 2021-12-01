#include <cstdint>
#include "InstructionBase.h"

#ifndef _STOREREGSINMEMORY_
#define _STOREREGSINMEMORY_

class StoreRegsInMemory: public InstructionBase
{
    public:
        StoreRegsInMemory(uint16_t opcode);

        virtual void Execute(Chip8* chip8);
        virtual std::string GetClassName() {return typeid(*this).name();};

    protected:        
        uint8_t theMaxRegToStore;

    private:
        StoreRegsInMemory() {};        
};

#endif