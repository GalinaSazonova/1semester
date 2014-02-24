#include "BinaryTree.h"
#include <iostream>
#include <stdio.h>

using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *leftChild;
	BinaryTreeNode *rightChild;
};


BinaryTreeNode *createNode(int newValue)
{
	BinaryTreeNode *root = new BinaryTreeNode;
	root->value = newValue;
	root->leftChild = nullptr;
	root->rightChild = nullptr;
	return root;
}

BinaryTreeNode *createTree()
{
	return nullptr;
}

BinaryTreeNode *parent(BinaryTreeNode *root, BinaryTreeNode *child)
{
	BinaryTreeNode *temp = root;
	while (temp->leftChild != child  && temp->rightChild != child)
	{
		if (child->value < temp->value)
		{
			temp = temp->leftChild;
		}
		if (child->value > temp->value)
		{
			temp = temp->rightChild;
		}
	}
	return temp;
}

BinaryTreeNode *bigRight(BinaryTreeNode *root)
{
	BinaryTreeNode *temp = root;
	while (root->rightChild != nullptr)
	{
		root = root->rightChild;
	}
	return root;
}

BinaryTreeNode *addValue(BinaryTreeNode *root, int value)
{
	if (root == nullptr)
	{
		root = createNode(value);
	}
	if (value < root->value)
	{
		if (root->leftChild == nullptr)
		{
			root->leftChild = createNode(value);
		}
		else
		{
			addValue(root->leftChild, value);
		}
	}
	if (value > root->value)
	{
		if (root->rightChild == nullptr)
		{
			root->rightChild = createNode(value);
		}
		else
		{
			addValue(root->rightChild, value);
		}
	}
	return root;
}

BinaryTreeNode *removeLeaf(BinaryTreeNode *mainRoot, BinaryTreeNode *leaf)
{
	if (leaf->leftChild != nullptr && leaf->rightChild == nullptr)
	{
		if (mainRoot == leaf)
		{
			mainRoot = leaf->leftChild;
		}
		else
		{
			BinaryTreeNode *parentOfRoot = parent(mainRoot, leaf);
			if (leaf->leftChild->value > parentOfRoot->value)
			{
				parentOfRoot->rightChild = leaf->leftChild;
			}
			else
			{
				parentOfRoot->leftChild = leaf->leftChild;
			}
		}
	}
	if (leaf->leftChild == nullptr && leaf->rightChild != nullptr)
	{
		if (mainRoot == leaf)
		{
			mainRoot = leaf->rightChild;
		}
		else
		{
			BinaryTreeNode *parentOfRoot = parent(mainRoot, leaf);
			if (leaf->rightChild->value > parentOfRoot->value)
			{
				parentOfRoot->rightChild = leaf->rightChild;
			}
			else
			{
				parentOfRoot->leftChild = leaf->rightChild;
			}
		}
	}
	if (leaf->leftChild == nullptr && leaf->rightChild == nullptr)
	{
		if (mainRoot == leaf)
		{
			mainRoot = nullptr;
		}
		else
		{
			BinaryTreeNode *parentOfRoot = parent(mainRoot, leaf);
			parentOfRoot->leftChild = nullptr;
			parentOfRoot->rightChild = nullptr;
		}
	}
	delete leaf;
	return mainRoot;
}

BinaryTreeNode *findValueNeed(BinaryTreeNode *root, int value)
{
	if (root->value == value)
	{
		return root;
	}
	if (value < root->value)
	{
		if (root->leftChild == nullptr)
		{
			return nullptr;
		}
		return findValueNeed(root->leftChild, value);
	}
	if (value > root->value)
	{
		if (root->rightChild == nullptr)
		{
			return nullptr;
		}
		return findValueNeed(root->rightChild, value);
	}
	return root;
}

