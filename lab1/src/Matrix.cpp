#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Matrix.hpp"

Matrix::Matrix(const std::string &filename)
{
    readFromFile(filename);
}

void Matrix::memoryInit()
{
    this->vector = new float[n];
    this->matrix = new float *[n];
    this->matrix[0] = new float[n * m];

    this->memptr = matrix[0];

    for (int i = 1; i < n; ++i)
    {
        this->matrix[i] = this->matrix[i - 1] + m;
    }

    for (int i = 0; i < n; ++i)
    {
        vector[i] = 0;
        for (int j = 0; j < m; ++j)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::~Matrix()
{
    delete[] memptr;
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
        std::cout << "| ";

        std::cout << vector[i] << '\n';
    }
    std::cout << "----------\n";
}

void Matrix::readFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);

    file >> n;
    m = n + 1;

    memoryInit();

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
            if (!matrix[i][i])
            {
                std::cout << "Division by zero\n";
                std::swap(matrix[i], matrix[i+1]);
            }
            
            float d = matrix[k][i] / matrix[i][i];

            for (int j = i; j < m; ++j)
            {
                matrix[k][j] -= matrix[i][j] * d;
            }

            print();
        }
    }


    for (int i = n - 1; i >= 0 ; --i)
    {
        if (!matrix[i][i])
        {
            std::cout << "ne sovmestna\n";
        }
        
        for (int j = m - 2; j > i ; --j)
        {
            matrix[i][m - 1] -= matrix[i][j] * vector[j];
            matrix[i][j] = 0;
        }

        vector[i] = matrix[i][m-1] / matrix[i][i];
    }
}
