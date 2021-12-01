#include <cstdint>
#include <memory>
#include <map>

#ifndef _INSTRUCTIONFACTORY_
#define _INSTRUCTIONFACTORY_
class InstructionBase;

class InstructionFactory
{
    public:
        
        typedef std::shared_ptr<InstructionBase> (*InstructionCreateFunc) (uint16_t);

        InstructionFactory();
        std::shared_ptr<InstructionBase> GetInstruction(const uint16_t opcode);

    protected:
    
        static std::map<uint16_t, InstructionCreateFunc> theFirstNibbleMap;
        static std::shared_ptr<InstructionBase> Process0(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process1(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process2(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process3(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process4(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process5(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process6(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process7(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process8(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process9(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessA(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessB(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessC(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessD(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessE(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessF(const uint16_t opcode);

        static std::map<uint16_t, InstructionCreateFunc> theLogicalOperationsMap;
        static std::shared_ptr<InstructionBase> Process8XY0(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process8XY1(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process8XY2(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process8XY3(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process8XY4(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process8XY5(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process8XY7(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process8XY6(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> Process8XYE(const uint16_t opcode);

        static std::map<uint16_t, InstructionCreateFunc> theFxMap;
        static std::shared_ptr<InstructionBase> ProcessFX07(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessFX15(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessFX18(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessFX1E(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessFX0A(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessFX29(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessFX33(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessFX55(const uint16_t opcode);
        static std::shared_ptr<InstructionBase> ProcessFX65(const uint16_t opcode);
        
};

#endif