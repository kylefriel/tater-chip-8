#include <array>

#ifndef _DISPLAY_
#define _DISPLAY_

#define DISPLAY_WIDTH   64
#define DISPLAY_HEIGHT  32

class Display
{    
    public:

        Display();        
        void Draw();

    // protected methods here
    protected:        
        
    // protected members here
    protected:          

        std::array< std::array<bool, DISPLAY_WIDTH>, DISPLAY_HEIGHT> theDisplayGrid;
};
#endif