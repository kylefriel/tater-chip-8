#include <array>
#include <vector>
#include <SDL.h>

#ifndef _DISPLAY_
#define _DISPLAY_

#define DISPLAY_WIDTH       64
#define DISPLAY_HEIGHT      32
#define PIXEL_SCALE_FACTOR  10

class Display
{    
    public:

        Display();
        ~Display();
        bool Initialize();
        void Draw(uint16_t x, uint16_t y, uint16_t n);        
        void ClearScreen();

    // protected methods here
    protected:        

        void UpdateDisplay(bool clear = false);
        std::vector<SDL_Point> ConvertGridToPoints();
        
    // protected members here
    protected:          

        std::array< std::array<bool, DISPLAY_WIDTH>, DISPLAY_HEIGHT> theDisplayGrid;

        SDL_Window* theWindow;
        SDL_Renderer* theRenderer;
        //std::vector<SDL_Point> theDisplayPoints;
};
#endif