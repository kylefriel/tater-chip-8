#include "Timer.h"
        
Timer::Timer()
    :theCounter(0)
{
    
}

void Timer::Run()
{
    Decrement();
}
    
void Timer::Decrement()
{
    if (theCounter > 0)
    {
        theCounter--;
    }
}