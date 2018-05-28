#ifndef CARDLIST_H
#define CARDLIST_H
#include <vector>
#include <memory>
#include "card.h"
using namespace std;

/**
 * @brief The CardList class represent as list of Card objects
 */
class CardList {
public:
    CardList() {}
    virtual ~CardList() {}

    size_t size() { return  m_cards.size(); }

    Card_ptr operator[](unsigned int idx) {
        if(size() == 0 || idx >= size())
            return nullptr;
        return m_cards[idx];
    }

    Card_ptr at(unsigned int idx) {
        return (*this)[idx];
    }

    Card_ptr last() { return m_cards.back(); }

    Card_ptr front() { return m_cards.front(); }

    void removeLast() { m_cards.pop_back(); }

    virtual void add(Card_ptr c) = 0;

protected:
    std::vector<shared_ptr<Card> > m_cards;
};

typedef std::shared_ptr<CardList> CardList_ptr;
#endif // CARDLIST_H
