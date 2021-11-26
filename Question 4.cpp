#include <iostream>
using namespace std;
int main()
{
	float marks = 0;

	cout<<"Enter Marks = ";
	cin>>marks;

	if (marks <= 100 && marks >= 85)
		cout<<"Grade is A"<<endl;
	if (marks < 85 && marks >=75)
		cout<<"Grade is B"<<endl;
	if (marks < 75 && marks >= 65)
		cout<<"Grade is C"<<endl;
	if (marks < 65 && marks > 50)
		cout<<"Grade is D"<<endl;
	if (marks <= 50)
		cout<<"Grade is F"<<endl;

	return 0;
}