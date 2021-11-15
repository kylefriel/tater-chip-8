#include "Chip8Display.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Chip8Display::Chip8Display()
{   
    theDisplayGrid = {false}; 
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
    theDisplayGrid = {false}; 

    // using namespace std;
    // for (int i = 0 ; i < DISPLAY_HEIGHT ; i++)
    //     for (int j = 0 ; j < DISPLAY_WIDTH ; j++)
    //         theDisplayGrid[i][j] = false;
   
    // clear and rerender the window
    UpdateDisplay(true);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8Display::ConvertGridToPoints(std::vector<SDL_Point>& points)
{        
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
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%