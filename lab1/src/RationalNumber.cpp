#include <RationalNumber.hpp>

using Num = RationalNumber;

Num::RationalNumber()
    : numerator(0),
      denominator(1),
      sign(0)
{

    std::cout << NOK(31265, 32712);
}

Num::~RationalNumber()
{
}

size_t Num::NOD(size_t a, size_t b)
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

size_t Num::NOK(size_t a, size_t b)
{
    return a * b / NOD(a, b);
}

size_t Num::GetNumerator() const
{
    return this->numerator;
}

size_t Num::GetDenominator() const
{
    return this->denominator;
}

