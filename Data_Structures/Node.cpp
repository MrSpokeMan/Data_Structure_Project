#include "Node.h"

Node::Node(int data)
{
	this->data = data;
	parent = left= right = nullptr;
	color = 0;
}
