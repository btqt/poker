#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QMetaType>
#include <QDebug>
#include <memory>
#include <ostream>

using namespace std;
class Card
{
public:
    enum Rank {Ace = 1, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
    enum Suit {Heart = 0, Diamond, Club, Spade};

    explicit Card();

    Card(Rank rank, Suit suit);

    ~Card() = default;

    // cctor, mctor, copy assignment, move assignmen
    Card(const Card& c) = default;
    Card(Card&& c) = default;
    Card& operator=(const Card &c) = default;
    Card& operator=(Card &&c) = default;

    bool operator<(const Card &c);
    bool operator>(const Card &c);

    void setRank(const Rank &rank);
    void setSuit(const Suit &suit);

    Rank rank() const;
    Suit suit() const;

    friend QDebug operator<<(QDebug dbg, const Card &c);
    friend std::ostream &operator<<(std::ostream &out, const Card &c);
signals:

public slots:

private:
    Rank m_rank;
    Suit m_suit;
};

typedef std::shared_ptr<Card> Card_ptr;
#endif // CARD_H
