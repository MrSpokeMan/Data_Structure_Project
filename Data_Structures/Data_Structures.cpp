#include "RB_Tree.h"
#include "RB_Tree.cpp" // solution for linker problem
#include "HashTable.h"
#include "HashTable.cpp"
#include "HashMap.h"
//#include "Upload.h"
#include <iostream>
int main()
{
    // Upload upload = Upload(10);

    // upload.rbTree.show();
    struct Recipes
    {
        int index;        // index
        std::string name; // name
        int value;        // minutes
    };

    RB_Tree<Recipes> tree = RB_Tree<Recipes>();
    tree.insert({20, "mama", 1});
    tree.show();
    std::cout << tree.getSize();
}