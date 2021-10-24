#include <cstdint>

class Timer{

    public:

        Timer();

        void Run();

    // protected methods here
    protected:

        void Decrement();

    // protected members here
    protected:

        uint8_t theCounter;
};