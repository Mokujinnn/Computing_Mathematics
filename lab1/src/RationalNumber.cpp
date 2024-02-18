#include "RationalNumber.hpp"

size_t NOD(size_t a, size_t b)
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

size_t NOK(size_t a, size_t b)
{
    return a * b / NOD(a, b);
}

size_t ToCommonDenominator(RationalNumber &n1, RationalNumber &n2)
{
    size_t nok = NOK(n1.denominator, n2.denominator);
    size_t d1 = nok / n1.denominator;
    size_t d2 = nok / n2.denominator;

    n1.denominator *= d1;
    n1.numerator *= d1;
    n2.denominator *= d2;
    n2.numerator *= d2;

    return nok;
}

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

size_t RationalNumber::GetNumerator() const
{
    return this->numerator;
}

size_t RationalNumber::GetDenominator() const
{
    return this->denominator;
}

bool RationalNumber::GetSign() const
{
    return this->sign;
}

void RationalNumber::Reduce()
{
    size_t d = NOD(this->numerator, this->denominator);

    this->denominator /= d;
    this->numerator /= d;
}

//
// Operators in class
//

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

RationalNumber &RationalNumber::operator+=(const RationalNumber &a)
{
    *this = *this + a;
    return *this;
}

RationalNumber &RationalNumber::operator-=(const RationalNumber &a)
{
    *this = *this - a;
    return *this;
}

//
// Operators in class end
//

//
// Operators outside class
//

RationalNumber operator-(const RationalNumber &n)
{
    return RationalNumber(n.GetNumerator(), n.GetDenominator(), !n.GetSign());
}

RationalNumber operator+(const RationalNumber &n1, const RationalNumber &n2)
{
    RationalNumber a(n1);
    RationalNumber b(n2);

    size_t denom = ToCommonDenominator(a, b);
    bool signa = a.GetSign();
    bool signb = b.GetSign();
    size_t numa = a.GetNumerator();
    size_t numb = b.GetNumerator();

    if (signa && signb)
    {
        RationalNumber n(numa + numb, denom, 1);
        n.Reduce();
        return n;
    }
    else if (signa)
    {
        RationalNumber n;
        if (numa > numb)
        {
            n = RationalNumber(numa - numb, denom, 1);
        }
        else if (numa == numb)
        {
            n = RationalNumber(0, 1, 0);
        }
        else
        {
            n = RationalNumber(numb - numa, denom, 0);
        }

        n.Reduce();

        return n;
    }
    else if (signb)
    {
        RationalNumber n;
        if (numb > numa)
        {
            n = RationalNumber(numb - numa, denom, 1);
        }
        else if (numa == numb)
        {
            n = RationalNumber(0, 1, 0);
        }
        else
        {
            n = RationalNumber(numa - numb, denom, 0);
        }

        n.Reduce();

        return n;
    }

    RationalNumber n(numa + numb, denom, 0);
    n.Reduce();

    return n;
}

RationalNumber operator-(const RationalNumber &n1, const RationalNumber &n2)
{
    return n1 + (-n2);
}

//
// Operators outside class end
//