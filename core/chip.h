#ifndef CHIP_H
#define CHIP_H
#include <memory>
#include <QDebug>

class Chip
{
public:
    Chip() : m_value(0.0) {}
    ~Chip() = default;
    Chip(const Chip &c) {m_value = c.m_value;}

    Chip& operator=(const Chip &c) {this->m_value = c.value(); return *this;}
    Chip& operator=(const double &c) {this->m_value = c; return *this;}

    Chip operator+(const Chip &c) {this->m_value += c.value(); return *this;}
    Chip operator+(const double &c) {this->m_value += c; return *this;}

    Chip operator-(const Chip &c) {this->m_value -= c.value(); return *this;}
    Chip operator-(const double &c) {this->m_value -= c; return *this;}

    bool operator==(const Chip &chip) { return m_value == chip.value(); }
    bool operator==(const double &chip) { return m_value == chip; }

    bool operator<(const Chip &chip) { return m_value < chip.value(); }
    bool operator<(const double &chip) { return m_value < chip; }

    bool operator<=(const Chip &chip) { return m_value <= chip.value(); }
    bool operator<=(const double &chip) {return m_value <= chip;}

    bool operator>=(const Chip &chip) { return m_value >= chip.value(); }
    bool operator>=(const double &chip) { return m_value >= chip; }

    bool operator>(const Chip &chip) { return m_value > chip.value(); }
    bool operator>(const long &chip) { return m_value > chip; }

    double value() const {return m_value;}

    friend QDebug operator<< (QDebug dbg, const Chip &c){ dbg << c.value(); return dbg.maybeSpace();}
    friend std::ostream& operator<< (std::ostream& o, const Chip &c) { o << c.value();return o;}
private:
    double m_value;
};

#endif // CHIP_H
