#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	position.x = 0;
	position.y = 0;
	health = 5;
	relics = 0;
	constitution = 0;
	dexterity = 0;
	wisdom = 0;
	conItems = 0;
	dexItems = 0;
	wisItems = 0;
}

Entity::Entity(int x, int y)
{
	position.x = x;
	position.y = y;
	health = 5;
	relics = 0;
	constitution = 0;
	dexterity = 0;
	wisdom = 0;
	conItems = 0;
	dexItems = 0;
	wisItems = 0;
}

Entity::~Entity()
{
}

void Entity::displayStats()
{
	std::cout << "Position: (" << position.x << ", " << position.y << ")" << std::endl;
	std::cout << "Health: " << health << std::endl;
	std::cout << "Relics: " << relics << std::endl;
}