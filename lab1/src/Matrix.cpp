#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Matrix.hpp"

Matrix::Matrix(unsigned _n, unsigned _m) : n(_n), m(_m + 1)
{
    this->vector = new float[n];
    this->matrix = new float *[n];
    this->matrix[0] = new float[n * m];

    for (int i = 1; i < n; ++i)
    {
        this->matrix[i] = this->matrix[i - 1] + m;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::~Matrix()
{
    delete[] matrix[0];
    delete[] matrix;
    delete[] vector;
}

void Matrix::print()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << std::setw(3) << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "----------\n";
}

void Matrix::readFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);
    file >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            file >> matrix[i][j];
        }
    }
}

void Matrix::gauss()
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int k = i + 1; k < n; ++k)
        {
            float d = matrix[k][i] / matrix[i][i];

            for (int j = i; j < m; ++j)
            {
                matrix[k][j] -= matrix[i][j] * d;
            }
        }
    }
    

    for (int i = n - 1; i >= 0 ; --i)
    {
        for (int j = m - 2; j > i ; --j)
        {
            matrix[i][m - 1] -= matrix[i][j] * vector[j];
            matrix[i][j] = 0;
        }

        vector[i] = matrix[i][m-1] / matrix[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << vector[i] << ' ';
    }
    
    std::cout << '\n';
}
