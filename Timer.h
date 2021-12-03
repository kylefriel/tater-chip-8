#include <cstdint>
#include <chrono>

#ifndef _TIMER_
#define _TIMER_

class Chip8;

class Timer
{        
    public:

        typedef std::chrono::steady_clock::time_point timepoint;
        typedef std::chrono::nanoseconds nanosecs;

    public:        

        Timer();

        void Run(Chip8* chip8);

        uint8_t GetCounter() const {return theCounter;}
        void SetCounter(const uint8_t c) {theCounter = c;}

    // protected methods here
    protected:        

        virtual void ChildRun(Chip8* chip8) {};

    // protected members here
    protected:        

        uint8_t theCounter;

    // private methods here
    private:

        void Decrement();        

    // private members here
    private:
        
        timepoint theLastTimePoint;
        nanosecs  theElaspedTimeSinceLastDecrement;        
};
#endif