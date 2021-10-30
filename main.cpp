#include <stdio.h>
#include <string>
#include "Chip8.h"

int main(int argc, char* argv[])
{
    if (2 != argc)
    {
        printf ("usage: %s <path-to-chip-8-rom>\n", argv[0]);
        return 0;
    }

    std::string filename = argv[1];

    Chip8 emulator;
    if (!emulator.LoadFromFile(filename))
    {
        printf ("failed to load rom file %s\n", filename.c_str());
        return 0;
    }

    //emulator.Execute();
    return 0;
}