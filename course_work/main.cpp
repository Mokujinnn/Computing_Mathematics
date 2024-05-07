#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

double alphE = 0.999;
double alphI = 0.999;
double k = 0.042;
double ro = 0.952;
double beta = 0.999;
double mu = 0.0188;
double c = 1;
double tao = 2;

inline double getN(double S, double E, double I, double R, double D)
{
    return S + E + I + R + D;
}

inline double getdS(double S, double E, double I, double N)
{
    return (-c * (alphI * S * I / N + alphE * S * E / N));
}

inline double getdE(double S, double E, double I, double N)
{
    return (c * (alphI * S * I / N + alphE * S * E / N)) - ((k + ro) * E);
}

inline double getdI(double E, double I)
{
    return k * E - beta * I - mu * I;
}

inline double getdR(double E, double I)
{
    return beta * I + ro * E;
}

inline double getdD(double I)
{
    return mu * I;
}

double SEIRD(double S0, double E0, double I0, double R0, double D0, int t0, int t, double h)
{
    double S = S0, E = E0, I = I0, R = R0, D = D0;

    int N;
    for (int i = t0; i < t / h; i++)
    {
        N = getN(S, E, I, R, D);

        S = S0 + h * getdS(S0, E0, I0, N);
        E = E0 + h * getdE(S0, E0, I0, N);
        I = I0 + h * getdI(E0, I0);
        R = R0 + h * getdR(E0, I0);
        D = D0 + h * getdD(I0);

        S0 = S;
        E0 = E;
        I0 = I;
        R0 = R;
        D0 = D;

        // if (i % 100 == 0)
        // {
        //     std::cout << std::fixed << std::setprecision(9);
        //     std::cout << "S0 = " << S0 << '\n';
        //     std::cout << "E0 = " << E0 << '\n';
        //     std::cout << "I0 = " << I0 << '\n';
        //     std::cout << "R0 = " << R0 << '\n';
        //     std::cout << "D0 = " << D0 << "\n\n";
        // }
    }

    return k * E / 0.58;
}

int main(int argc, char const *argv[])
{
    double q8 = 99;
    double q9 = 24;

    double S0 = 2798170 - q8 - q9;
    double E0 = q8;
    double I0 = 0;
    double R0 = q9;
    double D0 = 0;

    std::ofstream file("file1.txt");

    file << "i,n\n";

    for (int i = 1; i <= 90; i++)
    {
        file << i << ',' << SEIRD(S0, E0, I0, R0, D0, 0, i, 0.01) << '\n';
    }
    file.close();

    return 0;
}
