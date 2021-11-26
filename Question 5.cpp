#include <iostream>
using namespace std;
int main()
{
	char r ='r';
	char p ='p';
	char s ='s';
	char a ='\0';
	char b ='\0';

	cout<<"1st Player Turn = ";
	cin>>a;
	cout<<"2nd Player Turn = ";
	cin>>b;

	if (a == r && b == r)
		cout<<"Draw"<<endl;
	if (a == r && b == p)
		cout<<"2nd player Wins."<<endl;
	if (a == r && b == s)
		cout<<"1st player Wins."<<endl;

	if (a == p && b == r)
		cout<<"1st Player Wins."<<endl;
	if (a == p && b == p)
		cout<<"Draw."<<endl;
	if (a == p && b == s)
		cout<<"2nd Player Wins."<<endl;

	if (a == s && b == r)
		cout<<"2nd Player Wins."<<endl;
	if (a == s && b == p)
		cout<<"1st Player Wins"<<endl;
	if (a == s && b == s)
		cout<<"Draw."<<endl;

	return 0;
}