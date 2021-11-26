#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	const int size = 25;
	char arr[size] = { '\0' };

	cout << "Sentence: ";
	cin.getline(arr, size);

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == '.' && arr[i + 1] == ' ')
		{
			arr[i + 1] = '\0';
		}
	}

	cout << "New Sentence: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i];
	}
	cout << endl;

	_getch();
	return 0;
}