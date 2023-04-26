#include "RB_Tree.h"

void RB_Tree::initWarden(Node_p node, Node_p parrent)
{
}

void RB_Tree::treeBalancingInsert(Node_p node)
{
}

void RB_Tree::rotateRight(Node_p node)
{
}

void RB_Tree::rotateLeft(Node_p node)
{
	Node_p tmpNode = node->right; // initialize node to rotate
	node->right = tmpNode->left; // change left undertree tmpNode for right undertree node
	if (tmpNode->left != warden)
		tmpNode->left->parent = node;

}
