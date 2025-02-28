#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

World::World()
{
	srand(time(NULL));
	totalRelics = 0;
	previousPosition.x = 0;
	previousPosition.y = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int tileType = rand() % 10;
			if (tileType < 4)
			{
				world[i][j].type = Field::FieldType::EMPTY;
			}
			else if (tileType >= 4 && tileType < 8)
			{
				world[i][j].type = Field::FieldType::DANGER;
			}
			else if (tileType == 8)
			{
				world[i][j].type = Field::FieldType::WELL;
			}
			else
			{
				world[i][j].type = Field::FieldType::RELIC;
				totalRelics++;
			}
		}
	}
}

World::~World()
{
}

void World::displayWorld(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == y && j == x)
			{
				std::cout << "@ ";
			}
			else
			{
				std::cout << "* ";
			}
		}
		std::cout << std::endl;
	}
}