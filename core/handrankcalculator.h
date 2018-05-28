#ifndef HANDRANKCALCULATOR_H
#define HANDRANKCALCULATOR_H
#include <memory>
#include "hand.h"

class HandRankCalculator
{
public:
    HandRankCalculator(Hand_ptr hand);

    HandRank calculateHandRank();

private:
    bool checkStraight();
    bool checkFlush();



    Hand_ptr m_hand;
};

typedef std::shared_ptr<HandRankCalculator> HandRankCalculator_ptr;
#endif // HANDRANKCALCULATOR_H
