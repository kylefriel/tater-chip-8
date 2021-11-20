#include <algorithm>
#include "Chip8Display.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Chip8Display::Chip8Display()
{   
    //theDisplayGrid = {false}; 
    memset(theDisplayGrid, 0, sizeof(theDisplayGrid));
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Chip8Display::~Chip8Display()
{    
    SDL_DestroyWindow(theWindow);
    SDL_Quit();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Chip8Display::Initialize()
{    
    if (0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {        
        return false;
    }

    theWindow = SDL_CreateWindow("tater-chip-8", 
                                 SDL_WINDOWPOS_CENTERED, 
                                 SDL_WINDOWPOS_CENTERED, 
                                 DISPLAY_WIDTH * PIXEL_SCALE_FACTOR, 
                                 DISPLAY_HEIGHT * PIXEL_SCALE_FACTOR, 
                                 0);
    theRenderer = SDL_CreateRenderer(theWindow, -1, SDL_RENDERER_SOFTWARE);
    SDL_RenderSetScale(theRenderer, PIXEL_SCALE_FACTOR, PIXEL_SCALE_FACTOR);
   
    return true;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8Display::UpdateDisplay(bool clear)
{

    // clear the window
    SDL_SetRenderDrawColor(theRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(theRenderer);    
    
    if (!clear)
    {
        std::vector<SDL_Point> points;
        ConvertGridToPoints(points);        
        if (0 != SDL_SetRenderDrawColor(theRenderer, 0, 255, 0, SDL_ALPHA_OPAQUE))
        {
            printf ("SDL_SetRenderDrawColor failed!\n");
        }  
                
        if (0 != SDL_RenderDrawPoints(theRenderer, points.data(), points.size()))
        {
            printf ("SDL_RenderDrawPoints failed!\n");
        }        
    }    

    SDL_RenderPresent(theRenderer);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8Display::ClearScreen()
{
    // clear all of the display points   
    memset(theDisplayGrid, 0, sizeof(theDisplayGrid));    
   
    // clear and rerender the window
    UpdateDisplay(true);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8Display::ConvertGridToPoints(std::vector<SDL_Point>& points)
{        
    for (int x = 0 ; x < DISPLAY_WIDTH ; x++)
    {
        for (int y = 0 ; y < DISPLAY_HEIGHT ; y++)
        {
            if (theDisplayGrid[x][y])
            {                
                points.push_back({x, y});
            }
        }
    }
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%