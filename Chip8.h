#include <cstdint>
#include <stack>
#include <string>
#include "Timer.h"
#include "SoundTimer.h"
#include "Display.h"
#include "InstructionFactory.h"

#ifndef _CHIP8_
#define _CHIP8_

#define MEM_SIZE     0x1000
#define PROGAM_START 0x0200
#define FONTS_SIZE   0x0050
#define FONTS_START  0x0050

#define NUM_VARIABLE_REGISTERS 0x10

class Chip8
{    
    public:
        // contructors
        Chip8();
        Chip8(uint16_t sleepTimeMs);        

        // load the ROM
        bool LoadFromFile(std::string file);

        // execute the ROM
        void Execute();

    public:

        // accessor methods
        Display& GetDisplay() {return theDisplay;}

    // protected methods here
    protected:

        void InitializeMemory();

    // protected members here
    protected:        
        
        Timer theDelayTimer;
        SoundTimer theSoundTimer;        
        Display theDisplay;            
        
        std::stack<uint16_t> theStack;
        uint16_t theProgramCounter;
        uint16_t theIndexRegister;        
        std::array <uint16_t, NUM_VARIABLE_REGISTERS> theVariableRegisters;
        std::array <uint16_t, MEM_SIZE> theMemory;

        // amount of time to sleep (in milliseconds) before executing the next instruction
        //const uint16_t theBetweenInstructionWaitTimeMs;   
        std::chrono::milliseconds theBetweenInstructionWaitTimeMs;

        InstructionFactory theInstructionFactory;
};
#endif