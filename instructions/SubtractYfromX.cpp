#include "../Chip8.h"
#include "SubtractYfromX.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SubtractYfromX::SubtractYfromX(uint16_t opcode)
    :Subtract(SECOND_NIBBLE(opcode), THIRD_NIBBLE(opcode), SECOND_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%