#include <stdio.h>
#include "instructions/InstructionBase.h"
#include "instructions/ClearScreen.h"
#include "instructions/Display.h"
#include "instructions/Jump.h"
#include "instructions/SetReg.h"
#include "instructions/Add.h"
#include "instructions/SetIndex.h"
#include "instructions/Subroutine.h"
#include "instructions/SubroutineReturn.h"
#include "instructions/SkipIfXEqual.h"
#include "instructions/SkipIfXNotEqual.h"
#include "instructions/SkipIfXYEqual.h"
#include "instructions/SkipIfXYNotEqual.h"
#include "instructions/Set.h"
#include "instructions/BinaryOr.h"
#include "instructions/BinaryAnd.h"
#include "instructions/LogicalXor.h"
#include "instructions/AddWithCarry.h"
#include "instructions/SubtractYfromX.h"
#include "instructions/SubtractXfromY.h"
#include "instructions/ShiftLeft.h"
#include "instructions/ShiftRight.h"
#include "instructions/JumpWithOffSet.h"
#include "instructions/Random.h"
#include "instructions/SkipIfKeyPressed.h"
#include "instructions/SkipIfKeyNotPressed.h"
#include "instructions/SetSoundTimer.h"
#include "instructions/SetXToDelayTimer.h"
#include "instructions/SetDelayTimerToX.h"
#include "instructions/AddToIndex.h"
#include "instructions/GetKey.h"
#include "instructions/SetIndexToFont.h"
#include "instructions/StoreBinaryCodedDecimal.h"
#include "instructions/StoreRegsInMemory.h"
#include "instructions/LoadRegsFromMemory.h"
#include "InstructionFactory.h"

