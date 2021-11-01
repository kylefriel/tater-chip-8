#include <cstdint>

#ifndef _INSTRUCTIONFACTORY_
#define _INSTRUCTIONFACTORY_
class InstructionBase;

class InstructionFactory
{
    public:
        InstructionFactory();

        InstructionBase* GetInstruction(uint16_t opcode);
};

#endif