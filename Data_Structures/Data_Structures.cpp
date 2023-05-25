#include <iostream>
#include<random>
#include "RB_Tree.h"
#include "RB_Tree.cpp" // solution for linker problem

int main()
{
    
    struct Test {
        int value;
    };

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(1, 1500);

    RB_Tree<Test> *rbTree = new RB_Tree<Test>;

    for (int i = 0; i < 100; i++)
    {
        Test rand;
        //Test rand1;
        rand.value = dist(rng);
        //rand.value = i;
        //rand1.value = 13;
        rbTree->insert(rand);
        /*rand.value = 12;
        rbTree->insert(rand);
        rbTree->insert(rand);
        rand.value = 2;
        rbTree->insert(rand);*/
    }
    rbTree->show();
}