#include <iostream>
using namespace std;
int main()
{
	float side1 = 0;
	float side2 = 0;
	float side3 = 0;

	cout<<"Enter Base = ";
	cin>>side1;

	cout<<"Enter Perpendicular = ";
	cin>>side2;

	cout<<"Enter Hypotenuse = ";
	cin>>side3;

	if (side3 * side3 == side1 * side1 + side2 * side2)

		cout<<"It is a Right Angle Triangle."<<endl;
	else
		cout<<"It is not a Right Angle Triangle."<<endl;
	return 0;
}

