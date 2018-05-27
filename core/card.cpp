#include "card.h"

Card::Card() : m_rank(Card::Ace), m_suit(Card::Heart) {}

Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit) {}

void Card::setRank(const Rank &rank) {
    m_rank= rank;
}

void Card::setSuit(const Suit &suit) {
    m_suit = suit;
}

Card::Rank Card::rank() const {return m_rank;}

Card::Suit Card::suit() const {return m_suit;}

QDebug operator<<(QDebug dbg, const Card &c)
{
    dbg.nospace() << QString("%1%2").arg(c.rank()).arg(c.suit());
    return dbg.maybeSpace();
}

std::ostream &operator<<(std::ostream &out, const Card &c)
{
    out << c.rank() << c.suit();
    return out;
}
