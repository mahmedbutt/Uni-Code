#include <iostream>
using namespace std;
int main()
{
	float weight = 0;
	float height = 0;
	float bmi = 0;
	char k ='k';
	char p = 'p';
	char i = 'i';
	char m = 'm';
	char w = 'w';

	cout<<"Enter Unit of Measure = ";
	cin>>w;

	if (w == k)
	{
		cout<<"Enter Weight = ";
		cin>>weight;
		cout<<"Enter height = ";
		cin>>height;
		bmi = ( weight / ( height * height ) );
		cout<<bmi;
	}
	else if (w == p)
	{
		cout<<"Enter Weight = ";
		cin>>weight;
		cout<<"Enter height = ";
		cin>>height;
		bmi = ( weight / ( height * height ) ) * 703;
		cout<<bmi<<endl;
	}

	if (bmi < 18.5)
		cout<<"Underweight."<<endl;
	if (bmi >=18.5 && bmi <= 24.9)
		cout<<"Normal"<<endl;
	if (bmi >=25 && bmi <= 29.9)
		cout<<"Overweight"<<endl;
	if (bmi >= 30)
		cout<<"Obese"<<endl;
	return 0;
}