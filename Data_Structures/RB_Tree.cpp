﻿#include "RB_Tree.h"
#include <string>
#include <iostream>

template <typename T>
void RB_Tree<T>::initWarden()
{
	warden = new Node<T>(T());
	warden->color = 0;
	warden->left = nullptr;
	warden->right = nullptr;
	warden->parent = nullptr;
}

template <typename T>
void RB_Tree<T>::insertFixUp(Node_p node)
{
	typename RB_Tree<T>::Node_p tmpNode;
	while (node->parent->color == 1)
	{
		if (node->parent == node->parent->parent->right)
		{
			tmpNode = node->parent->parent->left;
			if (tmpNode->color == 1)
			{ // case 1
				node->parent->color = 0;
				tmpNode->color = 0;
				node->parent->parent->color = 1;
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->left)
				{ // case 2
					node = node->parent;
					rotateRight(node);
				}
				node->parent->color = 0; // case 3
				node->parent->parent->color = 1;
				rotateLeft(node->parent->parent);
			}
		}
		else
		{
			tmpNode = node->parent->parent->right;
			if (tmpNode->color == 1)
			{
				node->parent->color = 0;
				tmpNode->color = 0;
				node->parent->parent->color = 1;
				node = node->parent->parent;
			}
			else
			{
				if (node == node->parent->right)
				{
					node = node->parent;
					rotateLeft(node);
				}
				node->parent->color = 0;
				node->parent->parent->color = 1;
				rotateRight(node->parent->parent);
			}
		}
		if (node == root)
		{
			break;
		}
	}
	root->color = 0;
}

template <typename T>
void RB_Tree<T>::rotateRight(Node_p node)
{
	typename RB_Tree<T>::Node_p tmpNode = node->left;
	node->left = tmpNode->right;
	if (tmpNode->right != warden)
		tmpNode->right->parent = node;
	tmpNode->parent = node->parent;
	if (node->parent == nullptr)
		root = tmpNode;
	else if (node == node->parent->right)
		node->parent->right = tmpNode;
	else
		node->parent->left = tmpNode;
	tmpNode->right = node;
	node->parent = tmpNode;
}

template <typename T>
void RB_Tree<T>::rotateLeft(Node_p node)
{
	typename RB_Tree<T>::Node_p tmpNode = node->right; // initialize node to rotate
	node->right = tmpNode->left;					   // change left undertree of tmpNode for right undertree of node
	if (tmpNode->left != warden)					   // if left undertree of tmpNode is not warden then change parent ptr of tmpNode to node
		tmpNode->left->parent = node;
	tmpNode->parent = node->parent; // parent of tmpNode change to parent of node
	if (node->parent == nullptr)	// if node is root then change root to tmpNode
		root = tmpNode;
	else if (node == node->parent->left) // if node is left child then make tmpNode as a left child
		node->parent->left = tmpNode;
	else
		node->parent->right = tmpNode; // and likewise
	tmpNode->left = node;
	node->parent = tmpNode;
}

template <typename T>
RB_Tree<T>::RB_Tree()
{
	initWarden();
	this->root = this->warden;
}

template <typename T>
void RB_Tree<T>::insert(T data)
{
	typename RB_Tree<T>::Node_p tmpWarden = nullptr;
	typename RB_Tree<T>::Node_p tmpRoot = this->root;
	typename RB_Tree<T>::Node_p newNode = new Node<T>(data);
	newNode->data = data;
	newNode->left = warden;
	newNode->right = warden;
	newNode->color = 1;
	size++;

	while (tmpRoot != warden)
	{
		tmpWarden = tmpRoot;
		if (newNode->data.value < tmpRoot->data.value)
			tmpRoot = tmpRoot->left;
		else
			tmpRoot = tmpRoot->right;
	}

	newNode->parent = tmpWarden;

	if (tmpWarden == nullptr)
		root = newNode;
	else if (newNode->data.value < tmpWarden->data.value)
		tmpWarden->left = newNode;
	else
		tmpWarden->right = newNode;

	if (newNode->parent == nullptr)
	{
		newNode->color = 0;
		return;
	}

	if (newNode->parent->parent == nullptr)
	{
		return;
	}

	insertFixUp(newNode);
}

template <typename T>
void RB_Tree<T>::show_helper(typename RB_Tree<T>::Node_p root, std::string tabulator, bool visited_last)
{
	if (root != warden)
	{
		printf("%s", tabulator.c_str());
		if (visited_last)
		{
			std::cout << "R ---- ";
			tabulator += "\t";
		}
		else
		{
			std::cout << "L ---- ";
			tabulator += "|  ";
		}
		std::string node_color = root->color ? "\x1B[31m(r)\033[0m" : "\x1B[90m(b)\033[0m";
		printf("%d %s\n", root->data.value, node_color.c_str());
		show_helper(root->left, tabulator, false);
		show_helper(root->right, tabulator, true);
	}
}

template <typename T>
void RB_Tree<T>::show() { show_helper(getRoot(), "", true); }

template <typename T>
typename RB_Tree<T>::Node_p RB_Tree<T>::getRoot()
{
	return this->root;
}

template <typename T>
void RB_Tree<T>::find_helper(Node_p node, int value)
{
	if (!(node->data.value == value))
	{
		std::cout << "Nie ma takiego elementu" << std::endl;
	}
	else if (node->data.value < value || node->data.value > value)
	{
		if (node->data.value < value)
			find_helper(node->right, value);
		else
			find_helper(node->left, value);
	}
	else
		std::cout << "Wezel: " << node->data.value << " minut" << std::endl << "Nazwa przepisu: " << node->data.name << std::endl << "Index w bazie: " << node->data.index << std::endl;

}

template <typename T>
void RB_Tree<T>::find(int value)
{
	find_helper(getRoot(), value);
}
