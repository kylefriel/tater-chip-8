#include <cstdint>
#include <map>

#ifndef _INSTRUCTIONFACTORY_
#define _INSTRUCTIONFACTORY_
class InstructionBase;

class InstructionFactory
{
    public:
        
        typedef InstructionBase* (*InstructionCreateFunc) (uint16_t);

        InstructionFactory();
        InstructionBase* GetInstruction(const uint16_t opcode);

    protected:

        

        std::map<uint16_t, InstructionCreateFunc> theFirstNibbleMap;
        static InstructionBase* Process0(const uint16_t opcode);
        static InstructionBase* Process1(const uint16_t opcode);
        static InstructionBase* Process3(const uint16_t opcode);
        static InstructionBase* Process6(const uint16_t opcode);
        static InstructionBase* Process7(const uint16_t opcode);
        static InstructionBase* Process8(const uint16_t opcode);
        static InstructionBase* ProcessA(const uint16_t opcode);
        static InstructionBase* ProcessB(const uint16_t opcode);
        static InstructionBase* ProcessC(const uint16_t opcode);
        static InstructionBase* ProcessD(const uint16_t opcode);
        static InstructionBase* ProcessE(const uint16_t opcode);
        static InstructionBase* ProcessF(const uint16_t opcode);

        static InstructionBase* CreateClearScreen(const uint16_t opcode);
        static InstructionBase* CreateJump(const uint16_t opcode);
        static InstructionBase* CreateSetReg(const uint16_t opcode);
        static InstructionBase* CreateAddValToReg(const uint16_t opcode);
        static InstructionBase* CreateSetIndex(const uint16_t opcode);
        static InstructionBase* CreateDisplay(const uint16_t opcode);
        
        
};

#endif