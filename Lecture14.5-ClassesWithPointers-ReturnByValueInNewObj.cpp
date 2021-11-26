#include<iostream>
using namespace std;

class A
{
private:
	int* a;
public:
	A(int i = 0)
	{
		cout << "A() called for:\t"<<i<<endl;
		a = new int(i);		
	}
	A(const A& rhs)
	{
		cout << "A(A) called to create copy of:\t" << *rhs.a << endl;
		a = new int(*rhs.a);		
	}
	~A()
	{
		cout << "~A() called for:\t" << *a << endl;
		delete a;
	}
	A Add(A& rhs)
	{
		cout<<"--------------- ADDITION START --------------------\n";
		A result(*a + *rhs.a);		
		cout<<"--------------- RETURNING FROM ADDITION --------------------\n";
		return result;
	}
	A& operator=(const A& rhs)
	{
		cout << "Operator= called for LHS = " << *a <<" and RHS = "<< *rhs.a << endl;
		if (&rhs != this)
		{
			*a = *rhs.a;
		}
		return *this;
	}
};



void main()
{
	A a1(10);
	A a2(20);

	A a3 = a1.Add(a2);
	cout<<"--------------- LINE AFTER RETURN --------------------\n";

	//A a3;
	//a3 = a1.Add(a2);
	//cout<<"--------------- LINE AFTER RETURN --------------------\n";
}
