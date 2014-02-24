#pragma once
#include "stackFor3Tasks.h"

int operationPriority(char c);

void infixToPostfix(Stack *stack, char infixLine[size], char postfixLine[size]);