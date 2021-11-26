#include <iostream>
using namespace std;
#include <conio.h>
int main ()
{
	int num[4];
	int k =0;
	for (int i =0;i<5;i++)
	{
		cout << "Enter number : ";
		cin >> num[i];
			cout<<endl;
	}
	

	int temp = 0;

	for (int z =0;z<=4;z++)
	{
	temp = num[z];
	for (int i=z+1; i<=4;i++)
	{
	if (num[i]==temp)
	{
	k=i;
	while (num[k-1]!=temp)
	{
	num[k]=num[k-1];
	k--;
	}
	num[k]=temp;
	
	}
	}
	}
	
	for (int i =0;i<5;i++)
	{
		cout << num[i];
			cout<<endl;
	}
	

	getch();
return 0;
}