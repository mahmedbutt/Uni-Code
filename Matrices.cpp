#include <iostream>
#include "Matrices.h"
using namespace std;

Matrices::Matrices(int r, int c)
{
	rows = r;
	cols = c;
	mat = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mat[i][j] = 0;
		}
	}
}

Matrices::Matrices(const Matrices& M)
{
	rows = M.rows;
	cols = M.cols;

	mat = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mat[i][j] = M.mat[i][j];
		}
	}
}

Matrices::~Matrices()
{
	if (mat != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] mat[i];
		}
	}
	delete mat;
	mat = nullptr;
}

void Matrices::setrows(int r)
{
	rows = r;
}

void Matrices::setcols(int c)
{
	cols = c;
}

int Matrices::getcols()
{
	return cols;
}

int Matrices::getrows()
{
	return rows;
}

void Matrices::setmatrix(int a)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mat[i][j] = a;
		}
	}
}

int Matrices::getmatrix(int& a)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			a = mat[i][j];
		}
	}
	return **mat;
}

void Matrices::print()
{
	cout << "Matrix : ";
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; i < cols; j++) 
		{
			cout << mat[i][j];
		}
	}
}

Matrices Matrices::operator+(const Matrices& B)
{
	Matrices A;
	if (this->cols != B.cols)
	{
		system("pause");
	}
	if (this->rows != B.rows)
	{
		system("pause");
	}


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			A.mat[i][j] = mat[i][j] + B.mat[i][j];
		}
	}
	return A;
}

Matrices Matrices::operator-(const Matrices& B)
{
	if (this->cols != B.cols)
	{
		system("pause");
	}
	if (this->rows != B.rows)
	{
		system("pause");
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			B.mat[i][j] = mat[i][j] - B.mat[i][j];
		}
	}
	return (B);
}

Matrices Matrices::operator*(const Matrices& B)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mat[i][j] = mat[i][j] * B.mat[i][j];
		}
	}
	return(*this);
}

bool Matrices::operator==(const Matrices& B)
{
	if (this->rows != B.rows)
	{
		return(false);
	}
	if (this->cols != B.cols)
	{
		return(false);
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (this->mat[i][j] != B.mat[i][j])
				return(false);
		}
	}
	return(true);
}

//Matrices& Matrices::operator=(const Matrices& B)
//{
//	mat = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		mat[i] = new int[cols];
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			mat[i][j] = B.mat[i][j];
//		}
//	}
//}

Matrices& Matrices::operator ++()
{
	Matrices X;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			X.mat[i][j] = ++mat[i][j];
		}
	}
	return (X);
}

Matrices& Matrices::operator++(int q)
{
	Matrices Y;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Y.mat[i][j] = mat[i][j]++;
		}
	}
	return (Y);
}

Matrices& Matrices::operator--()
{
	Matrices W;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			W.mat[i][j] = --mat[i][j];
		}
	}
	return (W);
}

Matrices& Matrices::operator--(int q)
{
	Matrices Z;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Z.mat[i][j] = mat[i][j]--;
		}
	}
	return (Z);
}

Matrices Matrices::operator+=(Matrices& B)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mat[i][j] += B.mat[i][j];
		}
	}
	return (*this);
}

Matrices Matrices::operator-=(Matrices& B)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mat[i][j] -= B.mat[i][j];
		}
	}
	return (*this);
}

Matrices Matrices::operator*=(Matrices& B)
{

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < B.rows; j++)
		{
			for (int k = 0; k < B.cols; k++)

			mat[i][j] *= B.mat[i][j];
		}
	}
	return (*this);
}



Matrices Matrices::operator /=(int a)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			mat[i][j] /= a;

		}
	}
	return (*this);
}

void* Matrices::operator new(size_t s)
{
	void* arr = malloc(s);
	return arr;
}

void Matrices::operator delete(void* arr)
{
	free(arr);
}

int& Matrices::operator()(int row, int cols)
{
	if (row <= 9 || row >= 0 && cols <= 9 || cols >= 0)
	{
		return(mat[rows][cols]);
	}
}

const int& Matrices::operator()(int rows, int cols) const
{
	if (rows <= 9 || rows >= 0 && cols <= 9 || cols >= 0)
	{
		return(mat[rows][cols]);
	}
}

ostream& operator <<(ostream& output,const Matrices& B)
{
	for (int i = 0; i < B.rows; i++)
	{
		for (int j = 0; j < B.cols; j++)
		{
			output << B.mat[i][j] << " ";
		}
		cout << endl;
	}
	return output;
}

