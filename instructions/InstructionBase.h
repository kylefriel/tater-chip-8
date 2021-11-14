#include <string>

#ifndef _INSTRUCTIONBASE_
#define _INSTRUCTIONBASE_

#define FIRST_NIBBLE(X)     ((X & 0xf000) >> 12)
#define SECOND_NIBBLE(X)    ((X & 0xf00) >> 8)
#define THIRD_NIBBLE(X)     ((X & 0xf0) >> 4)
#define FOURTH_NIBBLE(X)    ((X & 0xf))
#define LS_THREE_NIBBLES(X) ((X & 0x0fff))
#define LS_BYTE(X)          ((X & 0x00ff))

class Chip8;

class InstructionBase
{
    public:
        InstructionBase();
        virtual void Execute(Chip8* chip8) = 0;        
        virtual std::string GetClassName() = 0;

    protected:
};

#endif