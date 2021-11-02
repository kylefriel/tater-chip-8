#include <array>

#ifndef _DISPLAY_
#define _DISPLAY_

#define DISPLAY_WIDTH   64
#define DISPLAY_HEIGHT  32

class Display
{    
    public:

        Display();
        void Draw(uint16_t x, uint16_t y, uint16_t n);
        void ClearScreen();

    // protected methods here
    protected:        
        
    // protected members here
    protected:          

        std::array< std::array<bool, DISPLAY_WIDTH>, DISPLAY_HEIGHT> theDisplayGrid;
};
#endif