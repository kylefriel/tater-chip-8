#include <algorithm>
#include "Chip8SdlWrapper.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Chip8SdlWrapper::Chip8SdlWrapper()
    :theEscKeyPressed(false),
     theWindow(0),
     theRenderer(0)
{   
    //theDisplayGrid = {false}; 
    memset(theDisplayGrid, 0, sizeof(theDisplayGrid));

    theKeyMap.emplace(SDLK_1, 0x1);
    theKeyMap.emplace(SDLK_2, 0x2);
    theKeyMap.emplace(SDLK_3, 0x3);
    theKeyMap.emplace(SDLK_4, 0xC);
    theKeyMap.emplace(SDLK_q, 0x4);
    theKeyMap.emplace(SDLK_w, 0x5);
    theKeyMap.emplace(SDLK_e, 0x6);
    theKeyMap.emplace(SDLK_r, 0xD);
    theKeyMap.emplace(SDLK_a, 0x7);
    theKeyMap.emplace(SDLK_s, 0x8);
    theKeyMap.emplace(SDLK_d, 0x9);
    theKeyMap.emplace(SDLK_f, 0xE);
    theKeyMap.emplace(SDLK_z, 0xA);
    theKeyMap.emplace(SDLK_x, 0x0);
    theKeyMap.emplace(SDLK_c, 0xB);
    theKeyMap.emplace(SDLK_v, 0xF);
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
    //thePressedKeys.clear();

    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (SDL_KEYDOWN == event.type)
        {
            theEscKeyPressed = (SDLK_ESCAPE == event.key.keysym.sym) ? true : false;

            std::map<SDL_Keycode, uint8_t>::iterator it = theKeyMap.find(event.key.keysym.sym);
            if (it != theKeyMap.end())
            {        
                thePressedKeys.push_back(theKeyMap[event.key.keysym.sym]);                
            }                        
        }
        else if (SDL_KEYUP)
        {
            std::map<SDL_Keycode, uint8_t>::iterator it = theKeyMap.find(event.key.keysym.sym);
            if (it != theKeyMap.end())
            {        
                std::vector<uint8_t>::iterator pos = std::find(thePressedKeys.begin(), thePressedKeys.end(), theKeyMap[event.key.keysym.sym]);
                if (pos != thePressedKeys.end())
                {
                    thePressedKeys.erase(pos);
                }                            
            }        
        }
    }
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Chip8SdlWrapper::KeyPressed(uint8_t key)
{
    bool ret = false;
    if (std::find(thePressedKeys.begin(), thePressedKeys.end(), key) != thePressedKeys.end())
    {
        ret = true;
    }    

    return ret;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Chip8SdlWrapper::AnyKeyPressed(uint8_t &key)
{
    if (!thePressedKeys.empty())    
    {
        key = thePressedKeys.at(0);
        return true;
    }
    
    return false;
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%