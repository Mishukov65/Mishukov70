#include "BinaryTree.h"
#include <iostream>

using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree(){
	root = NULL;
}

template <typename T>
BinaryTree<T>::~BinaryTree(){
	clear();
}

template <typename T>
void BinaryTree<T>::clear(node<T> *leaf){
	if(leaf != NULL){
		clear(leaf->left);
		clear(leaf->right);
		delete leaf;
	}
}

template <typename T>
void BinaryTree<T>::insert(T key, node<T> *leaf){

	if(key < leaf->value){
		if(leaf->left != NULL){
			insert(key, leaf->left);
		}else{
			leaf->left = new node<T>;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}else if(key >= leaf->value){
		if(leaf->right != NULL){
			insert(key, leaf->right);
		}else{
			leaf->right = new node<T>;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
		}
	}

}

template <typename T>
bool BinaryTree<T>::isEmpty(){
	if(root != NULL){
		return false;
	}else{
		return true;
	}
}

template <typename T>
void BinaryTree<T>::insert(T key){
	if(root != NULL){
		insert(key, root);
	}else{
		root = new node<T>;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

template <typename T>
void BinaryTree<T>::_delete(T key){
    if(root == NULL){
        return;
    }else{
        _delete(key, root);
    }
}

template <typename T>
void BinaryTree<T>::_delete(T key, node<T> *leaf){
    if(leaf == NULL){
        return;
    }else{
        //cout << "!";
        if(leaf->value == key){
            leaf->left = NULL;
            leaf->right = NULL;
            leaf->value = NULL;
            leaf = NULL;
            return;
		}
        _delete(key, leaf->left);
		_delete(key, leaf->right);
		return;
    }
}

template <typename T>
bool BinaryTree<T>::isContain(T key, node<T> *leaf){
	if(leaf != NULL){
		if(key == leaf->value){
			return true;
		}
		if(key < leaf->value){
			return isContain(key, leaf->left);
		}else{
			return isContain(key, leaf->right);
		}
	}else{
		return false;
	}
}

template <typename T>
bool BinaryTree<T>::isContain(T key){
	return isContain(key, root);
}

template <typename T>
void BinaryTree<T>::clear(){
	clear(root);
}

template <typename T>
void BinaryTree<T>::inorder_print(){
	inorder_print(root);
	cout << "\n";
}

template <typename T>
void BinaryTree<T>::inorder_print(node<T> *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

template <typename T>
void BinaryTree<T>::postorder_print(){
	postorder_print(root);
	cout << "\n";
}

template <typename T>
void BinaryTree<T>::postorder_print(node<T> *leaf){
	if(leaf != NULL){
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

template <typename T>
void BinaryTree<T>::preorder_print(){
	preorder_print(root);
	cout << "\n";
}

template <typename T>
void BinaryTree<T>::preorder_print(node<T> *leaf){
	if(leaf != NULL){
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}
