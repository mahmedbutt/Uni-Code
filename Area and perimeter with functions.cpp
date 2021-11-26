#include <iostream>
#include <conio.h>
using namespace std;

float AreaOfRectangle(float l, float w);
float PerimeterOfRectangle(float l, float  w);

int main()
{
	float length = 0, width = 0;
	cout<<"Enter Length = ";
	cin>>length;
	cout<<"Enter Width = ";
	cin>>width;

	float area = AreaOfRectangle (length, width);
	cout<<"Area of Rectangle is = "<<area<<endl;

	float perimeter = PerimeterOfRectangle(length, width);
	cout<<"Perimeter of Rectangle is = "<<perimeter<<endl;
}

float AreaOfRectangle(float l, float w)
{
	return l*w;
}

float PerimeterOfRectangle(float l, float  w)
{
	return (2*(l+w));
}