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
     theProgramCounter(PROGAM_START)
{
    InitializeMemory();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Chip8::Chip8(uint16_t sleepTimeMs)
    :theBetweenInstructionWaitTimeMs(sleepTimeMs),
     theProgramCounter(PROGAM_START)
{
    InitializeMemory();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Chip8::LoadFromFile(std::string file)
{
    using namespace std;
    ifstream f (file, ios::binary);

    if (!f)
    {
        return false;
    }

    char c[sizeof(uint16_t)];
    int i = PROGAM_START;
    // copy the entire rom into memory (16 bits at a time) at the predefined location
    while (f.read(c, sizeof(uint16_t)) && i < MEM_SIZE)
    {        
        theMemory[i++] = (static_cast<uint16_t>(c[0] << 8) | static_cast<uint8_t>(c[1]));        
    }    
    
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

    while (true)
    {            
        // get the next instruction and increment the program counter
        uint16_t opcode = theMemory[theProgramCounter++];

        // get the correct instruction object to perform the execution
        InstructionBase* instruction = theInstructionFactory.GetInstruction(opcode);

        if (0 != instruction)
        {
            instruction->Execute(this);
            delete instruction;
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
    theMemory.fill(0x0000);

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