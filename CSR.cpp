#include "CSR.h"

CSR::CSR() :
	element(nullptr),
	column(nullptr),
	row(nullptr),
	numberOfNonZeroElement(0),
	size(0)
{}

CSR::CSR(double* _p_element, int* _p_column, int* _p_row, int _p_numberOfNonZeroElement, int _p_size) :
	element(new double[_p_numberOfNonZeroElement]),
	column(new int[_p_numberOfNonZeroElement]),
	row(new int[_p_size + 1]),
	numberOfNonZeroElement(_p_numberOfNonZeroElement),
	size(_p_size)
{
	for (int i = 0; i < _p_size + 1; i++)
	{
		row[i] = _p_row[i];
	}

	for (int i = 0; i < _p_numberOfNonZeroElement; i++)
	{
		element[i] = _p_element[i];
		column[i] = _p_column[i];
	}
}

CSR::CSR(const CSR& _p) :
	size(_p.size),
	numberOfNonZeroElement(_p.numberOfNonZeroElement)
{
	element = new double[_p.numberOfNonZeroElement];
	column = new int[_p.numberOfNonZeroElement];
	row = new int[size + 1];

	row[0] = 0;

	for (int i = 0; i < size; i++)
		row[i + 1] = _p.row[i + 1];

	for (int i = 0; i < _p.numberOfNonZeroElement; i++)
	{
		element[i] = _p.element[i];
		column[i] = _p.column[i];
	}
}

CSR::~CSR()
{
	size = 0;
	numberOfNonZeroElement = 0;

	if (element != nullptr)
		delete[] element;
	if (row != nullptr)
		delete[] row;
	if (column != nullptr)
		delete[] column;
}

Vector CSR::operator * (const Vector&_p) const
{
	Vector z(_p);
	for (int i = 0; i < size; i++)
	{
		z[i] = 0;
		for (int j = row[i]; j < row[i + 1]; j++)
			z[i] = z[i] + _p[column[j]] * element[j];
	}
	return z;
}

CSR operator * (double num, const CSR& _p)
{
	CSR temp(_p);
	for (int i = 0; i < _p.numberOfNonZeroElement; i++)
		temp.element[i] *= num;
	return temp;
}

int CSR::demisision() const
{
	return size;
}