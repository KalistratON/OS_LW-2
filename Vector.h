#pragma once
#include <iostream>
#include "MyException.h"

class Vector
{
	int size;
	double* element;

public:
	Vector();
	Vector(int);
	Vector(double*, int);
	Vector(const Vector&);
	~Vector();

	const Vector& operator = (const Vector&);

	Vector operator + (const Vector&) const;
	Vector operator - (const Vector&) const;
	Vector operator - () const;
	double& operator [] (int) const;

	Vector operator * (double) const;
	double operator * (const Vector&) const;
	friend Vector operator * (double number, const Vector& obj);
	friend std::ostream& operator << (std::ostream&, const Vector&);
};

