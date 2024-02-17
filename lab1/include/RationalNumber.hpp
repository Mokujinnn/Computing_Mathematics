#pragma once

#include <iostream>

class RationalNumber
{
    using Num = RationalNumber;

private:
    size_t numerator;
    size_t denominator;
    bool sign;

    size_t NOD(size_t a, size_t b);
    size_t NOK(size_t a, size_t b);

    void ToCommonDenominator(Num &n1, Num &n2);

public:
    RationalNumber();
    ~RationalNumber();

    size_t GetNumerator() const;
    size_t GetDenominator() const;

    friend std::ostream &operator<<(std::ostream &os, const Num &n)
    {
        return os << n.numerator << '/' << n.denominator;
    }

    // Num &operator+(const Num &num);
};
