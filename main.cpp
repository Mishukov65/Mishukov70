#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

using namespace std;

int main(){

	//BinaryTree tree;
	BinaryTree<char> *tree = new BinaryTree<char>();

	cout << tree->isEmpty() << endl;

	tree->insert('A');
	tree->insert('B');
	tree->insert('C');
	tree->insert('D');
	tree->insert('E');
	tree->insert('F');
	tree->insert('G');

	cout << tree->isContain('H') << endl;
	cout << tree->isEmpty() << endl;

	tree->inorder_print();

	tree->_delete('D');

	tree->inorder_print();

	//Всё тоже самое работает и с int и с bool и т.д.

	delete tree;

	BinaryTree<int> *treeInt = new BinaryTree<int>();

	cout << treeInt->isEmpty() << endl;

	treeInt->insert(1);
	treeInt->insert(2);
	treeInt->insert(3);
	treeInt->insert(4);
	treeInt->insert(5);
	treeInt->insert(6);
	treeInt->insert(7);

	cout << treeInt->isContain(2) << endl;
	cout << treeInt->isEmpty() << endl;

	treeInt->inorder_print();

	treeInt->_delete(5);

	treeInt->inorder_print();

	delete treeInt;

}
