#include<iostream>
using namespace std;

class Rectangle{
private:
	int* lenght;
	int* width;
public:
	Rectangle::Rectangle(int l = 0, int w = 0)
	{
		cout << "\n\n\nConstructor Called with parameters " << l << " and " << w << "\n\n\n";
		lenght = new int(l);
		width = new int (w);
	}
	Rectangle(const Rectangle&);
	~Rectangle();
	void Print();
	const Rectangle& operator=(const Rectangle&);	
	void SetValues(int, int);

	Rectangle GetDoubleSizedRect()
	{
		cout << "I am inside GetDoubleSizedRect()" << endl;
		Rectangle temp;
		*temp.lenght = *lenght * 2;
		*temp.width = *width * 2;
		cout << "I am exiting GetDoubleSizedRect()" << endl;
		return temp;
	}
};


// Comment this Copy Constructor and check behavior of Built-In Copy constructor
Rectangle::Rectangle(const Rectangle& rhs)
{
	cout<<"Copy Constructor Called to create a copy of Rectangle "<<*rhs.lenght<<" X "<<*rhs.width<<endl;
	lenght = new int( *rhs.lenght);
	width = new int ( *rhs.width);
}
Rectangle::~Rectangle()
{
	cout << "Destructor Called for rectangle "<<*lenght<<" X "<<*width<<"\n\n";
	if(lenght != 0) delete lenght;
	if(width != 0) delete width;
}
const Rectangle& Rectangle::operator=(const Rectangle& rhs)
{
	cout<<"Overloaded Assignment Operator Called for RHS "<<*rhs.lenght<<" X "<<*rhs.width<<endl;

	if( &rhs != this )	//Avoid self-assignment
	{
		//De-allocate previous memory and allocate new memory IF REQUIRED
		*lenght = *rhs.lenght;
		*width = *rhs.width;
	}
	return *this;
}

void Rectangle::Print()
{
	cout << *lenght << " X " << *width<<endl<<endl;
}
void Rectangle::SetValues(int l , int w)
{
	*lenght = l;
	*width = w;
}



void main()
{
	{
		Rectangle r1(2, 3);
		Rectangle r2;

		r2 = r1.GetDoubleSizedRect();
		cout << "Line after GetDoubleSizedRect()" << endl;
		cout << "r2:\t";
		r2.Print();		
		cout << "\n\n\n objects are going out of scope...\n\n\n";
		//Comment Copy Constructor and check what built-in Copy Constructor does?
	}
	cout << "Press any key to continue...";
	getchar();
}