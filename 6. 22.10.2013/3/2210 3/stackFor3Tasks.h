#pragma once

int const size = 50;

struct StackElement;
struct Stack;
Stack *create();
typedef StackElement *Position;
// ���������� ��� ��� ����, � ����������� �� ����, ���� ���� ��� ���
bool notEmpty(Stack *stack);
// ��������� ������� � ����(� ������)
void push(Stack *stack, char element);
// ������� ������� �������
void pop(Stack *stack);
// ���������� �������� ������ �����
char top(Stack *stack);
// ������� ����
void deleteStack(Stack *stack);