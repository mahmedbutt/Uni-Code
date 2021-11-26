#include <iostream>
using namespace std;
int main()
{
	int num1 = 0;
	int num2 = 0;

	cout<<"Enter bigNumber = ";
	cin>>num1;

	cout<<"Enter littleNumber = ";
	cin>>num2;

	if (num1 < num2)
		cout<<"The littleNumber is bigger than bigNumber."<<endl;
	else if (num1 > num2)
		cout<<"The bigNumber is bigger."<<endl;
	else if (num1 == num2)
		cout<<"They are Equal."<<endl;

	if (num1%num2 == 0)
	{
		cout<<"They are evenly divisible."<<endl;
		{
			if (num1 == num2)
				cout<<"They are Same."<<endl;
			else
				cout<<"Not Same."<<endl;
		}
	}
	else
		cout<<"They are not evenly divisible."<<endl;

	return 0;
}