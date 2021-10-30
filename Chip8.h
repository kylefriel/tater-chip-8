#include <cstdint>
#include <stack>
#include <string>
#include "Timer.h"
#include "SoundTimer.h"
#include "Display.h"

#ifndef _CHIP8_
#define _CHIP8_

#define MEM_SIZE     0x1000
#define PROGAM_START 0x0200
#define FONTS_SIZE   0x0050
#define FONTS_START  0x0050

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

    // protected methods here
    protected:

        void InitializeMemory();

        uint16_t FetchNextInstruction();

        void DecodeInstruction();

        void ExecuteInstruction();

    // protected members here
    protected:        

        std::stack<uint16_t> theStack;

        Timer theDelayTimer;
        SoundTimer theSoundTimer;        
        std::array <uint16_t, MEM_SIZE> theMemory;
        Display theDisplay;

        // amount of time to sleep (in milliseconds) before executing the next instruction
        //const uint16_t theBetweenInstructionWaitTimeMs;   
        std::chrono::milliseconds theBetweenInstructionWaitTimeMs;
};
#endif