#include <iostream>
#include <conio.h>
using namespace std;

void itreplace(int array[], int size) {					//iterative solution
	int x = 1;
	for (int i = 0; i < size; i++)
		x *= array[i];
	for (int i = 0; i < size; i++)
		array[i] = x / array[i];
}

int  rereplace(int array[], int size, int currproduct)					//recursive solution
{
	if (size < 0)
		return currproduct;

	int product = rereplace(array, size-1, currproduct*array[size]);
	array[size] = product / array[size];

	return product;
}

int main() {
	int array[] = {5,4,3,2,1};
	int size = sizeof(array)/sizeof(array[0]);

	itreplace(array, size);

	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;

	rereplace(array, size-1, 1);

	for (int i = 0; i < size; i++)
		cout << array[i]<<" ";
	cout << endl;

	_getch();
	return 0;
}