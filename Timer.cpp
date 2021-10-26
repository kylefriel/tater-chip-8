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
void Timer::Run()
{
    ChildRun();    
    Decrement();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    
void Timer::Decrement()
{
    if (theCounter > 0)
    {
        const int64_t SIXTY_HERTZ_IN_NS = 16666667;
        using namespace std::chrono;
        timepoint now = steady_clock::now();    
        nanoseconds elaspedTimeNs = duration_cast<nanoseconds>(now - theLastTimePoint);

        if (nanoseconds(SIXTY_HERTZ_IN_NS) <= elaspedTimeNs)    
        {
            theCounter--;
        }

        theLastTimePoint = now;
    }    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
