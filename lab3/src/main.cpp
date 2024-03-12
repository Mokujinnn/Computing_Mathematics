#include <iostream>
#include <iomanip>
#include <cmath>

double secantMethod(double left, double right, double eps, double (*func)(double))
{
    double curEps = eps + 1;

    double x0 = left;
    double x1 = (left + right) / 2;
    double x2 = 0;

    while (curEps > eps)
    {
        double y = func(x1);

        x2 = x1 - (y * (x1 - x0)) / (y - func(x0));

        double delta = x0 - x2;
        curEps = std::abs(delta);

        std::cout << "y = " << y << " x = " << x1 << '\n';

        x0 = x1;
        x1 = x2;
    }

    return -1;
}

double f(double x)
{
    return pow(2, x) * x - pow(3, x) + 10;
}

double test(double x)
{
    return 1.5 - 0.4 * pow(x, 1.5) - 0.5 * log(x);
}

int main()
{
    std::cout << std::setprecision(15);
    secantMethod(0.5, 6, 1e-6, f);

    return 0;
}
