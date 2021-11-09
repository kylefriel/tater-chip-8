#include "Chip8Display.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Chip8Display::Chip8Display()
{    
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
    if (0 != SDL_Init(SDL_INIT_EVERYTHING))
    {        
        return false;
    }

    theWindow = SDL_CreateWindow("tater-chip-8", 
                                 SDL_WINDOWPOS_CENTERED, 
                                 SDL_WINDOWPOS_CENTERED, 
                                 DISPLAY_WIDTH * PIXEL_SCALE_FACTOR, 
                                 DISPLAY_HEIGHT * PIXEL_SCALE_FACTOR, 
                                 0);
    theRenderer = SDL_CreateRenderer(theWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetScale(theRenderer, PIXEL_SCALE_FACTOR, PIXEL_SCALE_FACTOR);
    
    /*
    SDL_SetRenderDrawColor(theRenderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < 32 ; i++)
    {
        SDL_RenderDrawPoint(theRenderer, i, i);
    }
    SDL_RenderPresent(theRenderer);    
    SDL_Delay(5000);            
    ClearScreen();
    SDL_Delay(5000);        
    */
   
    return true;
}

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8Display::Draw(uint16_t x, uint16_t y, uint16_t n)
{
    // @todo implement drawing algorithm

    UpdateDisplay();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8Display::UpdateDisplay(bool clear)
{
    if (clear)
    {
        // clear and rerender the window
        SDL_SetRenderDrawColor(theRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(theRenderer);
    }
    else
    {
        std::vector<SDL_Point> points = ConvertGridToPoints();
        SDL_SetRenderDrawColor(theRenderer, 0, 255, 0, SDL_ALPHA_OPAQUE);  
        SDL_RenderDrawPoints(theRenderer, points.data(), points.size());         
        SDL_RenderPresent(theRenderer); 
    }

    SDL_RenderPresent(theRenderer);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8Display::ClearScreen()
{
    // clear all of the display points   
    using namespace std;
    for (int i = 0 ; i < DISPLAY_HEIGHT ; i++)
        for (int j = 0 ; j < DISPLAY_WIDTH ; j++)
            theDisplayGrid[i][j] = false;
   
    // clear and rerender the window
    UpdateDisplay(true);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::vector<SDL_Point> Chip8Display::ConvertGridToPoints()
{
    std::vector<SDL_Point> points;

    using namespace std;
    for (int w = 0 ; w < DISPLAY_WIDTH ; w++)
    {
        for (int h = 0 ; h < DISPLAY_HEIGHT ; h++)
        {
            if (theDisplayGrid[w][h])
            {                
                points.push_back({w, h});
            }
        }
    }

    return points;    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%