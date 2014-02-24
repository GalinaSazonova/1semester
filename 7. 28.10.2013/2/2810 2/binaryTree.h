#pragma once

struct BinaryTreeNode;

typedef BinaryTreeNode BinaryTree;
// ������� ������ ������
BinaryTreeNode *createTree();
// ��������� �������� ������ ���� � ���������
BinaryTreeNode *addValue(BinaryTreeNode *root, int value);
// �������� ��������
BinaryTreeNode *removeValue(BinaryTreeNode *root, int value);
// ��������� �� ��������������, ������� ��������� �� �����
bool exist(BinaryTreeNode *root, int value); 
// ������� � ������������� �������
void fprintIncrease(BinaryTreeNode *root);
// �������� � ��������� �������
void fprintDecrease(BinaryTreeNode *root);
// ������� ������
void deleteTree(BinaryTreeNode *root);