#include <stdio.h>
#include "instructions/InstructionBase.h"
#include "instructions/ClearScreen.h"
#include "instructions/Display.h"
#include "instructions/Jump.h"
#include "instructions/Set.h"
#include "instructions/Add.h"
#include "instructions/SetIndex.h"
#include "InstructionFactory.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
InstructionFactory::InstructionFactory()
{    
    // populate the map to the function pointers
    theFirstNibbleMap.emplace(0x0, InstructionFactory::Process0);
    theFirstNibbleMap.emplace(0x1, InstructionFactory::Process1);
    theFirstNibbleMap.emplace(0x3, InstructionFactory::Process3);
    theFirstNibbleMap.emplace(0x6, InstructionFactory::Process6);
    theFirstNibbleMap.emplace(0x7, InstructionFactory::Process7);
    theFirstNibbleMap.emplace(0x8, InstructionFactory::Process8);
    theFirstNibbleMap.emplace(0xA, InstructionFactory::ProcessA);
    theFirstNibbleMap.emplace(0xB, InstructionFactory::ProcessB);
    theFirstNibbleMap.emplace(0xC, InstructionFactory::ProcessC);
    theFirstNibbleMap.emplace(0xD, InstructionFactory::ProcessD);
    theFirstNibbleMap.emplace(0xE, InstructionFactory::ProcessE);
    theFirstNibbleMap.emplace(0xF, InstructionFactory::ProcessF);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::GetInstruction(const uint16_t opcode)
{
    std::map<uint16_t, InstructionCreateFunc>::iterator it = theFirstNibbleMap.find(FIRST_NIBBLE(opcode));
    if (it != theFirstNibbleMap.end())
    {        
        return ((*it->second)(opcode));
    }

    return 0;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process0(const uint16_t opcode)
{
    if (0x00e0 == opcode)
    {        
        return (std::shared_ptr<InstructionBase>(new ClearScreen()));
    }
    
    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process1(const uint16_t opcode)
{        
    return std::shared_ptr<InstructionBase>(new Jump(opcode));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process3(const uint16_t opcode)
{
    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process6(const uint16_t opcode)
{        
    return std::shared_ptr<InstructionBase>(new Set(opcode));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process7(const uint16_t opcode)
{    
    return std::shared_ptr<InstructionBase>(new Add(opcode));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process8(const uint16_t opcode)
{
    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessA(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new SetIndex(opcode));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessB(const uint16_t opcode)
{
    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessC(const uint16_t opcode)
{
    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessD(const uint16_t opcode)
{    
    return std::shared_ptr<InstructionBase>(new Display(opcode));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessE(const uint16_t opcode)
{
    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessF(const uint16_t opcode)
{
    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%