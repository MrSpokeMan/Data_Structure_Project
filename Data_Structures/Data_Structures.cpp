#include "RB_Tree.h"
#include "HashTable.h"
#include "HashTable.cpp"
#include "HashMap.h"
#include "Upload.h"
#include <iostream>

int main()
{
    Upload *upload = new Upload(0);

    // upload->rbTree->show();

    std::cout << "\n";

    upload->rbTree->find(20);
}