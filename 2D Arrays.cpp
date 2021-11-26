#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int a[2][3] = {2,4,5,9,0,9};

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin>>a[i][j];
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}

	_getch();
	return 0;
}