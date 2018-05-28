#ifndef COMMON_DEFINE_H
#define COMMON_DEFINE_H
#include <iostream>
#include <memory>
using namespace std;
#define _LOG_SCREEN_(MSG) std::cout<<MSG<<"  - at "<<__FILE__<<", function "<<__PRETTY_FUNCTION__<<", line "<<__LINE__<<std::endl

template <typename T>
bool less_than_comparator(shared_ptr<T> a, shared_ptr<T> b)
{
   return *a < *b;
}

template <typename T>
bool greater_than_comparator(shared_ptr<T> a, shared_ptr<T> b)
{
   return *a > *b;
}

enum class Round {
    Pre_Flop = 0,
    Flop,
    Turn,
    River,
    None,
    Undefined
};

enum class BettingTerm {
    Bet,
    Fold,
    Check,
    Raise,
    ReRaise,
    Call,
    Allin,
    Undefined
};

enum class HandRank {
    RoyalFlush,
    StraightFlush,
    FourOfAKind,
    FullHouse,
    Flush,
    Straight,
    ThreeOfAKind,
    TwoPair,
    OnePair,
    HighCard,
    Undefined
};

#endif // COMMON_DEFINE_H
