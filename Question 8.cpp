#include <iostream>
#include <conio.h>
using namespace std;

void findandreplace(int &l, int &l1, int &l2, int &l3, char a[], char newa[], char find[], char replace[], bool flag, int increase);

int main()
{
	const int size = 100;
	char arr[size] = { '\0' };
	char newarr[size] = { '\0' };
	char find[size] = { '\0' };
	char replace[size] = { '\0' };
	bool flag = true;
	int increase = 1;

	cout << "Sentence: ";
	cin.getline(arr, size, '\n');

	int len = strlen(arr);

	cout << "Find Sub-String: ";
	cin.getline(find, size, '\n');
	
	int len1 = strlen(find);

	cout << "Replace Sub-String: ";
	cin.getline(replace, size, '\n');

	int len2 = strlen(replace);

	int len3 = strlen(newarr);

	findandreplace(len, len1, len2, len3, arr, newarr, find, replace, flag, increase);

	for (int i = 0; i < len3; i++)
	{
		cout << newarr[i];
	}
	cout << endl;

	_getch();
	return 0;
}

void findandreplace(int &l, int &l1, int &l2,int &l3, char a[], char newa[], char find[], char replace[], bool flag, int increase)
{
	int i = 0;
	increase = 1;

	for (int i = 0; i < l1; i++)
	{
		for (int j = 0; j < l2; j++)
		{
			if (find[j] == a[i + j])
			{
				flag = true;
			}
			else
			{
				j = l2;
				flag = false;
			}
		}
		if (flag == true)
		{
			if (l1 > l2)
			{
				l3 = l - ((l1 * increase) - (increase * l2));
				increase++;
			}
			else
			{
				l3 = l + ((increase * l2) - (l1 * increase));
				increase++;
			}
		}

		for (int k = 0; k < i; k++)
		{
			newa[k] = a[k];
		}
		for (int l = i + l1; l < l3; l++)
		{
			newa[l] = a[l - l1];
		}

		int x = 0;
		int y = 0;
		for (int i = 0; x < (i + l2); x++)
		{
			newa[x] = replace[y];
			y++;
		}
	}
	i = i + l2;
}