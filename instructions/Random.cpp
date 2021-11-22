#include <random>

#include "../Chip8.h"
#include "Random.h"

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Random::Random(uint16_t opcode)
    :theXReg(SECOND_NIBBLE(opcode)),
     theNnVal(LS_BYTE(opcode))
{
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Random::Execute(Chip8* chip8)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution dist(0, 0xff);
    uint8_t randomNumber = dist(mt);        
    
    chip8->SetVReg(theXReg, theNnVal & randomNumber);    
}
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%