BinaryTreeNode *removeValue(BinaryTreeNode *root, int value)
{
	BinaryTreeNode *nodeNeedToDelete = findValueNeed(root, value);
	if (nullptr == nodeNeedToDelete)
	{
		return root;
	}
	if (nodeNeedToDelete->leftChild == nullptr && nodeNeedToDelete->rightChild == nullptr)
	{
		root = removeLeaf(root, nodeNeedToDelete);
		return root;
	}
	if ((nodeNeedToDelete->leftChild != nullptr && nodeNeedToDelete->rightChild == nullptr) || (nodeNeedToDelete->leftChild == nullptr && nodeNeedToDelete->rightChild != nullptr))
	{
		root = removeLeaf(root, nodeNeedToDelete);
		return root;
	}
	if (nodeNeedToDelete->leftChild != nullptr && nodeNeedToDelete->rightChild != nullptr)
	{
		BinaryTreeNode *temp = bigRight(nodeNeedToDelete);
		int valTemp = temp->value;
		root = removeLeaf(root, temp);
		nodeNeedToDelete->value = valTemp;
		return root;
	}
	return root;
}



bool exist(BinaryTreeNode *root, int value)
{
	BinaryTreeNode *temp = root;
	while (root != nullptr)
	{
		if (root->value == value)
		{
			return true;
		}
		if (value < root->value)
		{
			if (root->leftChild == nullptr)
			{
				return false;
			}
			temp = temp->leftChild;
		}
		if (value > root->value)
		{
			if (root->leftChild == nullptr)
			{
				return false;
			}
			temp = temp->rightChild;
		}
	}
	return false;
}

void fprintIncrease(BinaryTreeNode *root)
{
	if (root != nullptr)
	{
		fprintIncrease(root->leftChild);
		cout << root->value << " ";
		fprintIncrease(root->rightChild);
	}
}

void fprintDecrease(BinaryTreeNode *root)
{
	if (root != nullptr)
	{
		fprintDecrease(root->rightChild);
		cout << root->value << " ";
		fprintDecrease(root->leftChild);
	}
}


void deleteTree(BinaryTreeNode *root)
{
	if (root == nullptr)
	{
		delete root;
		return;
	}
	if (root->leftChild != nullptr)
	{
		deleteTree(root->leftChild);
	}
	if (root->rightChild != nullptr)
	{
		deleteTree(root->rightChild);
	}
	delete root;
}

BinaryTreeNode *createArithmTree(BinaryTreeNode *root, string line, int &position)
{
	if (sizeof(line) > 0)
	{
		while (line[position] == '(' || line[position] == ' ')
		{
			position++;
		}
		if (line[position] == '*' || line[position] == '/' || line[position] == '+' || line[position] == '-')
		{
			root = createNode(line[position]);
			position++;
			root->leftChild = createArithmTree(root->leftChild, line, position);
			root->rightChild = createArithmTree(root->rightChild, line, position);
		}
		else if (line[position] >= '0' && line[position] <= '9')
		{
			root = createNode(line[position]);
			position++;
			return root;
		}
		if (line[position] == ')')
		{
			position++;
			return root;
		}
	}
	return root;
}

int countArithmTree(BinaryTreeNode *root, bool &test)
{
	if (root->value == '*')
	{
		return countArithmTree(root->leftChild, test) * countArithmTree(root->rightChild, test);
	}
	if (root->value == '/')
	{
		if (countArithmTree(root->rightChild, test) == 0)
		{
			printf("Error: devision by ZeRo!!\n");
			test = 1;
			return 1;
		}
		return countArithmTree(root->leftChild, test) / countArithmTree(root->rightChild, test);
	}
	if (root->value == '+')
	{
		return countArithmTree(root->leftChild, test) + countArithmTree(root->rightChild, test);
	}
	if (root->value == '-')
	{
		return countArithmTree(root->leftChild, test) - countArithmTree(root->rightChild, test);
	}
	return root->value - 48;
}

void printArithmTree(BinaryTreeNode *root)
{
	if (root->value == '*' || root->value == '/' || root->value == '+' || root->value == '-')
	{
		printf("( %c ", root->value);
		printArithmTree(root->leftChild);
		printArithmTree(root->rightChild);
		printf(") ");
	}
	else
	{
		printf("%c ", root->value);
	}
}
