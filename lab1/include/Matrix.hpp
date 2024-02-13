#pragma once

class Matrix
{
private:
    float **matrix;

    unsigned n;
    unsigned m;
    
    
public:
    Matrix(unsigned n, unsigned m);
    ~Matrix();
};

