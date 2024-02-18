#include <iostream>

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

    RationalNumber a(3, 10, 1);
    RationalNumber b(2, 5, 0);

    std::cout << a + b;

    return 0;
}