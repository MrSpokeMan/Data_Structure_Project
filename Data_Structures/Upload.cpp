#include "Upload.h"
#include <fstream>
#include <sstream>

Upload::Upload(int size)
{
	this->size = size;
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
		while (std::getline(file, line))
		{
			if (rbTree->getSize() >= size)
				break;

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

	file.close();
}
