#include <iostream>
#include "RB_Tree.h"
#include "RB_Tree.cpp" // solution for linker problem

int main()
{
    RB_Tree<int> *rbTree = new RB_Tree<int>;
    rbTree->insert(80);
}