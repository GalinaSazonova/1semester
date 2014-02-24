/* input 1+1
output 11+
input (1+1)*2
output 11+2* 
input 1+1*2
output 112*+
*/
#define _CRT_SECURE_NO_WARNINGS
#include "stackFor3Tasks.h"
#include "postfix.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	Stack *stack = create();
	char infixLine[size];
	cout << "Please, enter an expression" << endl;
	gets_s(infixLine, size);
	char postfixLine[255] = {0};
	infixToPostfix(stack, infixLine, postfixLine);
	for (int i = 0; postfixLine[i] != '\0'; i++)
	{
		cout << postfixLine[i];
		if (postfixLine[i] == ' ')
			break;
	}
	cout << endl;
	deleteStack(stack);
	return 0;
}

