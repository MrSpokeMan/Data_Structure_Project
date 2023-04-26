#ifndef NODE_H
#define NODE_H
class Node
{
public:
	int data;
	Node(int data);
	Node* parent;
	Node* left;
	Node* right;
	int color; // color attribute of a tree: 0 - black, 1 - red
};
#endif