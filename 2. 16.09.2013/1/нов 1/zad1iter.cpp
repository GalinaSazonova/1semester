#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int count = 0;
	cout << "Input numder" << endl;
	cin >> count;
	int const n = 100;
	int fib[n] = {0};
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= count; ++i)
	{
		fib[i] = fib[i - 1] + fib[i - 2];		
	}
	cout<< fib[count] <<endl;
	return 0;
}