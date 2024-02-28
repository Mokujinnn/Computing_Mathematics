#pragma once

#include <vector>
#include <string>

class Matrix
{
private:
    std::vector<std::vector<double>> matrix;
    std::vector<double> vector;

    size_t IterCounter;

    bool convergenceCheck();
    void swapLines(int n);
    bool NextSet(int n);
public:
    Matrix(const std::string &filename);
    ~Matrix();

    void readFromFile(const std::string &filename);
    void print();
    void printvec();
    void seidel();
};
