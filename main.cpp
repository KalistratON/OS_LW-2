#include "CSR.h"
#include "MatrixLoader.h"
#include <cmath>

Vector gradientMethod(const CSR&, const Vector&, double);
bool iteration(const CSR&, const Vector&, Vector&, Vector&, Vector&, Vector&, double);

Vector randomResult(int);

int main()
{
	MatrixLoader loader("1138_bus_SORTED.txt", 1138);
	std::tuple < double*, int*, int*, int, int > _p = loader.GetMatrix();

	double* elem;
	int*	column;
	int*	row;
	int		size;
	int		count;

	std::tie(elem, column, row, count, size) = _p;
	CSR A(elem, column, row, count, size);
	
	double eps;
	std::cout << "Input mark of relation" << std::endl;
	std::cin  >> eps;

	//Vector b = randomResult(size);
	Vector b(size);
	b[0] = 1;

	std::ofstream _file("result_of_calc.txt");
	_file << "Answer:" << std::endl << gradientMethod(A, b, eps) << std::endl;
	_file.close();

	return 0;
}

Vector gradientMethod(const CSR& A, const Vector& b, double eps)
{
	int sizeOfSLAE = A.demisision();

	Vector x(sizeOfSLAE);
	Vector r(b);
	Vector r_prev(b);
	Vector z(b);
	
	iteration(A, b, x, r, z, r_prev, eps);

	return x;
}

bool iteration(const CSR& A, const Vector& b, Vector& x, Vector& r, Vector& r_prev, Vector& z, double eps)
{
	double alfa = (r * r) / ((A * z) * z);
	x = x + alfa * z;
	r_prev = r;
	r = r - alfa * A * z;
	double beta = (r * r) / (r_prev * r_prev);
	z = r + beta * z;
	if (sqrt(r * r) / sqrt(b * b) >= eps)
		iteration(A, b, x, r, r_prev, z, eps);
	else
		return true;
}

Vector randomResult(int size)
{
	Vector b(size);
	for (int i = 0; i < size; i++)
		b[i] = rand() % 10 - 5;
	return b;
}