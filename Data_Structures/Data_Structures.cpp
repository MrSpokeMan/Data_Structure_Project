#include <iostream>
#include<random>
#include "RB_Tree.h"
#include "RB_Tree.cpp" // solution for linker problem
#include "HashMap.h"
#include "HashMap.cpp"

int main()
{

    struct Test {
        int value;
    };

    HashMap<std::string, int > myMap(10);

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(1, 100);

    myMap.insert("Banana", 20);
    myMap.insert("Banane", 20);
    myMap.insert("A", 20);
    myMap.insert("B", 20);
    myMap.insert("C", 20);
    std::cout << myMap.get("Banana") << std::endl;
    std::cout << myMap.get("Bas") << std::endl;
    myMap.remove("Bas");
    myMap.remove("Banana");
    std::cout << myMap.get("A") << std::endl;

    RB_Tree<Test> *rbTree = new RB_Tree<Test>;

    for (int i = 0; i < 50; i++)
    {
        Test rand;
        //Test rand1;
        //rand.value = dist(rng);
        rand.value = i;
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