#pragma once

#include <string>

class Matrix
{
private:
    float *memptr;
    float **matrix;
    float *vector;

    unsigned n;
    unsigned m;
    
    void memoryInit();
public:
    Matrix(const std::string &filename);

    ~Matrix();

    void print();

    void readFromFile(const std::string &filename);

    void gauss();
};

