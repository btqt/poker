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

    virtual ~PokerDeck() override;

    virtual Card_ptr deal() override;
    virtual void shuffle() override;

    virtual void add(Card_ptr c) override;

    void burn();

    void sort();

    friend QDebug operator<<(QDebug dbg, const PokerDeck &c);
    friend std::ostream &operator<<(std::ostream &out, const PokerDeck &c);
private:
    void initialize();

};
typedef std::shared_ptr<PokerDeck> PokerDeck_ptr;
#endif // POKERDECK_H
