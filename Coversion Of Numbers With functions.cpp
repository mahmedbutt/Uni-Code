#include <iostream>
#include <conio.h>
using namespace std;

int bintodec (int num1);
int dectobin (int num1);
void dectohex ();
void hextobin ();

int main()
{
	int num = 0;
	int n = 0;
	int conv = 0;
	int rem = 0;
	int i = 0;

	cout<<"Enter 1 for Binary to Decimal."<<endl;
	cout<<"Enter 2 for Decimal to Binary."<<endl;
	cout<<"Enter 3 for Decimal to Hexadecimal."<<endl;
	cout<<"Enter 4 for Hexadecimal to Binary."<<endl;
	cout<<"Enter Number for Conversion Type = ";
	cin>>num;

	if (num == 1)
	{
		cout<<"Binary to Decimal."<<endl;
		cout<<"Enter Number = ";
		cin>>n;
		
		int decimal = bintodec(n);
			cout<<"The decimal number is "<<decimal<<endl;
	}

	if (num == 2)
	{
		cout<<"Decimal to Binary."<<endl;
		cout<<"Enter Number = ";
		cin>>n;

		int binary = dectobin(n);
		cout<<"The binary number is "<<binary<<endl;
	}

	if (num == 3)
	{
	cout<<"Decimal to Hexadecimal."<<endl;

	dectohex ();
	}

	if (num == 4)
	{
	cout<<"Hexadecimal to Binary."<<endl;

	hextobin ();
	}
}

int bintodec (int num1)
{
	int conv = 0;
	int rem = 0;
	int i = 1;
	int n = num1;
	while (n != 0)
	{
		rem = n % 10;
		n /= 10;
		conv = conv + (rem * i);
		i *= 2;
	}
	return conv;
}

int dectobin (int num1)
{
	int conv = 0;
	int rem = 0;
	int i = 1;
	int n = num1;
	while (n != 0)
	{
		rem = n % 2;
		n /= 2;
		conv = conv + (rem * i);
		i *= 10;
	}
	return conv;
}

void dectohex ()
{
	int num = 0;
	int tens = 1;
	int sum = 0;
	int copy = 0;
	int counter = 1;
	int tens2 = 1;
	int rem = 0;

	cout<<"Enter Number = ";
	cin>>num;
	copy = num;

	while (copy >= 16)
	{
		copy /= 16;
		counter++;
	}

	for(int i = 1; i < (counter*2); i++)
	{
		tens *=10;
	}
	tens2 = tens;
	copy = num;
	int a = 99;
	for(int k = 1; k <= counter;k++)
	{	
		
		a = copy %16;
		copy /= 16;

		if (a < 10)
		{
			a *= tens;
			tens /= 10;
			sum = sum + a;
			sum = sum + (6* tens);
			tens /= 10;
		}
		else if (a > 9)
		{
			tens /= 10;
			a *= tens;
			tens /= 10;
			
			sum = sum + a;
			tens /= 1;
		
		}
	}
	 copy = sum;
	 cout<<"The Hexadecimal value is = ";
	 while(copy > 0)
	 {
		rem = copy % 10;
		if (rem == 6)
		{
		copy /= 10;
			rem = copy %10;
			cout<<rem;
			copy /= 10;
		}

		else if (rem != 6)
		{
			
			rem = copy %100;
			copy /= 100;

			if (rem == 10) 
				cout<<"A"<<endl;
			else if (rem == 11) 
				cout<<"B"<<endl;
			else if (rem == 12) 
				cout<<"C"<<endl;
			else if (rem == 13) 
				cout<<"D"<<endl;
			else if (rem == 14) 
				cout<<"E"<<endl;
			else if (rem == 15) 
				cout<<"F"<<endl;
		}

	 }
}


void hextobin ()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	cout<<"Enter hexadecimal value = ";
	cin>>a>>b>>c>>d;

	a = dectobin(a);
	b = dectobin(b);
	c = dectobin(c);
	d = dectobin(d);

	cout<<a<<b<<c<<d<<endl;
}