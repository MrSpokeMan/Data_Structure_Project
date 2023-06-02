#pragma once
#include <string>
#include "RB_Tree.h"

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

public:
	RB_Tree<Recipes>* rbTree = new RB_Tree<Recipes>;

	Upload(int size);

	void dataFromFile();
};

#include "Upload.cpp"