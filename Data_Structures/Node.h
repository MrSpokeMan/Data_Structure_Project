#ifndef NODE_H
#define NODE_H
template <class T> class Node
{
public:
	T data;

	Node(T data) : data(data), parent(nullptr), left(nullptr), right(nullptr), color(0) {};

	Node* parent;
	Node* left;
	Node* right;
	int color; // color attribute of a tree: 0 - black, 1 - red
};
#endif