#include <cstdint>
#include <stack>
#include "Timer.h"

class Chip8
{
    public:
        // contructors
        Chip8();
        Chip8(uint16_t sleepTimeMs);        

        // load the ROM
        bool Load();

        // execute the ROM
        void Execute();

    // protected methods here
    protected:

        uint16_t FetchNextInstruction();

        void DecodeInstruction();

        void ExecuteInstruction();

    // protected members here
    protected:        

        std::stack<uint16_t> theStack;

        Timer theDelayTimer;

        Timer theSoundTimer;

        // amount of time to sleep (in milliseconds) before executing the next instruction
        //const uint16_t theBetweenInstructionWaitTimeMs;   
        std::chrono::milliseconds theBetweenInstructionWaitTimeMs;
};