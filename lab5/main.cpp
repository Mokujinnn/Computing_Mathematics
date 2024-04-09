#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <omp.h>

double func(double x)
{
    return exp(-x * x);
}

void integral(double a, double b, int startn, double eps, double (*func)(double) = func)
{
    double sq[2];
    #pragma omp parallel // num_threads(1)
    {
        int n = startn, k;
        double delta = 1;
        for (k = 0; delta > eps; n *= 2, k ^= 1)
        {
            double h = (b - a) / n;
            double s = 0;
            sq[k] = 0;
            #pragma omp barrier

            #pragma omp for nowait
            for (int i = 0; i < n; i++)
            {
                s += func(a + h * i);
            }

            #pragma omp atomic
            sq[k] += s * h;

            #pragma omp barrier
            if (n > startn)
            {
                delta = fabs(sq[k] - sq[k ^ 1]) / 3.0;
            }
            // #pragma omp master
            // std::cout << k << " " << std::setprecision(12) << sq[k] << '\n';
        }
        #pragma omp single
        std::cout << std::setprecision(12) << "Result: " << sq[k] << " Eps: " << eps << " N: " << n / 2 << '\n';
    }
}

int main(int argc, char const *argv[])
{
    using namespace std::chrono;

    auto t = steady_clock::now();
    integral(0.1, 1, 10, 1.0e-6, [](double x) {return x * x;});
    auto e = steady_clock::now();
    std::cout << "Elapsed time: " << duration_cast<nanoseconds>(e - t).count() / 1e+9 << "\n";
    
    return 0;
}
