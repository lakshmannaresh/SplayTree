#ifndef _NODE_H
#define _NODE_H

class Node
{
private:
	int value;
	Node* left;
	Node* right;
	Node* parent;

public:
	Node(int newValue)
		: value(newValue)
		, left(NULL)
		, right(NULL)
		, parent(NULL)
	{
	}

	void setLeft(Node* newNode)
	{
		left = newNode;
	}

	void setRight(Node* newNode)
	{
		right = newNode;
	}

	void setParent(Node* newNode)
	{
		parent = newNode;
	}

	Node* getLeft()
	{
		return left;
	}

	Node* getRight()
	{
		return right;
	}

	Node* getParent()
	{
		return parent;
	}

	int getValue()
	{
		return value;
	}

public:
	void deleteMe()
	{
		left = NULL;
		right = NULL;
		this->~Node();
	}

	void deleteAllNodes()
	{
		this->~Node();
	}

private:
	~Node()
	{
		if (left != NULL)
		{
			deleteNode(&left);
		}

		if (right != NULL)
		{
			deleteNode(&right);
		}
	}

	void deleteNode(Node** delNode)
	{
		delete *delNode;
		delNode = NULL;
	}
};

#endif