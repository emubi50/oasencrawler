#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	health = 5;
	relics = 0;
}

Entity::Entity(int x, int y)
{
	position.x = x;
	position.y = y;
	health = 5;
	relics = 0;
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