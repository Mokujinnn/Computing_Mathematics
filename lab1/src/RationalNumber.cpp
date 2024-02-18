#include <set>

#include "RationalNumber.hpp"

// using RationalNumber = RationalRationalNumberber;

RationalNumber::RationalNumber()
    : numerator(0),
      denominator(1),
      sign(0)
{
}

RationalNumber::RationalNumber(size_t numerator, size_t denominator, bool sign)
    : numerator(numerator),
      denominator(denominator),
      sign(sign)
{
}

RationalNumber::RationalNumber(const RationalNumber &a)
    : numerator(a.numerator),
      denominator(a.denominator),
      sign(a.sign)
{
}

RationalNumber::~RationalNumber()
{
}

size_t RationalNumber::NOD(size_t a, size_t b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }

    return (a == 0) ? b : a;
}

size_t RationalNumber::NOK(size_t a, size_t b)
{
    return a * b / NOD(a, b);
}

size_t RationalNumber::GetNumerator() const
{
    return this->numerator;
}

size_t RationalNumber::GetDenominator() const
{
    return this->denominator;
}

void RationalNumber::ToCommonDenominator(RationalNumber &n)
{
    size_t nok = NOK(this->denominator, n.denominator);
    size_t d1 = nok / this->denominator;
    size_t d2 = nok / n.denominator;

    this->denominator *= d1;
    this->numerator *= d1;
    n.denominator *= d2;
    n.numerator *= d2;
}

void RationalNumber::Reduce()
{
    size_t d = NOD(this->numerator, this->denominator);

    this->denominator /= d;
    this->numerator /= d;
}

RationalNumber &RationalNumber::operator=(const RationalNumber &a)
{
    if (this != &a)
    {
        this->numerator = a.numerator;
        this->denominator = a.denominator;
        this->sign = a.sign;
    }
    
    return *this;
}

// RationalNumber &operator+(const RationalNumber &n1, const RationalNumber &n2)
// {

// }