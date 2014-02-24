#include "postfix.h"

int operationPriority(char c)
{
	switch(c)
	{
	case '*':
		return 2;
	case '/':
		return 2; 
	case '+':
		return 1;
	case '-':
		return 1;
	}
	return 0;
}

void infixToPostfix(Stack *stack, char infixLine[], char postfixLine[])
{
	int i = 0;
	int lastInPostfixLine = 0;
	while (infixLine[i] != '\0')
	{
		if (infixLine[i] >= '0' && infixLine[i] <= '9')
		{
			postfixLine[lastInPostfixLine] = infixLine[i];
			lastInPostfixLine++;
		}
		else
		{
			switch (infixLine[i])
			{
			case '(':
				push(stack, infixLine[i]);
				break;
			case ')':
				{
					char temp = top(stack);
					pop(stack);
					while (temp != '(')
					{
						postfixLine[lastInPostfixLine] = temp;
						lastInPostfixLine++;
						temp = top(stack);
						pop(stack);
					}
				}
				break;
			default :
				{ 
					if (!empty(stack)) 
						push(stack, infixLine[i]);
					else
					{
						char w = top(stack);
						while (empty(stack) && (operationPriority(top(stack)) >= operationPriority(infixLine[i])))
						{
							w = top(stack);
							pop(stack);
							postfixLine[lastInPostfixLine] = w;
							lastInPostfixLine++;
						}
						push(stack, infixLine[i]);
					}
				}
				break;
			}
		}
		i++;
	}
	while (empty(stack))
	{
		char w = top(stack);
		pop(stack);
		postfixLine[lastInPostfixLine] = w;
		lastInPostfixLine++;
	}
}