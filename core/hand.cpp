#include "hand.h"

Hand::Hand() : CardList ()
{

}

void Hand::add(Card_ptr c)
{
    m_cards.push_back(c);
}
