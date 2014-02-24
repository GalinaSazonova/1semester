/* 11+
result: 2
11+2* 
result: 4
пр вводе инфиксной строки не работает*/
#include "stackFor3Tasks.h"
#include "StackCalculator.h"
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	Stack *stack = create();
	char postfixLine[255];
	cout << "Please, enter postfix expression" << std::endl;
	gets_s(postfixLine, 255);
	calculator(stack, postfixLine);
	deleteStack(stack);
	return 0;
}