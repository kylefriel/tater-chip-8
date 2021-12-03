#include <map>
#include <SDL.h>

#ifndef _CHIP8DISPLAY_
#define _CHIP8DISPLAY_

#define DISPLAY_WIDTH       64
#define DISPLAY_HEIGHT      32
#define PIXEL_SCALE_FACTOR  10

class Chip8SdlWrapper
{    
    public:
        
        typedef bool Chip8DisplayGrid[DISPLAY_WIDTH][DISPLAY_HEIGHT];

        Chip8SdlWrapper();
        ~Chip8SdlWrapper();
        bool Initialize();
        void Draw() {UpdateDisplay();}
        void ClearScreen();
        void CheckForKeyboardEvents();
        
        bool GetGridPointState(uint8_t x, uint8_t y);
        void SetGridPointState(uint8_t x, uint8_t y, bool state);

        // indicate whether or not the ESC key was pressed 
        // which is how the user exits the emulator
        bool EscKeyPressed() {return theEscKeyPressed;}

        // indicates whether one of the CHIP-8 4x4 input keys are pressed
        // using the following layout:
        //
        // -----------------
        // | 1 - 2 - 3 - 4 |
        // | Q - W - E - R |
        // | A - S - D - F |
        // | Z - X - C - V |
        // -----------------        
        bool KeyPressed(uint8_t key);
        // return true if any key is pressed and set the reference to the key that was pressed
        bool AnyKeyPressed(uint8_t &key);

        void PlaySound(bool paused);

    // protected methods here
    protected:        

        void UpdateDisplay(bool clear = false);
        void ConvertGridToPoints(std::vector<SDL_Point>& points);
        
    // protected members here
    protected:          

        SDL_Window* theWindow;
        SDL_Renderer* theRenderer;        

        // map SDL keycodes to CHIP-8 input keys
        std::map<SDL_Keycode, uint8_t> theKeyMap;

        // list of keys that were in the pressed state during the last update
        std::vector<uint8_t> thePressedKeys;

        bool theEscKeyPressed;

        // sound stuff
        SDL_AudioSpec theWavSpec;
        SDL_AudioDeviceID theAudioDevice;
        uint32_t theWavLength;
        uint8_t* theWavBuffer;         

        Chip8DisplayGrid theDisplayGrid;                        
};
#endif