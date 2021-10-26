#include "Timer.h"

#ifndef _SOUNDTIMER_
#define _SOUNDTIMER_

class SoundTimer : public Timer
{
    public:

        SoundTimer();        

    // protected methods here
    protected:        

        virtual void ChildRun();
};
#endif