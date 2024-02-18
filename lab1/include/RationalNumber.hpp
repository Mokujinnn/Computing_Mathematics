#pragma once

#include <iostream>

class RationalNumber
{
private:
    size_t numerator;
    size_t denominator;
    bool sign;

    size_t NOD(size_t a, size_t b);
    size_t NOK(size_t a, size_t b);

    void ToCommonDenominator(RationalNumber &n);
    void Reduce();

public:
    RationalNumber();
    RationalNumber(size_t numerator, size_t denominator, bool sign = 0);
    RationalNumber(const RationalNumber &a);
    ~RationalNumber();

    size_t GetNumerator() const;
    size_t GetDenominator() const;

    friend std::ostream &operator<<(std::ostream &os, const RationalNumber &n)
    {
        return os << n.numerator << '/' << n.denominator;
    }

    RationalNumber &operator=(const RationalNumber &a);
};
