/* Says, that everything is ok, whith expressions:
([{}])
()
{}
Error: ((*/
#include "stackFor3Tasks.h"
#include "balance.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	Stack *stack = create();
	char line[255];
	cout << "Please, enter an expression" << endl;
	gets_s(line, 255);
	if (bracketBalance(stack, line))
	{
		cout << "Correct expression" << endl;
	}
	else
	{
		cout << "Error" << endl;
	}
	deleteStack(stack);
	return 0;
}