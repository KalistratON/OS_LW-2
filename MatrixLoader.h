#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <tuple>

class MatrixLoader
{
private:

    struct CSRElement
    {
        int row;
        int col;
        double value;
    };

    int size;
    int countElem;
    double* elements;
    int* columnInd;
    int* rowInd;

public:

    MatrixLoader(const std::string& file, int size);

    static void SortFile(const std::string& file);

    std::tuple<double*, int*, int*, int, int> GetMatrix();
};
