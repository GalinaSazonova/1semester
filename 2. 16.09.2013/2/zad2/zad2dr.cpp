#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int degree = 0;
	cout << "Input degree" << endl;
	cin >> degree;
	int base = 0;
	cout << "Input base" << endl;
	cin >> base;
	int check = 1;
	while (degree != 1) 
	{
		if (degree % 2 == 1) 
		{
			check = check * base;
		}
		base *= base;
		degree = degree / 2;
	}
	int otvet = base * check;
	cout << "Reshenye = ";
	cout << otvet << endl;
	return 0;
}