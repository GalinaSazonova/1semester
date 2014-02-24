#include "StackCalculator.h"

using namespace std;

void calculator(Stack *stack, char *line)
{
	int mainResult = 0;
	for (int i = 0; line[i] != '\0'; i++)
	{
		char symbol = line[i];
		if (symbol != '-' && symbol != '*' && symbol != '/' && symbol != '+' && symbol != ' ')
		{
			push(stack, atoi(&symbol));
		}
		else switch (symbol)
		{
			case '+':
			{
				int result = 0;
				result += top(stack);
				pop(stack);
				result += top(stack);
				pop(stack);
				push(stack, result);
				break;
			}
			case '-':
			{
				int result = 0;
				result -= top(stack);
				pop(stack);
				result += top(stack);
				pop(stack);
				push(stack, result);
				break;
			}
			case '*':
			{
				int result = 0;
				result = 1;
				result *= top(stack);
				pop(stack);
				result *= top(stack);
				pop(stack);
				push(stack, result);
				break;
			}
			case '/':
			{
				int tempor = top(stack);
				pop(stack);
				if (tempor != 0)
				{
					int result = 0;
					result = top(stack) / tempor;
					pop(stack);
					push(stack, result);
					break;
				}
				else
				{
					printf("Error: fuuu!! there is a zero in division!!!\n");
					mainResult = -99999; 
					break;
				}
			}
			default:
			{
				continue;
			}
		}
	}
	mainResult = top(stack);
	pop(stack);
	if (mainResult != -99999)
	{
		cout << "Result: " << mainResult << endl;
	}
}