#pragma once

struct BinaryTreeNode;

typedef BinaryTreeNode BinaryTree;
// Создает пустое дерево
BinaryTreeNode *createTree();
// Добавляет значение целого типа в множество
BinaryTreeNode *addValue(BinaryTreeNode *root, int value);
// Удаление значения
BinaryTreeNode *removeValue(BinaryTreeNode *root, int value);
// Проверяет на принадлежность, выводит результат на экран
bool exist(BinaryTreeNode *root, int value); 
// Печатат в возрастаеющем порядке
void fprintIncrease(BinaryTreeNode *root);
// Печатает в убывающем порядке
void fprintDecrease(BinaryTreeNode *root);
// Удаляет дерево
void deleteTree(BinaryTreeNode *root);