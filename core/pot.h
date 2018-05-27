#ifndef POT_H
#define POT_H
#include "chip.h"

class Pot
{
public:
    Pot() : m_chip() {}

private:
    Chip m_chip;
};

#endif // POT_H
