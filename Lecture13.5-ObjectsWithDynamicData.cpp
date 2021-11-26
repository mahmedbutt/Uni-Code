#include<iostream>
using namespace std;

class Rectangle{
private:
	int* lenght;
	int* width;
public:
	Rectangle();
	Rectangle(int, int);
	~Rectangle();
	void SetValues(int, int);
	void Print();
};
Rectangle::Rectangle()
{
	cout << "Default Constructor Called.\n\n";
	lenght = new int;	//Integer is on heap
	width = new int;
	*lenght = *width = 0;	
}
Rectangle::Rectangle(int l, int w)
{
	cout << "Overloaded Constructor Called with l = "<<l<<" and w = "<<w<<".\n\n";
	lenght = new int(l);	//Integer is on heap. Initializing integer to l
	width = new int(w);		//Initializing integer to w
}
Rectangle::~Rectangle()
{
	//What if we do not deallocate memory in destructor?
	cout << "Destructor Called for rectangle "<<*lenght<<"X"<<*width<<"\n";
	delete lenght;	//Deallocated memory from heap
	delete width;	
}
void Rectangle::Print()
{
	//What will following line print now?
	//cout << "Rectangle is " << lenght << "X" << width<<endl<<endl;
	cout << "Rectangle is " << *lenght << "X" << *width << endl << endl;
}
void Rectangle::SetValues(int l, int w)
{
	*lenght = l;
	*width = w;
}
void main()
{
	//Create an object on stack
	Rectangle r1(5,10);
	r1.Print();
	
	Rectangle r2;
	r2.SetValues(3,4);
	r2.Print();
}