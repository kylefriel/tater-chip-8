#include "../Chip8.h"
#include "SubtractXfromY.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
SubtractXfromY::SubtractXfromY(uint16_t opcode)
    :Subtract(THIRD_NIBBLE(opcode), SECOND_NIBBLE(opcode), SECOND_NIBBLE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%