#ifndef HAND_H
#define HAND_H
#include <algorithm>
#include "common.h"
#include "cardlist.h"

class Hand : public CardList
{
public:
    Hand();

    virtual void add(Card_ptr c) override;

    void sort() { std::sort( m_cards.begin(), m_cards.end(), less_than_comparator<Card> ); }
private:

};
typedef std::shared_ptr<Hand> Hand_ptr;
#endif // HAND_H
