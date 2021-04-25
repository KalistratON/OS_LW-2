#pragma once
#include <exception>
class OutOfRageExeption : public std::exception
{
private:
	int Index_1;
public:
	OutOfRageExeption(const char*, const int&);
	int GetFirst() const;
};
class InCompatibleDimExeption : public std::exception
{
private:
	int Index_1;
	int Index_2;
public:
	InCompatibleDimExeption(const char*, const int&, const int&);
	int GetFirst() const;
	int GetSecond() const;
};
