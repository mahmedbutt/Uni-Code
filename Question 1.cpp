#include <iostream>
using namespace std;
int main()
{
	int num = 0;

	cout<<"Enter number = ";
	cin>>num;
	
	if (num %2 == 0)
		cout<<"Number is Even"<<endl;
	else
		cout<<"Number is Odd"<<endl;
	return 0;
}