#include "MatrixLoader.h"


MatrixLoader::MatrixLoader(const std::string& fileName, int _size)
{
    size = _size;
    std::fstream file(fileName);
    std::string temp;

    getline(file, temp);

    countElem = std::stoi(temp);

    elements = new double[countElem];
    columnInd = new int[countElem];
    rowInd = new int[size + 1];

    rowInd[0] = 0;

    std::stringstream iss;

    std::string number;
    int count = 0;
    int row = 1;
    int countInRow = 0;

    while (getline(file, temp))
    {
        iss << temp;

        iss >> number;
        if (std::stoi(number) == row)
            countInRow++;
        else
        {
            rowInd[row] = countInRow;
            countInRow++;
            row++;
        }

        iss >> number;
        columnInd[count] = (std::stoi(number) - 1);

        iss >> number;
        elements[count] = (atof(number.c_str()) - 1);

        count++;
        iss.clear();
    }

    rowInd[row] = countInRow;
}

void MatrixLoader::SortFile(const std::string& fileName)
{
    std::string temp;
    std::string number;
    CSRElement elem;

    std::vector<CSRElement> vec;

    std::fstream file(fileName);

    std::stringstream iss;

    while (getline(file, temp))
    {
        iss << temp;

        iss >> number;
        elem.row = std::stoi(number);

        iss >> number;
        elem.col = std::stoi(number);

        iss >> number;
        elem.value = atof(number.c_str());

        vec.push_back(elem);

        iss.clear();
    }

    std::sort(vec.begin(), vec.end(), [](CSRElement& a, CSRElement& b)
        {
            if (a.row < b.row)
                return true;
            return false;
        });

    std::vector<CSRElement>::iterator it1 = vec.begin();

    std::vector<CSRElement>::iterator it2 = std::find_if(vec.begin(), vec.end(), [&it1](CSRElement& a)
        {
            if (a.row == it1->row + 1)
                return true;
            return false;
        });

    while (it1 != vec.end())
    {
        std::sort(it1, it2, [](CSRElement& a, CSRElement& b)
            {
                if (a.col < b.col)
                    return true;
                return false;
            });

        it1 = it2;
        it2 = std::find_if(it1, vec.end(), [&it1](CSRElement& a)
            {
                if (a.row == it1->row + 1)
                    return true;
                return false;
            });
    }

    file.close();

    std::string newName = fileName;
    newName.resize(newName.size() - 4);
    newName += "_SORTED.txt";
    std::ofstream file2(newName);

    file2 << vec.size() << std::endl;
    for (auto& el : vec)
    {
        file2 << el.row << " " << el.col << " " << el.value << std::endl;
    }
    file2.close();
}

std::tuple<double*, int*, int*, int, int> MatrixLoader::GetMatrix()
{
    return (std::make_tuple(elements, columnInd, rowInd, countElem, size));
}