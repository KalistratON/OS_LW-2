#include "MyException.h"
OutOfRageExeption::OutOfRageExeption(const char* error, const int &index_1):exception(error)
{
	Index_1 = index_1;
}
int OutOfRageExeption::GetFirst() const { return Index_1; }
InCompatibleDimExeption::InCompatibleDimExeption(const char* error,const int& index_1,const int& index_2) :exception(error)
{
	Index_1 = index_1;
	Index_2 = index_2;
}
int InCompatibleDimExeption::GetFirst() const { return Index_1; }
int InCompatibleDimExeption::GetSecond() const { return Index_2; }