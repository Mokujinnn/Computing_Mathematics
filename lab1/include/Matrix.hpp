#pragma once

#include <string>

class Matrix
{
private:
    float **matrix;
    float *vector;

    unsigned n;
    unsigned m;
    
    
public:
    Matrix(unsigned n, unsigned m);

    ~Matrix();

    void print();

    void readFromFile(const std::string &filename);

    void gauss();
};

