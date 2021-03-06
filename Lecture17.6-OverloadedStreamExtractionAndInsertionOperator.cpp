#include<iostream>
using namespace std;

class ComplexNumber
{
	
	//friend functions can directly access private data of class
	friend ostream& operator<<(ostream&, const ComplexNumber&);// overloaded stream insertion operator
	friend istream& operator>>(istream&, ComplexNumber&);// overloaded stream insertion operator
	//These functions are friends of our class

private:
	int real;
	int imaginary;
public:
	ComplexNumber();
	ComplexNumber(int, int);
	void Print();
	
};

ComplexNumber::ComplexNumber()
{
	real = imaginary = 0;
}
ComplexNumber::ComplexNumber(int r, int i)
{
	real = r;
	imaginary = i;
}

//operator<< is a global function. This is not a member function of class
//overloaded stream insertion operator
ostream& operator<<(ostream& out, const ComplexNumber& obj)
{
	out << obj.real;		//Can we read/write private data in this function?
	if (obj.imaginary >= 0)
		out << "+";
	out << obj.imaginary << "i";
	return out;	// to enable cascading
}

//operator>> is a global function. This is not a member function of class
//overloaded stream extraction operator
istream& operator>>(istream& in, ComplexNumber& obj)
{
	in >> obj.real;			//Can we read/write private data in this function?
	in >> obj.imaginary;
	return in;	// to enable cascading
}

void main()
{
	ComplexNumber c1, c2, c3;
	cout << "Enter c1, c2 and c3 (real and imaginary parts) one by one:\n";
	cin >> c1 >> c2 >> c3;
	cout << "c1 = " << c1 << "\nc2 = " << c2 << "\nc3 = " << c3 << endl;


}