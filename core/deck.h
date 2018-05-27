#ifndef DECK_H
#define DECK_H
#include "card.h"
class Deck
{
public:
    virtual Card& deal() const = 0;
    virtual void shuffle() = 0;
};

#endif // DECK_H
