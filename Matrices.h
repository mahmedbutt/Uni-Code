#include <iostream>
#include <conio.h>
using namespace std;

class Matrices
{
	int rows, cols;
	int** mat;
	

public:
	Matrices(int r = 0, int c = 0);
	Matrices(const Matrices& M);
	~Matrices();
	void setrows(int r);
	int getrows();
	void setcols(int c);
	int getcols();
	void setmatrix(int a);
	int getmatrix(int& a);
	void print();

	Matrices operator +(const Matrices& B);
	Matrices operator -(const Matrices& B);
	Matrices operator *(const Matrices& B);
	bool operator ==(const Matrices& B);
	//Matrices& operator =(const Matrices& B);
	Matrices& operator++();
	Matrices& operator ++(int q);
	Matrices& operator --();
	Matrices& operator --(int q);
	Matrices operator +=(Matrices& B);
	Matrices operator -=(Matrices& B);
	Matrices operator *=(Matrices& B);
	Matrices operator/=(int a);

	void* operator new(size_t s);
	void operator delete(void*);
	friend ostream& operator << (ostream& output, const Matrices& B);
	friend istream& operator >> (istream& input, Matrices& B);
	int& operator ()(int row, int cols);
	const int& operator ()(int rows, int cols)const;
};
