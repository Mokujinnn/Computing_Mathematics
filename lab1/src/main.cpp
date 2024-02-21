#include <iostream>
#include <cmath>

#include "RationalNumber.hpp"
#include "Matrix.hpp"

int main()
{

    Matrix a("D:\\Files\\Computing_Mathematics\\lab1\\file.txt");

    a.print();

    a.gauss();

    a.print();

    return 0;
}