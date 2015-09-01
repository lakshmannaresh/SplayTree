#include "SplayTree.h"
#include <iostream>

int main(int argc, char* argv[])
{
	SplayTree *stree = new SplayTree(10);
	stree->insert(20);
	stree->insert(30);
	stree->insert(40);
	stree->insert(50);
	stree->insert(60);

	Node* prevNode = NULL;
	stree->search(stree->getRoot(), prevNode, 30);

	std::cout << "Tree Nodes are : \n";
	stree->printTree();

	std::cout << "Pre Order print is : \n";
	stree->printPreOrder(stree->getRoot());

	std::cout << std::endl;
	std::cout << "End of main \n";
	delete stree;

	std::cin.ignore();
}