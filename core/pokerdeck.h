#ifndef POKERDECK_H
#define POKERDECK_H
#include <QDebug>
#include <ostream>
#include "common.h"
#include "deck.h"
#include "cardlist.h"

using namespace std;

class PokerDeck : public Deck, public CardList
{
public:
    explicit PokerDeck();
    virtual Card& deal() const;
    virtual void shuffle();
    void burn();

    friend QDebug operator<<(QDebug dbg, const PokerDeck &c);
    friend std::ostream &operator<<(std::ostream &out, const PokerDeck &c);
private:
    void initialize();

};

#endif // POKERDECK_H
