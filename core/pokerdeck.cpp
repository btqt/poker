#include "pokerdeck.h"

PokerDeck::PokerDeck() : Deck(), CardList()
{
    initialize();
}

PokerDeck::~PokerDeck()
{

}

Card_ptr PokerDeck::deal()
{
    if(this->size() <= 0)
        return nullptr;
    Card_ptr c = this->last();
    this->removeLast();
    return c;
}

void PokerDeck::shuffle()
{
    std::srand(std::time(0));
    std::random_shuffle(m_cards.begin(), m_cards.end());
}

void PokerDeck::add(Card_ptr c)
{
    m_cards.push_back(c);
}

void PokerDeck::burn()
{

}

void PokerDeck::sort()
{
    std::sort(m_cards.begin(), m_cards.end(), less_than_comparator<Card>);
}

QDebug operator<<(QDebug dbg, const PokerDeck &c)
{
    for(std::vector<Card_ptr>::const_iterator it = c.m_cards.begin(); it != c.m_cards.end(); ++it) {
        Card_ptr card = *it;
        dbg << *card;
    }
    return dbg.space();
}

ostream &operator<<(ostream &out, const PokerDeck &c)
{
    for(std::vector<Card_ptr>::const_iterator it = c.m_cards.begin(); it != c.m_cards.end(); ++it) {
        Card_ptr card = *it;
        out << *card << " ";
    }
    return out;
}

void PokerDeck::initialize()
{
    try {
        for(int i = (int)Card::Ace; i <= (int)Card::King; ++i) {
            for(int j = (int)Card::Heart; j <= (int)Card::Spade; ++j) {
                std::shared_ptr<Card> c = std::make_shared<Card>( Card( (Card::Rank)i, (Card::Suit)j) );
                this->add(c);
            }
        }

        _LOG_SCREEN_("Initializing deck completed");
    } catch (std::exception &ex) {
        _LOG_SCREEN_(ex.what());
    }
}
