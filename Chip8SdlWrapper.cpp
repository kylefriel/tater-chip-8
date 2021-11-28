#include <algorithm>
#include "Chip8SdlWrapper.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Chip8SdlWrapper::Chip8SdlWrapper()
{   
    //theDisplayGrid = {false}; 
    memset(theDisplayGrid, 0, sizeof(theDisplayGrid));

    theKeyMap.emplace(0x1, SDLK_1);
    theKeyMap.emplace(0x2, SDLK_2);
    theKeyMap.emplace(0x3, SDLK_3);
    theKeyMap.emplace(0xC, SDLK_4);
    theKeyMap.emplace(0x4, SDLK_q);
    theKeyMap.emplace(0x5, SDLK_w);
    theKeyMap.emplace(0x6, SDLK_e);
    theKeyMap.emplace(0xD, SDLK_r);
    theKeyMap.emplace(0x7, SDLK_a);
    theKeyMap.emplace(0x8, SDLK_s);
    theKeyMap.emplace(0x9, SDLK_d);
    theKeyMap.emplace(0xE, SDLK_f);
    theKeyMap.emplace(0xA, SDLK_z);
    theKeyMap.emplace(0x0, SDLK_x);
    theKeyMap.emplace(0xB, SDLK_c);
    theKeyMap.emplace(0xF, SDLK_m);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Chip8SdlWrapper::~Chip8SdlWrapper()
{    
    SDL_DestroyWindow(theWindow);
    SDL_Quit();
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Chip8SdlWrapper::Initialize()
{    
    if (0 != SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS))
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
void Chip8SdlWrapper::UpdateDisplay(bool clear)
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
void Chip8SdlWrapper::ClearScreen()
{
    // clear all of the display points   
    memset(theDisplayGrid, 0, sizeof(theDisplayGrid));    
   
    // clear and rerender the window
    UpdateDisplay(true);
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8SdlWrapper::ConvertGridToPoints(std::vector<SDL_Point>& points)
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

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Chip8SdlWrapper::GetGridPointState(uint8_t x, uint8_t y)
{
    bool ret = false;    

    if (DISPLAY_WIDTH > x && DISPLAY_HEIGHT > y)
    {
        ret = theDisplayGrid[x][y];
    }    

    return ret;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8SdlWrapper::SetGridPointState(uint8_t x, uint8_t y, bool state)
{
    if (DISPLAY_WIDTH > x && DISPLAY_HEIGHT > y)
    {
        theDisplayGrid[x][y] = state;
    }
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Chip8SdlWrapper::CheckForKeyboardEvents()
{

    thePressedKeys.clear();

    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (SDL_KEYDOWN == event.type)
        {
            thePressedKeys.push_back(event.key.keysym.sym);
            printf ("%d was pressed!\n", event.key.keysym.sym);
        }
    }
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Chip8SdlWrapper::EscKeyPressed()
{
    if (std::find(thePressedKeys.begin(), thePressedKeys.end(), SDLK_ESCAPE) != thePressedKeys.end())
    {
        return true;
    }

    return false;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

bool Chip8SdlWrapper::KeyPressed(uint8_t key)
{
    bool ret = false;
    if (std::find(thePressedKeys.begin(), thePressedKeys.end(), theKeyMap[key]) != thePressedKeys.end())
    {
        ret = true;
    }    

    return ret;
}