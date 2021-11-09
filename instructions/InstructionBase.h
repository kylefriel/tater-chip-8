#ifndef _INSTRUCTIONBASE_
#define _INSTRUCTIONBASE_

class Chip8;

class InstructionBase
{
    public:
        InstructionBase();

        virtual void Execute(Chip8* chip8) = 0;

    protected:
};

#endif