#pragma once

#include <iostream>

class RationalNumber
{
private:
    size_t numerator;
    size_t denominator;
    bool sign;

    friend size_t ToCommonDenominator(RationalNumber &n1, RationalNumber &n2);

public:
    RationalNumber();
    RationalNumber(size_t numerator, size_t denominator, bool sign = 0);
    RationalNumber(const RationalNumber &a);
    ~RationalNumber();

    size_t GetNumerator() const;
    size_t GetDenominator() const;
    bool GetSign() const;
    void Reduce();

    friend std::ostream &operator<<(std::ostream &os, const RationalNumber &n)
    {
        if (n.sign)
        {
            return os << '-' << n.numerator << '/' << n.denominator;
        }
        else
        {
            return os << n.numerator << '/' << n.denominator;
        }
    }

    RationalNumber &operator=(const RationalNumber &a);
};

size_t NOD(size_t a, size_t b);
size_t NOK(size_t a, size_t b);

RationalNumber operator+(const RationalNumber &n1, const RationalNumber &n2);
RationalNumber operator-(const RationalNumber &n);