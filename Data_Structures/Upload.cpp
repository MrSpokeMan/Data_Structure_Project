#include "Upload.h"
#include <fstream>
#include <sstream>

Upload::Upload(int size, std::string structure_choice)
{
	this->size = size;
	this->structure_choice = structure_choice;
	dataFromFile();
}

void Upload::dataFromFile()
{
	std::ifstream file;
	file.open("recipes.csv");

	if (file.is_open())
	{
		// Read each line from the file
		std::string line;
		std::getline(file, line);
		if (structure_choice == "tree")
		{
			while (std::getline(file, line))
			{
				if (size != 0)
					if (rbTree->getSize() >= size) break;

				std::stringstream ss(line);
				std::string name, idStr, minutesStr;

				// Extract name, id, and minutes from the line
				if (std::getline(ss, name, ',') && std::getline(ss, idStr, ',') && std::getline(ss, minutesStr, ','))
				{
					Recipes recipes;
					recipes.name = name;
					recipes.index = std::stoi(idStr);
					recipes.value = std::stoi(minutesStr);

					rbTree->insert(recipes);
				}
			}
		}
		if (structure_choice == "HashMap")
		{
			while (std::getline(file, line))
			{
				if (size != 0)
					if (hashMap.getSize() >= size) break;

				std::stringstream ss(line);
				std::string name, idStr, minutesStr;

				// Extract name, id, and minutes from the line
				if (std::getline(ss, name, ',') && std::getline(ss, idStr, ',') && std::getline(ss, minutesStr, ','))
				{
					Recipes recipes;
					recipes.name = name;
					recipes.index = std::stoi(idStr);
					recipes.value = std::stoi(minutesStr);

					hashMap.insert(recipes.name, recipes);
				}
			}
		}
	}

	file.close();
}
