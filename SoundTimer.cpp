#include "Chip8.h"
#include "SoundTimer.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SoundTimer::SoundTimer()
    :Timer()
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void SoundTimer::ChildRun(Chip8* chip8)
{
    // @todo make a beep sound
    if (theCounter > 0)
    {
        chip8->GetSdl().PlaySound(false);
        printf ("playing audio\n");
    }
    else
    {
        chip8->GetSdl().PlaySound(true);
        printf ("pausing audio\n");
    }
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
