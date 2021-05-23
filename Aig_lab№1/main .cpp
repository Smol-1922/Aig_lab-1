#include"BRTree.h"
#include"functionBRTree.h"
#include"functionList.h"
#include"functionStack.h"
#include<iostream>
int main() {
	RBTree<int, int>* tree = new RBTree<int, int>;
	Node<int, int>* node;
	tree->insert(11, 1);
	tree->insert(2, 3);
	tree->insert(1, 5);
	tree->insert(7, 6);
	tree->insert(5, 4);
	tree->insert(4, 2);
	tree->insert(8, 7);
	tree->insert(14, 9);
	tree->insert(15, 10);
	tree->print();
	std::cout << std::endl;
	std::cout << std::endl;
	tree->remove(2);
	tree->print();
	std::cout << std::endl;
	std::cout << std::endl;
	node = tree->find(4);
	std::cout << node->key << std::endl;
	return 13;
}