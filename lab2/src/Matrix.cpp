#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

#include "Matrix.hpp"

Matrix::Matrix(const std::string &filename)
{
    readFromFile(filename);
}

Matrix::~Matrix()
{
}

void Matrix::readFromFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::in);

    if (!file.is_open())
    {
        std::cerr << "file not open\n";
        std::exit(1);
    }
    int n, m;

    file >> n >> m;

    matrix.resize(n);
    vector = std::vector<double>(n, 0);

    for (int i = 0; i < n; i++)
    {
        std::vector<double> &arr = matrix[i];
        arr.resize(m);

        for (int j = 0; j < m; j++)
        {
            double tmp;
            file >> tmp;
            arr[j] = tmp;
        }
        // matrix[i] = arr;
    }

    file.close();
}

void Matrix::print()
{
    for (auto m : matrix)
    {
        for (auto n : m)
        {
            std::cout << std::setw(5) << n << ' ';
        }
        std::cout << '\n';
    }
}

void Matrix::printvec()
{
    std::cout << std::setprecision(15);
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << 'x' << i << ": " << vector[i] << ' ';
    }
    std::cout << '\n';
}

bool Matrix::convergenceCheck()
{
    double sum = 0;
    bool flag = true;
    for (int i = 0; i < matrix.size(); i++)
    {
        double tmp = std::abs(matrix[i][i]);
        sum = 0;

        for (int j = 0; j < matrix[i].size() - 1; j++)
        {
            sum += abs(matrix[i][j]);
        }

        if (tmp < sum)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

double max(double *a, size_t n)
{
    double m = a[0];

    for (size_t i = 1; i < n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }

    return m;
}

bool Matrix::NextSet(int n) // broken
{
    int j = n - 2;
    while (j != -1 && std::abs(matrix[j][j]) >= std::abs(matrix[j + 1][j+1]))
        j--;

    if (j == -1)
        return false; // больше перестановок нет
    int k = n - 1;
    while (std::abs(matrix[j][j]) >= std::abs(matrix[k][k]))
        k--;

    std::swap(matrix[j], matrix[k]);
    int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
    while (l < r)
        std::swap(matrix[l++], matrix[r--]);

    return true;
}

void Matrix::seidel()
{
    int sizen = matrix.size();
    int sizem = matrix[0].size();

    double eps = 1e-3;
    double epsArr[sizen];
    double curEps = eps + 1;
    IterCounter = 0;

    for (int i = 0; i < sizen; ++i)
    {
        vector[i] = 0;
        epsArr[i] = 0;
    }

    if (!convergenceCheck())
    {
        std::cout << "Method not convergence\n";

        // for (int i = 0; i < sizen; i++)
        // {
        //     for (int j = 0; j < sizen - 1; j++)
        //     {
        //         std::swap(matrix[j], matrix[j + 1]);
        //         print();
        //     }

        //     // print();
        // }

        while (NextSet(sizen))
        {
            print();
        }

        // return;
    }

    while (curEps > eps && IterCounter < 100)
    {
        for (int i = 0; i < sizen; ++i)
        {
            double tmp = vector[i];
            vector[i] = matrix[i][sizem - 1];

            for (int j = 0; j < sizem - 1; ++j)
            {
                if (j != i)
                {
                    vector[i] -= matrix[i][j] * vector[j];
                }
            }
            vector[i] /= matrix[i][i];

            epsArr[i] = std::abs(vector[i] - tmp);
            // printvec();
        }

        IterCounter++;

        curEps = max(epsArr, sizen);
        printvec();
    }

    std::cout << "Number of iterations: " << IterCounter << '\n';
}