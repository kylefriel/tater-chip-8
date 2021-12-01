#include "../Chip8.h"
#include "GetKey.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
GetKey::GetKey(uint16_t opcode)
    :theReg(SECOND_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void GetKey::Execute(Chip8* chip8)
{
    uint8_t key;

    if (chip8->GetSdl().AnyKeyPressed(key))
    {
        chip8->SetVReg(theReg, key);
    }
    else
    {
        // decrement the program counter so that command will be
        // reexecuted until a key is pressed
        chip8->MovePcToLastInstruction();
    }
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%