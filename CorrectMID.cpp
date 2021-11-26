#include <iostream>
using namespace std;

int main ()
{
	int x = 0;
	int y = 0;
	int k = 0;
	int remain1 = 0;
	int remain2 = 0;
	int i = 0;
	cout<<"Enter x = ";
	cin>>x;
	cout<<"Enter y = ";
	cin>>y;
	cout<<"Enter k = ";
	cin>>k;

	for(i = 0; i <= k; i++)
	{ 
		remain1 = x%10;
		x/=10;
		remain2 = y%10;
		y/=10;

		if (x == 0 || y== 0)
			break;
	}

	if (remain1 == remain2 && i == k)
	{
		cout<<"kth digit is same"<<endl;
	}
	else
		cout<<"not"<<endl;

	return 0;
}