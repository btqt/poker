#ifndef DECK_H
#define DECK_H
#include "card.h"
class Deck
{
public:
    virtual ~Deck() {}
    virtual Card_ptr deal() = 0;
    virtual void shuffle() = 0;
};

typedef std::shared_ptr<Deck> Deck_ptr;
#endif // DECK_H
