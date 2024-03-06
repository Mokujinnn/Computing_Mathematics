#include <iostream>

#include "Matrix.hpp"

int main()
{
    Matrix m("../lab2/file.txt");

    m.print();

    m.seidel();

    m.print();
    m.printvec();
    
    return 0;
}