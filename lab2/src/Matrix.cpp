#include "Matrix.hpp"


// RationalNumber max(RationalNumber *a, size_t n)
// {
//     RationalNumber m = a[0];

//     for (size_t i = 1; i < n; i++)
//     {
//         if (a[i] > m)
//         {
//             m = a[i];
//             break;
//         }
//     }
    
//     return m;
// }

void Matrix::seidel()
{
    RationalNumber eps = 1e-3;
    RationalNumber epsArr[n];
    RationalNumber curEps = eps;
    IterCounter = 0;

    for (int i = 0; i < n; ++i)
    {
        vector[i] = 0;
        epsArr[i] = 0;
    }

    while (curEps < eps || IterCounter < 1000)
    {
        for (int i = 0; i < n; ++i)
        {
            vector[i] = matrix[i][m - 1];
            for (int j = 0; j < m - 1; ++j)
            {
                if (j != i)
                {
                    vector[i] -= matrix[i][j] * vector[j];
                }
            }
            vector[i] /= matrix[i][i];

            epsArr[i] = (vector[i] - epsArr[i]).abs();
        }

        IterCounter++;

        curEps = max(epsArr, n);
    }

    std::cout << "Number of iterations: " << IterCounter << '\n'; 
}