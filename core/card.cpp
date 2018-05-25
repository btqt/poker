#include "card.h"

Card::Card() : m_rank(Card::Ace), m_suit(Card::Heart)
{}

void Card::setRank(const Rank &rank) {
    m_rank= rank;
}

void Card::setSuit(const Suit &suit) {
    m_suit = suit;
}

Card::Rank Card::getRank() const {return m_rank;}

Card::Suit Card::getSuit() const {return m_suit;}

QDebug operator<<(QDebug dbg, const Card &c)
{
    dbg.nospace() << QString("%1%2").arg(c.getRank()).arg(c.getSuit());
    return dbg.maybeSpace();
}

std::ostream &operator<<(std::ostream &out, const Card &c)
{
    out << c.getRank() << c.getSuit();
    return out;
}
