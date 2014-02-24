#pragma once
#include <string>
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

// ������� ������ �������
BinaryTreeNode *createArithmTree(BinaryTreeNode *root, std::string line, int &position);
// ������ ����� ������
void printArithmTree(BinaryTreeNode *root);
// ������� ��������
int countArithmTree(BinaryTreeNode *root, bool &test);