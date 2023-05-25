#pragma once
#include "Node.h"
#include "Upload.h"
#include <string>

template <class T>
class RB_Tree
{
private:
    typedef Node<T> *Node_p; // creating node pointer to prevent too much usage of memory

    Node_p warden;
    Node_p root;

    int size = 0;

    void initWarden(); // creating node that is NULL for every leaf
    void insertFixUp(Node_p node);
    void rotateRight(Node_p node); // O(1)
    void rotateLeft(Node_p node);

public:
    RB_Tree();

    int getSize() { return size; }
    void insert(T data); // O(log n)
    void show_helper(Node_p root, std::string tabulator, bool visited_last);
    void show();
    void find_helper(Node_p node, int value);
    void find(int value);
    Node_p getRoot();
};