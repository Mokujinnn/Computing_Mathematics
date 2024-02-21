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
    this->vector = new RationalNumber[n];
    this->matrix = new RationalNumber *[n];
    this->matrix[0] = new RationalNumber[n * m];

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
            std::cout << std::setw(6) << matrix[i][j] << ' ';

        }
        std::cout << "| ";

        std::cout << vector[i] << '\n';
    }
    std::cout << "----------\n";
}

bool Matrix::IsVoidStr(int k)
{
    bool flag = true;
    for (int i = 0; i < m - 2; i++)
    {
        if (matrix[k][i] != 0 )
        {
            flag = false;
            break;
        }
    }
    return flag && matrix[k][m-1] == 0;
}

void Matrix::readFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);

    file >> n >> m;

    memoryInit();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            file >> matrix[i][j];
        }
    }

    file.close();
}

void Matrix::gauss()
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int k = i + 1; k < n; ++k)
        {
            int swap = 0;
            while (matrix[i][i] == 0)
            {
                // std::cout << "Division by zero\n";
                swap++;
                if (i + swap < n)
                {
                    std::swap(matrix[i], matrix[i+swap]);
                }
                else
                    break;
            }
            
            RationalNumber d = matrix[k][i] / matrix[i][i];

            for (int j = i; j < m; ++j)
            {
                matrix[k][j] -= matrix[i][j] * d;
            }

            print();

            if (matrix[k][k] == 0 && matrix[k][m-1] != 0)
            {
                std::cout << "ne sovmestna\n";
                return;
            }
        }
    }


    for (int i = n - 1; i >= 0 ; --i)
    {
        if (matrix[i][i] == 0 && matrix[i][m-1] != 0)
        {
            std::cout << "ne sovmestna\n";
            break;
        }

        if (IsVoidStr(i) || m - 1 > n)
        {
            std::cout << "beskonechno mnogo reshenii\n";
            break;
        }
        
        for (int j = m - 2; j > i ; --j)
        {
            matrix[i][m - 1] -= matrix[i][j] * vector[j];
            matrix[i][j] = 0;
        }

        vector[i] = matrix[i][m-1] / matrix[i][i];

        print();
    }
}
