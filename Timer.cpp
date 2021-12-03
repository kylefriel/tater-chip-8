#include <stdio.h>
#include "Chip8.h"
#include "Timer.h"

const int64_t SIXTY_HERTZ_IN_NS = 16666667;

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Timer::Timer()
    :theCounter(0),
    theElaspedTimeSinceLastDecrement(16666667)
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Timer::Run(Chip8* chip8)
{    
    Decrement();
    ChildRun(chip8);    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
void Timer::Decrement()
{
    if (theCounter > 0)
    {
        const int64_t SIXTY_HERTZ_IN_MS = 17;
        using namespace std::chrono;
        timepoint now = steady_clock::now();    
        milliseconds elaspedTimeMs = duration_cast<milliseconds>(now - theLastTimePoint);

        if (nanoseconds(SIXTY_HERTZ_IN_MS) <= elaspedTimeMs)    
        {
            theCounter--;            
        }

        theLastTimePoint = steady_clock::now();
    }    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
