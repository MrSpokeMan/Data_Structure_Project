#ifndef RB_TREE_H
#define RB_TREE_H
#include "Node.h"
template <class T> class RB_Tree
{
private:
    typedef Node<T>* Node_p; // creating node pointer to prevent too much usage of memory

    Node_p warden;
    Node_p root;

    void initWarden(); // creating node that is NULL for every leaf
    void insertFixUp(Node_p node);
    void rotateRight(Node_p node); // O(1)
    void rotateLeft(Node_p node);

public:
    RB_Tree();
    void insert(T data); // O(log n)
};
#endif RB_TREE_H