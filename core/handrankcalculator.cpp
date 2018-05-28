#include "handrankcalculator.h"

HandRankCalculator::HandRankCalculator(Hand_ptr hand) : m_hand(hand)
{
}

HandRank HandRankCalculator::calculateHandRank()
{
    if(m_hand == nullptr || m_hand->size() != 5) {
        _LOG_SCREEN_("Invalid hand");
        return HandRank::Undefined;
    }

    m_hand->sort();

    bool isStraight = checkStraight();
    bool isFlush = checkFlush();

    if(isStraight && isFlush)
        return HandRank::StraightFlush;
    else return isStraight ? HandRank::Straight : isFlush ? HandRank::Flush : HandRank::HighCard;

    //    return HandRank::Flush;
}

bool HandRankCalculator::checkStraight()
{
    int count = 0;
    for(unsigned int i = 0; i < m_hand->size() - 1; ++i) {
        if( m_hand->at(i)->rank() == (m_hand->at(i+1)->rank() - 1) ) {
            count ++;
        }
    }

    if(count == 4)
        return true;

    return false;
}

bool HandRankCalculator::checkFlush()
{
    int count = 0;
    for(unsigned int i = 0; i < m_hand->size() - 1; ++i) {
        if( m_hand->at(i)->suit() == (m_hand->at(i+1)->suit()) ) {
            count ++;
        }
    }

    if(count == 4)
        return true;

    return false;
}
