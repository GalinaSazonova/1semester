#pragma once

int const size = 50;

struct StackElement;
struct Stack;
Stack *create();
typedef StackElement *Position;
// Возвращает тру или фолс, в зависимости от того, пуст стек или нет
bool notEmpty(Stack *stack);
// Добавляет элемент в стэк(в голову)
void push(Stack *stack, char element);
// Удаляет верхний элемент
void pop(Stack *stack);
// Возвращает значение головы стэка
char top(Stack *stack);
// Удаляет стэк
void deleteStack(Stack *stack);