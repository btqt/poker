#ifndef COMMON_DEFINE_H
#define COMMON_DEFINE_H
#include <iostream>

using namespace std;
#define _LOG_SCREEN_(MSG) std::cout<<MSG<<"  - at "<<__FILE__<<", function "<<__PRETTY_FUNCTION__<<", line "<<__LINE__<<std::endl

enum Round {
    Pre_Flop = 0,
    Flop,
    Turn,
    River,
    None
};

enum BettingTerm {
    Bet,
    Fold,
    Check,
    Raise,
    ReRaise,
    Call,
    Allin
};

enum HandRank {
    RoyalFlush,
    StraightFlush,
    FourOfAKind,
    FullHouse,
    Flush,
    Straight,
    ThreeOfAKind,
    TwoPair,
    OnePair,
    HighCard
};

#endif // COMMON_DEFINE_H
