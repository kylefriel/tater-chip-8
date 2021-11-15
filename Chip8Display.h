#include <array>
#include <vector>
#include <SDL.h>

#ifndef _CHIP8DISPLAY_
#define _CHIP8DISPLAY_

#define DISPLAY_WIDTH       64
#define DISPLAY_HEIGHT      32
#define PIXEL_SCALE_FACTOR  10

class Chip8Display
{    
    public:

        typedef std::array< std::array<bool, DISPLAY_WIDTH>, DISPLAY_HEIGHT> Chip8DisplayGrid;

        Chip8Display();
        ~Chip8Display();
        bool Initialize();
        void Draw() {UpdateDisplay();}
        void ClearScreen();

        Chip8DisplayGrid& GetDisplayGrid() {return theDisplayGrid;}                    

    // protected methods here
    protected:        

        void UpdateDisplay(bool clear = false);
        void ConvertGridToPoints(std::vector<SDL_Point>& points);
        
    // protected members here
    protected:          

        SDL_Window* theWindow;
        SDL_Renderer* theRenderer;        

        Chip8DisplayGrid theDisplayGrid;        
};
#endif