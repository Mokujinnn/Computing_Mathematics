#pragma once

#include <string>

#include "RationalNumber.hpp"

class Matrix
{
private:
    RationalNumber *memptr;
    RationalNumber **matrix;
    RationalNumber *vector;

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

