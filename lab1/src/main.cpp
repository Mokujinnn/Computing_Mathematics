#include <iostream>

#include "Matrix.hpp"

int main()
{
    Matrix a(3,3);

    // a.print();

    a.readFromFile("D:\\Files\\Computing_Mathematics\\lab1\\file.txt");

    a.print();

    a.gauss();

    a.print();
    return 0;
}