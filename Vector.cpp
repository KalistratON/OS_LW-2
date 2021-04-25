#include "Vector.h"

Vector::Vector() :
	size(0),
	element(nullptr)
{}

Vector::Vector(int _p_size) :
	size(_p_size),
	element(new double[size])
{
	for (int i = 0; i < size; i++)
		element[i] = 0;
}

Vector::Vector(double* _p_element, int _p_size) :
	size(_p_size),
	element(new double[size])
{
	for (int i = 0; i < size; i++)
		element[i] = _p_element[i];
}

Vector::Vector(const Vector& _p) :
	size(_p.size)
{
	element = new double[size];
	for(int i = 0; i < size; i++)
		element[i] = _p.element[i];
}

Vector::~Vector()
{
	size = 0;
	if (element != nullptr)
		delete[] element;
	element = nullptr;
}

const Vector& Vector::operator = (const Vector& object)
{
	if (this == &object)
		return *this;
	if (this->size != object.size)
	{
		delete[]this->element;
		this->size = object.size;
		this->element = new double[this->size];
	}
	for (int i = 0;i < this->size;i++)
		this->element[i] = object.element[i];
	return (*this);
}


Vector Vector::operator + (const Vector& _p) const
{
	if (size != _p.size)
	{
		throw InCompatibleDimExeption("ERROR: Attempt to sum vectors with different sizes: ", size, _p.size);
	}
	Vector temp(*this);
	for (int i = 0; i < size;i++)
		temp.element[i] += _p.element[i];
	return temp;
}

Vector Vector::operator - (const Vector& _p) const
{
	if (size != _p.size)
	{
		throw InCompatibleDimExeption("ERROR: Attempt to sum vectors with different sizes: ", size, _p.size);
	}
	Vector temp(*this);
	for (int i = 0; i < size;i++)
		temp.element[i] -= _p.element[i];
	return temp;
}

Vector Vector::operator - () const
{
	Vector temp(*this);
	for (int i = 0; i < temp.size;i++)
		temp.element[i] = -element[i];
	return temp;

}

Vector Vector::operator * (double number) const
{
	Vector temp(*this);
	for (int i = 0; i < temp.size;i++)
		temp.element[i] *= number;        
	return temp;
}

double  Vector::operator * (const Vector& _p) const
{
	if (size != _p.size)
	{
		throw InCompatibleDimExeption("ERROR: Attempt to sum vectors with different sizes: ", size, _p.size);
		return -1;
	}
	double skal = 0;
	for (int i = 0; i < size;i++)
		skal += (element[i] * _p.element[i]);

	return skal;

}

Vector operator * (double number, const Vector& obj)
{
	Vector temp(obj);
	for (int i = 0; i < obj.size;i++)
		temp.element[i] *= number; 
	return temp;
}

double& Vector::operator [] (int i) const
{
	if (size <= i || i < 0)
	{
		throw OutOfRageExeption("ERROR: Not exist this coordinate: ", i);
	}
	return element[i];
}

std::ostream& operator << (std::ostream& out, const Vector& obj)
{
	for (int i = 0; i < obj.size;i++)
	{
		out << obj[i] << std::endl;
	}
	return out;
}

