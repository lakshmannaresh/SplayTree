#include "SplayTree.h"
#include <iostream>

void SplayTree::splayOperation(Node* curNode)
{
	if (curNode == root)
	{
		return;
	}

	if (curNode->getParent() == root)
	{
		if (curNode->getParent()->getLeft() == curNode)
		{
			rotatePrntRight(curNode);
		}
		else if (curNode->getParent()->getRight() == curNode)
		{
			rotatePrntLeft(curNode);
		}
		else
		{
			std::cout << " Dangling node \n ";
			exit(0);
		}
		return;
	}
	else
	{
		if (curNode->getParent()->getLeft() == curNode)
		{
			if (curNode->getParent()->getParent()->getLeft() == curNode->getParent())
			{
				rotatePrntRight(curNode->getParent());
				rotatePrntRight(curNode);
			}
			else if (curNode->getParent()->getParent()->getRight() == curNode->getParent())
			{
				rotatePrntLeft(curNode);
				rotatePrntRight(curNode);
			}
			else
			{
				std::cout << " Dangling node \n ";
				exit(0);
			}
		}
		else if (curNode->getParent()->getRight() == curNode)
		{
			if (curNode->getParent()->getParent()->getRight() == curNode->getParent())
			{
				rotatePrntLeft(curNode->getParent());
				rotatePrntLeft(curNode);
			}
			else if (curNode->getParent()->getParent()->getRight() == curNode->getParent())
			{
				rotatePrntRight(curNode);
				rotatePrntLeft(curNode);
			}
			else
			{
				std::cout << " Dangling node \n ";
				exit(0);
			}
		}
		else
		{
			std::cout << " Dangling node \n ";
			exit(0);
		}
	}
	splayOperation(curNode);
}

void SplayTree::rotatePrntRight(Node* curNode)
{
	if (curNode == NULL || curNode->getParent() == NULL)
		return;

	if (curNode->getParent() == root)
	{
		if (curNode->getRight())
			curNode->getRight()->setParent(root);
		root->setLeft(curNode->getRight());
		curNode->setRight(root);
		root->setParent(curNode);
		root = curNode;
	}
	else if (curNode->getParent()->getParent() != NULL)
	{
		Node *grandParent = curNode->getParent()->getParent();

		curNode->getParent()->setLeft(curNode->getRight());
		if (curNode->getRight())
			curNode->getRight()->setParent(curNode->getParent());
		curNode->getParent()->setParent(curNode);

		if (curNode->getParent() == grandParent->getLeft())
		{
			grandParent->setLeft(curNode);

		}
		else if (curNode->getParent() == grandParent->getRight())
		{
			grandParent->setRight(curNode);
		}

		curNode->setRight(curNode->getParent());
		curNode->setParent(grandParent);
	}
}

void SplayTree::rotatePrntLeft(Node* curNode)
{
	if (curNode == NULL || curNode->getParent() == NULL)
		return;

	if (curNode->getParent() == root)
	{
		if (curNode->getLeft())
			curNode->getLeft()->setParent(root);

		root->setRight(curNode->getLeft());
		curNode->setLeft(root);
		root->setParent(curNode);
		root = curNode;
	}
	else if (curNode->getParent()->getParent() != NULL)
	{
		Node *grandParent = curNode->getParent()->getParent();

		curNode->getParent()->setRight(curNode->getLeft());
		if (curNode->getLeft())
			curNode->getLeft()->setParent(curNode->getParent());
		curNode->getParent()->setParent(curNode);

		if (curNode->getParent() == grandParent->getLeft())
		{
			grandParent->setLeft(curNode);

		}
		else if (curNode->getParent() == grandParent->getRight())
		{
			grandParent->setRight(curNode);
		}

		curNode->setLeft(curNode->getParent());
		curNode->setParent(grandParent);
	}
}

void SplayTree::bfsPrint(Node* curNode)
{
	if (curNode->getLeft() != NULL)
		bfsQueue->push(curNode->getLeft());
	if (curNode->getRight() != NULL)
		bfsQueue->push(curNode->getRight());

	std::cout << curNode->getValue() << ", ";
	bfsQueue->pop();
	if (!bfsQueue->empty())
		return bfsPrint(bfsQueue->front());
	else
		return;
}

bool SplayTree::search(Node* curNode, Node* &prntNode, int value)
{
	if (curNode == NULL)
	{
		return false;
	}

	if (curNode->getValue() == value)
	{
		splayOperation(curNode);
		return true;
	}
	else if (curNode->getValue() > value)
	{
		prntNode = curNode;
		return 	search(curNode->getLeft(), prntNode, value);
	}
	else
	{
		prntNode = curNode;
		return 	search(curNode->getRight(), prntNode, value);
	}
}

void SplayTree::insert(int value)
{
	Node* prntNode = NULL;
	if (!search(root, prntNode, value))
	{
		Node* newNode = new Node(value);
		if (prntNode->getValue() > value)
		{
			prntNode->setLeft(newNode);
			prntNode->getLeft()->setParent(prntNode);
		}
		else
		{
			prntNode->setRight(newNode);
			prntNode->getRight()->setParent(prntNode);
		}
		splayOperation(newNode);
	}
}

Node* SplayTree::getRoot()
{
	return root;
}

void SplayTree::printTree()
{
	bfsQueue = new std::queue<Node*>();
	bfsQueue->push(root);
	bfsPrint(bfsQueue->front());
	std::cout << std::endl;

	delete bfsQueue;
}

void SplayTree::printPreOrder(Node* curNode)
{
	if (curNode == NULL)
		return;

	std::cout << curNode->getValue() << ",";
	printPreOrder(curNode->getLeft());
	printPreOrder(curNode->getRight());

}

SplayTree::SplayTree(int value)
{
	root = new Node(value);
}

SplayTree::~SplayTree()
{
	root->deleteAllNodes();
}