istream& operator >>(istream& input, Matrices& A)
{
	cout << "Enter Rows: ";
	cin >> A.rows;
	cout << "Enter Columns: ";
	cin >> A.cols;
	A.mat = new int* [A.rows];
	for (int i = 0; i < A.rows; i++)
	{
		A.mat[i] = new int[A.cols];
	}
	for (int i = 0; i < A.rows; i++)
	{
		for (int j = 0; j < A.cols; j++)
		{
			input >> A.mat[i][j];
		}
	}
	return input;
}

int main()
{
	int num = 0;
	Matrices m1, m2, m3;

	system("cls");
	cout << "\t\t Menu\t\t\n";
	cout << "1. Addition\n" << "2. Subtraction\n";
	cout << "3. Multiplication\n" << "4. Equals\n" << "5. Assignment\n";
	cout << "6. Pre-Increment\n" << "7. Post-Increment\n" << "8. Pre-Decrement\n" << "9. Post-Decrement\n";
	cout << "10. +=\n" << "11. -=\n" << "12. *=\n" << "13. /=\n" << "14. New Operator & Delete Operator\n" << "16. Paranthesis\n";
	cout << "17. Stream Insertion\n" << "18. Stream Extraction\n" << "19. Transpose of Matrix\n" << "20. Power of Matrix\n" << "21. Exit\n";
	cout << "\nInput : ";
	cin >> num;

	if (num == 1)
	{
		cin >> m1;
		cin >> m2;
		///system("cls");
		m3 = m2 + m1;
		cout << "Addition is: "<<m3;
	}
	else if (num == 2)
	{
		cin >> m1;
		cin >> m2;
		system("cls");
		m3 = m2 - m1;
		cout << "Subtraction is: "<<m3;
	}
	else if (num == 3)
	{
		cin >> m1;
		cin >> m2;
		system("cls");
		m3 = m2 * m1;
		cout << "Multiplication is: " << m3;
	}
	else if (num == 4)
	{
		cin >> m1;
		cin >> m2;
		system("cls");
		if (m1 == m2)
			cout << "They are Equal.\n";
		else
			cout << "They are not Equal.\n";
	}
	else if (num == 5)
	{
		cin >> m1;
		cin >> m2;
		system("cls");
	}
	else if (num == 6)
	{
		cin >> m1;
		cin >> m2;
		system("cls");
		cout << "This is Pre-Increment: ";
		cout << ++m1;
		cout << ++m2;
	}
	else if (num == 7)
	{
		cin >> m1;
		cin >> m2;
		system("cls");

		cout << "This is Post-Increment: ";
		cout << m1++;
		cout << m2++;
	}
	else if (num == 8)
	{
		cin >> m1;
		cin >> m2;
		system("cls");

		cout << "This is Pre-Decrement: ";
		cout << --m1;
		cout << --m2;
	}
	else if (num == 9)
	{
		cin >> m1;
		cin >> m2;
		system("cls");

		cout << "This is Post-Decrement: ";
		cout << m1--;
		cout << m2--;
	}
	else if (num == 10)
	{
		cin >> m1;
		cin >> m2;
		system("cls");
		m1 += m2;
	}
	else if (num == 11)
	{
		cin >> m1;
		cin >> m2;
		system("cls");
		m1 -= m2;
	}
	else if (num == 12)
	{
		cin >> m1;
		cin >> m2;
		system("cls");
		m1 *= m2;
	}
	else if (num == 13)
	{
	int a;
	cin >> a;
	cin >> m1;
	cin >> m2;
	system("cls");
	m1 /= a;
	}
	else if (num == 14)
	{
	int size;
	cin >> size;
	Matrices* p = new Matrices[size];
		system("cls");
		delete[] p;
	}
	else if (num == 15)
	{
	cout << "All outputs are dealt through Stream Insertion And Extraction: ";
		system("cls");
	}
	else if (num == 16)
	{
		system("cls");
	}
	else if (num == 17)
	{
		system("cls");
	}
	else if (num == 18)
	{
		system("cls");
	}
	else if (num == 19)
	{
		system("cls");
	}
	else if (num == 20)
	{
		system("cls");
	}
	else if (num == 21)
	{
		system("cls");
		return 0;
	}
	else if (num < 1 || num > 21)
	{
		cout << "Invalid Input";
		cin >> num;
		while (num != -1)
		{
			cout << "Invalid Input";
			cin >> num;
		}
	}

	system("pause");
}
