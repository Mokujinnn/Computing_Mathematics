#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

double l(double x, int k, const std::vector<double> &v)
{
    double tmp = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (i != k)
        {
            tmp *= (x - v[i]) / (v[k] - v[i]);
        }
    }
    return tmp;
}

double Lagrange(double x, const std::vector<double> &vectx, const std::vector<double> &vecty)
{
    if (vectx.size() != vecty.size())
    {
        std::cout << "vectx > vecty || vectx < vectyn\n";
        return NAN;
    }

    double tmp = 0;
    for (int i = 0; i < vectx.size(); i++)
    {
        tmp += l(x, i, vectx) * vecty[i];
    }
    
    return tmp;
}

int main(int argc, char const *argv[])
{
    std::vector<double> x;
    std::vector<double> y;
    std::string s;

    double tmp;

    std::ifstream file(argv[1]);

    if (!file.is_open())
    {
        std::cout << "File not is open\n";
        exit(EXIT_FAILURE);
    }
    
    std::getline(file, s);
    std::stringstream out(s);
    
    while (out >> tmp)
    {
        x.push_back(tmp);
    }
    out.clear();

    std::getline(file, s);
    out.str(s);

    while (out >> tmp)
    {
        y.push_back(tmp);
    }
    file.close();

    // for (int i = 0; i < x.size(); i++)
    // {
    //     std::cout << "x = " << x[i] << " y = " << y[i] << '\n';
    // }

    double x0 = std::stod(argv[2]);

    std::cout << Lagrange(x0, x, y);

    return 0;
}
