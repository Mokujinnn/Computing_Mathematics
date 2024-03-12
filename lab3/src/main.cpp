#include <iostream>
#include <iomanip>
#include <cmath>

double nonLinear(double left, double right, double eps, double (*func)(double))
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

        x0 = x1;
        x1 = x2;

        std::cout << "y = " << y << " x = " << x1 << '\n';
    }

    return -1;
}

double f(double x)
{
    return pow(2, x) * x - pow(3, x) + 10;
}

int main()
{
    std::cout << std::setprecision(9);
    nonLinear(3, 4, 0.0000000001, f);

    return 0;
}
