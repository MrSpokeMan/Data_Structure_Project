#include "RB_Tree.h"
#include "HashTable.h"
#include "HashTable.cpp"
#include "HashMap.h"
#include "Upload.h"
#include "time_measure.h"
#include <iostream>

int main()
{
    double start, end;
    //Upload *upload = new Upload(20, "tree");

    start = get_wall_time();
    Upload upload_hash = Upload(10000, "HashMap");
    end = get_wall_time();

    //upload->rbTree->show();


    //std::cout << "\n";
    Recipes zmienna =  upload_hash.hashMap.get("20 000 prize winning chili con carne");

    std::cout << zmienna.name << zmienna.index << std::endl;
    std::cout << end - start << std::endl;

    //upload->rbTree->find(20);

    //upload->rbTree->find(135);
}