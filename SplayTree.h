#ifndef _SplayTree_H
#define _SplayTree_H

#include <queue>
#include "Node.h"

class SplayTree
{
private:
	Node* root;
	std::queue<Node *> *bfsQueue;

private:
	void splayOperation(Node* curNode);

	void rotatePrntRight(Node* curNode);

	void rotatePrntLeft(Node* curNode);

	void bfsPrint(Node* curNode);
	
public:
	bool search(Node* curNode, Node* &prntNode, int value);
	
	void insert(int value);
	
	Node* getRoot();
	
	void printTree();
	
	void printPreOrder(Node* curNode);
	
	SplayTree(int value);
	
	~SplayTree();
};

#endif