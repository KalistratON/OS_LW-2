#pragma once
#include <iostream>
#include <memory>
#include "Vector.h"

class Vector;

class CSR {
public:
	double* element;
	int*	row;
	int*	column;
	int		size;
	int		numberOfNonZeroElement;
	
public:
	CSR();
	CSR(double*, int*, int*, int, int);
	CSR(const CSR&);
	~CSR();

	Vector operator * (const Vector&) const;
	
	int demisision() const;

	friend CSR operator * (double, const CSR&);
};