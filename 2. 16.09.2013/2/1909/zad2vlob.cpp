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
	int otvet = 1;
	for (int i = 0; i < degree; ++i)
	{
		otvet = otvet * base;
		
	}
	cout << "Reshenye = ";
	cout << otvet << endl;
	return 0;
}