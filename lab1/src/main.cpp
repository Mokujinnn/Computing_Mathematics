#include <iostream>
#include <cmath>

#include "RationalNumber.hpp"
#include "Matrix.hpp"

int main()
{

    // Matrix a("D:\\Files\\Computing_Mathematics\\lab1\\file.txt");

    // // a.print();

    // // a.readFromFile("D:\\Files\\Computing_Mathematics\\lab1\\file.txt");

    // a.print();

    // a.gauss();

    // a.print();

    RationalNumber a(3, 10, 0);
    RationalNumber b(2, 5, 0);

    // a *= a;

    // std::cout << a << ' ' << b << ' ' << std::floor(1.2);

    a = 51.45;

    std::cout << a << '\n';

    std::cout << a.ToDouble();

    return 0;
}