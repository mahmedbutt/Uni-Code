#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
	int fi_co = 0;
	int tw_co = 0;
	int on_co  = 0;
	int change = 0;
	int rem = 0;

	cout<<"Enter amount of 5 Rupees coins = ";
	cin>>fi_co;
	cout<<"Enter amount of 2 Rupees coins = ";
	cin>>tw_co;
	cout<<"Enter amount of 1 Rupees coins = ";
	cin>>on_co;

	cout<<"Enter Amount for Change: ";
	cin>>change;

	if (change / 5 <= fi_co)
		fi_co = change / 5;
	rem = change - fi_co * 5;

	if (rem / 2 <= tw_co)
		tw_co = rem / 2;
	rem = rem - tw_co * 2;

	if (rem< on_co)
		on_co = rem;
	rem = rem - on_co;

	if (change - rem == change)
	{
		cout<<"The amount "<< change <<" Rupees has the following change: \n";

		cout<<"Number of 5 Rupees conis = "<<fi_co<<endl;

		cout<<"Number of 2 Rupees conis = "<<tw_co<<endl;

		cout<<"Number of 1 Rupees conis = "<<on_co<<endl;

	}
	else 
		cout<<"No such Combination Exists."<<endl;

	

	
	_getch();
	return 0;
}