std::map<uint16_t, InstructionFactory::InstructionCreateFunc> InstructionFactory::theFirstNibbleMap;
std::map<uint16_t, InstructionFactory::InstructionCreateFunc> InstructionFactory::theLogicalOperationsMap;
std::map<uint16_t, InstructionFactory::InstructionCreateFunc> InstructionFactory::theFxMap;

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
InstructionFactory::InstructionFactory()
{    
    // populate the map with first nibble of the opcodes to the function pointers 
    if (theFirstNibbleMap.empty())   
    {
        theFirstNibbleMap.emplace(0x0, InstructionFactory::Process0);
        theFirstNibbleMap.emplace(0x1, InstructionFactory::Process1);
        theFirstNibbleMap.emplace(0x2, InstructionFactory::Process2);
        theFirstNibbleMap.emplace(0x3, InstructionFactory::Process3);
        theFirstNibbleMap.emplace(0x4, InstructionFactory::Process4);
        theFirstNibbleMap.emplace(0x5, InstructionFactory::Process5);
        theFirstNibbleMap.emplace(0x6, InstructionFactory::Process6);
        theFirstNibbleMap.emplace(0x7, InstructionFactory::Process7);
        theFirstNibbleMap.emplace(0x8, InstructionFactory::Process8);
        theFirstNibbleMap.emplace(0x9, InstructionFactory::Process9);
        theFirstNibbleMap.emplace(0xA, InstructionFactory::ProcessA);
        theFirstNibbleMap.emplace(0xB, InstructionFactory::ProcessB);
        theFirstNibbleMap.emplace(0xC, InstructionFactory::ProcessC);
        theFirstNibbleMap.emplace(0xD, InstructionFactory::ProcessD);
        theFirstNibbleMap.emplace(0xE, InstructionFactory::ProcessE);
        theFirstNibbleMap.emplace(0xF, InstructionFactory::ProcessF);        
    }

    // populate the map with the fourth nibble of the logical operations opcodes to the function pointers
    if (theLogicalOperationsMap.empty())
    {
        theLogicalOperationsMap.emplace(0x0, InstructionFactory::Process8XY0);
        theLogicalOperationsMap.emplace(0x1, InstructionFactory::Process8XY1);
        theLogicalOperationsMap.emplace(0x2, InstructionFactory::Process8XY2);
        theLogicalOperationsMap.emplace(0x3, InstructionFactory::Process8XY3);
        theLogicalOperationsMap.emplace(0x4, InstructionFactory::Process8XY4);
        theLogicalOperationsMap.emplace(0x5, InstructionFactory::Process8XY5);    
        theLogicalOperationsMap.emplace(0x6, InstructionFactory::Process8XY6);    
        theLogicalOperationsMap.emplace(0x7, InstructionFactory::Process8XY7);    
        theLogicalOperationsMap.emplace(0xE, InstructionFactory::Process8XYE);    
    }


    // populate the map with the LS byte of the logical operations opcodes to the function pointers
    if (theFxMap.empty())
    {
        theFxMap.emplace(0x07, InstructionFactory::ProcessFX07);
        theFxMap.emplace(0x15, InstructionFactory::ProcessFX15);
        theFxMap.emplace(0x18, InstructionFactory::ProcessFX18);
        theFxMap.emplace(0x1E, InstructionFactory::ProcessFX1E);
        theFxMap.emplace(0x0A, InstructionFactory::ProcessFX0A);
        theFxMap.emplace(0x29, InstructionFactory::ProcessFX29);    
        theFxMap.emplace(0x33, InstructionFactory::ProcessFX33);    
        theFxMap.emplace(0x55, InstructionFactory::ProcessFX55);    
        theFxMap.emplace(0x65, InstructionFactory::ProcessFX65);    
    }    
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
    else if (0x00ee == opcode)
    {        
        return (std::shared_ptr<InstructionBase>(new SubroutineReturn()));
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
std::shared_ptr<InstructionBase> InstructionFactory::Process2(const uint16_t opcode)
{        
    return std::shared_ptr<InstructionBase>(new Subroutine(opcode));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process3(const uint16_t opcode)
{    
    return std::shared_ptr<InstructionBase>(new SkipIfXEqual(opcode));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process4(const uint16_t opcode)
{    
    return std::shared_ptr<InstructionBase>(new SkipIfXNotEqual(opcode));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process5(const uint16_t opcode)
{    
    return std::shared_ptr<InstructionBase>(new SkipIfXYEqual(opcode));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process6(const uint16_t opcode)
{        
    return std::shared_ptr<InstructionBase>(new SetReg(opcode));
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
    std::map<uint16_t, InstructionCreateFunc>::iterator it = theLogicalOperationsMap.find(FOURTH_NIBBLE(opcode));
    if (it != theLogicalOperationsMap.end())
    {        
        return ((*it->second)(opcode));
    }

    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process9(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new SkipIfXYNotEqual(opcode));
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
    return std::shared_ptr<InstructionBase>(new JumpWithOffSet(opcode));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessC(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new Random(opcode));
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
    if (0x9e == LS_BYTE(opcode))
    {        
        return (std::shared_ptr<InstructionBase>(new SkipIfKeyPressed(opcode)));
    }
    else if (0xa1 == LS_BYTE(opcode))
    {        
        return (std::shared_ptr<InstructionBase>(new SkipIfKeyNotPressed(opcode)));
    }
    
    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessF(const uint16_t opcode)
{
    std::map<uint16_t, InstructionCreateFunc>::iterator it = theFxMap.find(LS_BYTE(opcode));
    if (it != theFxMap.end())
    {        
        return ((*it->second)(opcode));
    }

    return 0;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process8XY0(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new Set(opcode));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process8XY1(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new BinaryOr(opcode));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process8XY2(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new BinaryAnd(opcode));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process8XY3(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new LogicalXor(opcode));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process8XY4(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new AddWithCarry(opcode));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process8XY5(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new SubtractYfromX(opcode));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process8XY7(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new SubtractXfromY(opcode));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process8XY6(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new ShiftRight(opcode));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::Process8XYE(const uint16_t opcode)
{
    return std::shared_ptr<InstructionBase>(new ShiftLeft(opcode));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessFX07(const uint16_t opcode)
{
    return (std::shared_ptr<InstructionBase>(new SetXToDelayTimer(opcode)));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessFX15(const uint16_t opcode)
{
    return (std::shared_ptr<InstructionBase>(new SetDelayTimerToX(opcode)));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessFX18(const uint16_t opcode)
{
    return (std::shared_ptr<InstructionBase>(new SetSoundTimer(opcode)));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessFX1E(const uint16_t opcode)
{
    return (std::shared_ptr<InstructionBase>(new AddToIndex(opcode)));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessFX0A(const uint16_t opcode)
{
    return (std::shared_ptr<InstructionBase>(new GetKey(opcode)));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessFX29(const uint16_t opcode)
{
    return (std::shared_ptr<InstructionBase>(new SetIndexToFont(opcode)));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessFX33(const uint16_t opcode)
{
    return (std::shared_ptr<InstructionBase>(new StoreBinaryCodedDecimal(opcode)));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessFX55(const uint16_t opcode)
{    
    return (std::shared_ptr<InstructionBase>(new StoreRegsInMemory(opcode)));    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::shared_ptr<InstructionBase> InstructionFactory::ProcessFX65(const uint16_t opcode)
{
    return (std::shared_ptr<InstructionBase>(new LoadRegsFromMemory(opcode)));       
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%