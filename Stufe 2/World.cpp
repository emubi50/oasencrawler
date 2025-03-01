#include "World.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

World::World()
{
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

World::World(int emptyChance, int dangerChance, int wellChance, int relicChance, Position prev)
{
	totalRelics = 0;
	previousPosition = prev;
	dangerChance += emptyChance;
	wellChance += dangerChance;
	relicChance += wellChance;
	do
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int tileType = rand() % relicChance;
				if (tileType < emptyChance)
				{
					world[i][j].type = Field::FieldType::EMPTY;
				}
				else if (tileType >= emptyChance && tileType < dangerChance)
				{
					world[i][j].type = Field::FieldType::DANGER;
				}
				else if (tileType >= dangerChance && tileType < wellChance)
				{
					world[i][j].type = Field::FieldType::WELL;
				}
				else if (tileType >= wellChance && tileType < relicChance)
				{
					world[i][j].type = Field::FieldType::RELIC;
					this -> totalRelics++;
				}
			}
		}
	} while (totalRelics <= 0);
}

World::~World()
{
}

void World::displayWorld(int px, int py, int ex, int ey)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == py && j == px)
			{
				std::cout << "@ ";
			}
			else if (i == ey && j == ex)
			{
				std::cout << "! ";
			}
			else
			{
				std::cout << "* ";
			}
		}
		std::cout << std::endl;
	}
}

void World::displayTileTypes()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << world[i][j].type << " ";
		}
		std::cout << std::endl;
	}
}
