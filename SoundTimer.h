#include "Timer.h"

#ifndef _SOUNDTIMER_
#define _SOUNDTIMER_

class Chip8;

class SoundTimer : public Timer
{
    public:

        SoundTimer();        

    // protected methods here
    protected:        

        virtual void ChildRun(Chip8* chip8);
};
#endif