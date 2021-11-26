#include <iostream>
using namespace std;
int main()
{
	int x = 0;
	cout<<"Enter number = ";
	cin>>x;

	if(x<0)
	{
		x = (-1*x);
		cout<<"Absolute Value will be = ";
		cout<<x<<endl;
	}
	return 0;
}