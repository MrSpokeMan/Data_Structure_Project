#ifndef RB_TREE_H
#define RB_TREE_H
#include "Node.h"
class RB_Tree
{
private:
    typedef Node* Node_p; // creating node pointer to prevent too much usage of memory

    Node_p warden;
    Node_p root;

    void initWarden(Node_p node, Node_p parrent); // creating node that is NULL for every leaf
    void treeBalancingInsert(Node_p node);
    void rotateRight(Node_p node);
    void rotateLeft(Node_p node);
};
#endif RB_TREE_H