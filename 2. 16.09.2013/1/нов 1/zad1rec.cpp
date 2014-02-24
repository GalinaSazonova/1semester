#include <stdio.h>
#include <iostream>

using namespace std;

int fib(int n)
{ 
	if (n <= 1)	{
		return 1;
	}	else 	{
		return  fib(n - 1) + fib(n - 2);
	}
}

int main()
{
	int count = 0;
	cout << "Input numder" << endl;
	cin >> count;
	cout << fib(count) << endl;
	return 0;
}