#include "pokerdeck.h"

PokerDeck::PokerDeck() : Deck(), CardList()
{
    initialize();
}

Card& PokerDeck::deal() const
{
}

void PokerDeck::shuffle()
{
    this->shuffle();
}

void PokerDeck::burn()
{

}

QDebug operator<<(QDebug dbg, const PokerDeck &c)
{
    return dbg.maybeSpace();
}

ostream &operator<<(ostream &out, const PokerDeck &c)
{

    return out;
}

void PokerDeck::initialize()
{
    try {
        for(int i = (int)Card::Ace; i <= (int)Card::King; ++i) {
            for(int j = (int)Card::Heart; j <= (int)Card::Spade; ++j) {
                std::shared_ptr<Card> c = std::make_shared<Card>( Card( (Card::Rank)i, (Card::Suit)j) );
                this->push_back(c);
            }
        }

        _LOG_SCREEN_("Initializing deck completed");
    } catch (std::exception &ex) {
        _LOG_SCREEN_(ex.what());
    }
}
