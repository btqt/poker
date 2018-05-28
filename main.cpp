#include <QApplication>

#include <QDebug>
#include <iostream>
#include <algorithm>
#include "core/pokerdeck.h"
#include "core/common.h"
#include "core/card.h"
#include "core/hand.h"
#include "core/handrankcalculator.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
//    if (engine.rootObjects().isEmpty())
//        return -1;

    std::shared_ptr<Deck> deck = std::make_shared<PokerDeck>();
    std::cout << *dynamic_pointer_cast<PokerDeck>(deck) << std::endl;

    deck->shuffle();
    std::cout << *dynamic_pointer_cast<PokerDeck>(deck) << std::endl;

    Card_ptr c = deck->deal();
    std::cout << *dynamic_pointer_cast<PokerDeck>(deck) << std::endl;
    std::cout << *c << std::endl;

    c = deck->deal();
    std::cout << *dynamic_pointer_cast<PokerDeck>(deck) << std::endl;
    std::cout << *c << std::endl;

    PokerDeck_ptr p = dynamic_pointer_cast<PokerDeck>(deck);
    p->sort();
    std::cout << *p << std::endl;

    Hand_ptr hand(new Hand());
    hand->add( Card_ptr(new Card(Card::Rank::Ace, Card::Suit::Heart)) );
    hand->add( Card_ptr(new Card(Card::Rank::Deuce, Card::Suit::Heart)) );
    hand->add( Card_ptr(new Card(Card::Rank::King, Card::Suit::Spade)) );
    hand->add( Card_ptr(new Card(Card::Rank::Four, Card::Suit::Heart)) );
    hand->add( Card_ptr(new Card(Card::Rank::Five, Card::Suit::Heart)) );

    HandRankCalculator_ptr hrc( new HandRankCalculator(hand) );
    std::cout << (int)hrc->calculateHandRank() << std::endl;
    return app.exec();
}
