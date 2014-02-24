#include "balance.h"

bool bracketBalance(Stack *stack, char *line)
{
	for (int i = 0; line[i] != '\0'; i++)
	{
		char symbol = line[i];
		if (symbol != '('  && symbol != '{' && symbol != '[' && symbol != ']'  && symbol != '}' &&  symbol != ')' )
		{
			continue;
		}
		if (symbol == '('  || symbol == '{' ||  symbol == '[' )
		{
			push(stack, symbol);
			continue;
		}
		if (!notEmpty(stack))
		{
			return false;
		}
		if ((symbol == ')') && (top(stack) == '(') || (symbol == ']') && (top(stack) == '[') || (symbol == '}') && (top(stack) == '{'))
		{
			pop(stack);
			continue;
		}
		else
		{
			return false;
		}
	}
	return !notEmpty(stack);
}