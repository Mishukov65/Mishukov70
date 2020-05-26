#ifndef _BINARETREE_H_
#define _BINARETREE_H_

template <typename T>
struct node{
	T value;
	node *left;
	node *right;
};

template <typename T>
class BinaryTree{
public:
	BinaryTree();
	~BinaryTree();

	void insert(T key);
	void _delete(T key);
	bool isContain(T key);
	bool isEmpty();
	void clear();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void clear(node<T> *leaf);
	void _delete(T key, node<T> *leaf);
	void insert(T key, node<T> *leaf);
	bool isContain(T key, node<T> *leaf);
	void inorder_print(node<T> *leaf);
	void postorder_print(node<T> *leaf);
	void preorder_print(node<T> *leaf);

	node<T> *root;
};

#endif
