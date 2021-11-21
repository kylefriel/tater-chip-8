#include <cstdint>
#include <stack>
#include <string>
#include <array>
#include <vector>
#include "Timer.h"
#include "SoundTimer.h"
#include "Chip8Display.h"
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
        Chip8Display& GetDisplay() {return theDisplay;}

        // get and set variable registers
        uint8_t GetVReg(uint16_t r);
        void SetVReg(uint16_t r, uint8_t v);

        // get and set index register
        uint16_t GetIReg() {return theIndexRegister;}
        void SetIReg(uint16_t v) {theIndexRegister = v;}

        // get and set the flag register
        uint16_t GetFlagReg() {return theFlagRegister;}
        void SetFlagReg(uint16_t v) {theFlagRegister = v;}

        // program counter accessors
        void SetPc(uint16_t pc) {theProgramCounter = pc;}
        uint16_t GetPc() {return theProgramCounter;}
        void MovePcToNextInstruction() {theProgramCounter += 2;}

        // get memory at an address
        uint8_t GetMemory(uint16_t address);                

        // stack accessors
        void PushStack(uint16_t d) {theStack.push(d);}
        uint16_t PopStack();

    // protected methods here
    protected:

        void InitializeMemory();

    // protected members here
    protected:        
        
        Timer theDelayTimer;
        SoundTimer theSoundTimer;        
        Chip8Display theDisplay;            
        
        std::stack<uint16_t> theStack;
        uint16_t theProgramCounter;
        uint16_t theIndexRegister;        
        std::array <uint8_t, NUM_VARIABLE_REGISTERS> theVariableRegisters;
        uint16_t theFlagRegister;
        std::array <uint8_t, MEM_SIZE> theMemory;        

        // amount of time to sleep (in milliseconds) before executing the next instruction
        //const uint16_t theBetweenInstructionWaitTimeMs;   
        std::chrono::milliseconds theBetweenInstructionWaitTimeMs;

        InstructionFactory theInstructionFactory;
};
#endif