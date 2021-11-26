#include <iostream>
using namespace std;
int main()
{
	float num1 = 0;
	float num2 = 0;
	char o = '\0';
	float result = 0;

	cout<<"Enter Input 1 = ";
	cin>>num1;

	cout<<"Enter Input 2 = ";
	cin>>num2;

	cout<<"Enter Operator = ";
	cin>>o;

	if(o == '+')
	{
		result = num1 + num2;
	}
	
	if(o == '-')
	{
		result = num1 - num2;
	}
	
	if(o == '*')
	{
		result = num1 * num2;
	}

	if(o =='/')
	{
		result = num1 / num2;
	}
	
	cout<<"The Result is = ";
	cout<<result<<endl;

	return 0;
}