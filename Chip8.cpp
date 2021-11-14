#include <chrono>
#include <thread>
#include <fstream>
#include <iostream>
#include <vector>
#include "Chip8.h"
#include "instructions/InstructionBase.h"

const std::chrono::milliseconds default_sleep_time_ms(2); // default is 2ms

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Chip8::Chip8()
    :theBetweenInstructionWaitTimeMs(default_sleep_time_ms),
     theProgramCounter(PROGAM_START),
     theFlagRegister(0)
{
    std::fill(std::begin(theVariableRegisters), std::end(theVariableRegisters), 0);
    InitializeMemory();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Chip8::Chip8(uint16_t sleepTimeMs)
    :theBetweenInstructionWaitTimeMs(sleepTimeMs),
     theProgramCounter(PROGAM_START),
     theFlagRegister(0)
{
    std::fill(std::begin(theVariableRegisters), std::end(theVariableRegisters), 0);
    InitializeMemory();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Chip8::LoadFromFile(std::string file)
{
    using namespace std;
    fstream f (file, fstream::in | fstream::binary);

    if (!f)
    {
        return false;
    }

    f.read(reinterpret_cast<char*>(theMemory.data() + PROGAM_START), theMemory.size() - PROGAM_START);
    
    // for (int i = 0 ; i < theMemory.size() ; i+=2)
    // {        
    //     if (0 != theMemory[i] || 0 != theMemory[i+1])
    //         printf ("i=%x: %02x%02x\n", i, theMemory[i], theMemory[i+1]);
    // }    
    
    f.close();    

    return true;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8::Execute()
{            
    if (!theDisplay.Initialize())
    {
        printf ("failed to initialize graphics\n");
        return;
    }          

    while (true && theProgramCounter < theMemory.size())
    {            
        // get the next instruction and increment the program counter
        //uint16_t opcode = theMemory[theProgramCounter++];
        uint16_t opcode = (theMemory[theProgramCounter] << 8) | theMemory[theProgramCounter+1];
        theProgramCounter += 2;        

        // get the correct instruction object to perform the execution
        std::shared_ptr<InstructionBase> instruction = theInstructionFactory.GetInstruction(opcode);

        if (0 != instruction)
        {            
            std::cout << "opcode=" << std::hex << opcode << " Executing " + instruction->GetClassName() << std::endl;
            instruction->Execute(this);            
        }

        // sleep for some number of milliseconds before attempting to execute 
        // the next instruction
        std::this_thread::sleep_for(theBetweenInstructionWaitTimeMs);

        theDelayTimer.Run();
        theSoundTimer.Run();        
    }
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8::InitializeMemory()
{
    theMemory.fill(0);

    // define the fonts
    std::array <uint16_t, FONTS_SIZE> fonts = {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x80, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0x60, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    // copy the fonts into the memory at the predefined location
    std::copy(std::begin(fonts), std::end(fonts), std::begin(theMemory) + FONTS_START);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint8_t Chip8::GetVReg(uint16_t r)
{    
    try
    {
        return theVariableRegisters.at(r);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8::SetVReg(uint16_t r, uint8_t v)
{
    try
    {
        theVariableRegisters.at(r) = v;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';        
    }    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
uint8_t Chip8::GetMemory(uint16_t address)
{
    try
    {
        return theMemory.at(address);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n'; 
        return 0;       
    }    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%