#pragma once
#include <string>
#include "RB_Tree.h"
#include "HashMap.h"

struct Recipes
{
	int index;		  // id
	std::string name; // name
	int value;		  // minutes
};

class Upload
{
protected:
		int size;
		std::string structure_choice;

public:
	RB_Tree<Recipes>* rbTree = new RB_Tree<Recipes>;
	HashMap<std::string, Recipes> hashMap;

	Upload(int size, std::string structure_choice);//, std::string structure_choice);

	void dataFromFile();
};

#include "Upload.cpp"