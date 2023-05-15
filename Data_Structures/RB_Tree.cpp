#include "RB_Tree.h"

template <typename T> void RB_Tree<T>::initWarden()
{
	warden = new Node<T>(0);
	warden->color = 0;
	warden->left = nullptr;
	warden->right = nullptr;
}

template <typename T> void RB_Tree<T>::insertFixUp(Node_p node)
{
	while (node->parent->color == 1) {
		if (node->parent == node->parent->parent->left) {
			typename RB_Tree<T>::Node_p tmpNode = node->parent->parent->right;
			if (tmpNode->color == 1) {						// case 1
				node->parent->color = 0;
				tmpNode->color = 1;
				node = node->parent->parent;
			}
			else if (node == node->parent->right) {			// case 2
				node = node->parent;
				rotateLeft(node);
			}
			node->parent->color = 0;						// case 3
			node->parent->parent->color = 1;
			rotateRight(node->parent->parent);
		}
		else {
			typename RB_Tree<T>::Node_p tmpNode = node->parent->parent->left;
			if (tmpNode->color == 1) {
				node->parent->color = 0;
				tmpNode->color = 1;
				node = node->parent->parent;
			}
			else if (node == node->parent->left) {
				node = node->parent;
				rotateRight(node);
			}
			node->parent->color = 0;
			node->parent->parent->color = 1;
			rotateLeft(node->parent->parent);
		}
	}
	root->color = 0;
}

template <typename T> void RB_Tree<T>::rotateRight(Node_p node)
{
	typename RB_Tree<T>::Node_p tmpNode = node->left;
	node->left = tmpNode->right;
	if (tmpNode->right != warden)
		tmpNode->right->parent = node;
	tmpNode->parent = node->parent;
	if (node->parent == warden)
		root = tmpNode;
	else if (node == node->parent->right)
		node->parent->right = tmpNode;
	else node->parent->left = tmpNode;
	tmpNode->right = node;
	node->parent = tmpNode;
}

template <typename T> void RB_Tree<T>::rotateLeft(Node_p node)
{
	typename RB_Tree<T>::Node_p tmpNode = node->right; // initialize node to rotate
	node->right = tmpNode->left; // change left undertree of tmpNode for right undertree of node
	if (tmpNode->left != warden) // if left undertree of tmpNode is not warden then change parent ptr of tmpNode to node
		tmpNode->left->parent = node;
	tmpNode->parent = node->parent; // parent of tmpNode change to parent of node
	if (node->parent == warden) // if node is root then change root to tmpNode
		root = tmpNode;
	else if (node == node->parent->left) // if node is left child then make tmpNode as a left child
		node->parent->left = tmpNode;
	else node->parent->right = tmpNode; // and likewise
	tmpNode->left = node;
	node->parent = tmpNode;
}

template <typename T> RB_Tree<T>::RB_Tree() : warden(nullptr), root(nullptr)
{
	initWarden();
}

template <typename T> void RB_Tree<T>::insert(T data)
{
	typename RB_Tree<T>::Node_p tmpWarden = warden;
	typename RB_Tree<T>::Node_p tmpRoot = root;
	typename RB_Tree<T>::Node_p newNode = nullptr;
	while (root != warden) {
		tmpWarden = tmpRoot;
		if (newNode->data < tmpRoot->data)
			tmpRoot = tmpRoot->left;
		else tmpRoot = tmpRoot->right;
	}
	newNode->parent = tmpWarden;
	if (tmpWarden == warden)
		root = newNode;
	else if (newNode->data < tmpWarden->data)
		tmpWarden->left = newNode;
	else tmpWarden->right = newNode;
	newNode->left = newNode->right = warden;
	newNode->color = 1;
	insertFixUp(newNode);
}
