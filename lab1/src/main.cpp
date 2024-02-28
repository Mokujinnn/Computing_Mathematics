#include <iostream>
#include <cmath>

#include "RationalNumber.hpp"
#include "Matrix.hpp"

int main()
{

    Matrix a("../lab1/file1.txt");

    a.print();

    a.gauss();

    a.print();

    return 0;
}