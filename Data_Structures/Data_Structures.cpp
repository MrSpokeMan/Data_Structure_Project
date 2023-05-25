#include <iostream>
#include <random>
#include "RB_Tree.h"
#include "RB_Tree.cpp" // solution for linker problem
#include "HashTable.h"
#include "HashTable.cpp"
#include "HashMap.h"

int main()
{

    struct Test
    {
        int value;
    };

    HashTable<std::string, int> myTable(10);
    HashMap<std::string, int> myMap;

    std::random_device rd;
    std::mt19937 rng(rd());

    /*myMap.insert("Banana", 20);
    myMap.insert("Banane", 20);
    myMap.insert("A", 20);
    myMap.insert("B", 20);
    myMap.insert("C", 20);
    std::cout << myMap.get("Banana") << std::endl;
    std::cout << myMap.get("Bas") << std::endl;
    myMap.remove("Bas");
    myMap.remove("Banana");
    std::cout << myMap.get("A") << std::endl;

    myTable.insert("Banana", 20);
    myTable.insert("Banane", 20);
    myTable.insert("A", 20);
    myTable.insert("B", 20);
    myTable.insert("C", 20);
    std::cout << myTable.get("Banana") << std::endl;
    std::cout << myTable.get("Bas") << std::endl;
    myTable.remove("Bas");
    myTable.remove("Banana");
    std::cout << myTable.get("A") << std::endl;*/
    std::uniform_int_distribution<int> dist(1, 1500);

    RB_Tree<Test> *rbTree = new RB_Tree<Test>;

    for (int i = 0; i < 50; i++)
    {
        Test rand;
        rand.value = dist(rng);
        // rand.value = i;
        // Test rand1;
        rand.value = dist(rng);
        // rand.value = i;
        // rand1.value = 13;
        rbTree->insert(rand);
        /*rand.value = 12;
        rbTree->insert(rand);
        rbTree->insert(rand);
        */
    }
    rbTree->show();
    rbTree->find(9);
}