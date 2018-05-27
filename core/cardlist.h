#ifndef CARDLIST_H
#define CARDLIST_H
#include <vector>
#include <memory>
#include "card.h"
using namespace std;

/**
 * @brief CardList represent as list of Card objects
 */
typedef vector<shared_ptr<Card> > CardList;

#endif // CARDLIST_H
