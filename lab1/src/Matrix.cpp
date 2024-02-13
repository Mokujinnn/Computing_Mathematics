#include <iostream>

#include "Matrix.hpp"

Matrix::Matrix(unsigned _n, unsigned _m) : n(_n), m(_m + 1)
{
    this->matrix = new float *[n];
    this->matrix[0] = new float[n * m];

    for (int i = 1; i < n; ++i)
    {
        this->matrix[i] = this->matrix[i-1] + m;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = i + j;

            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

Matrix::~Matrix()
{
    delete [] matrix[0];
    delete [] matrix;
}
