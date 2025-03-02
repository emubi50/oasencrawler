#pragma once
#include "Position.h"

class Entity
{
public:
	// Constructor and Destructor
	Entity();
	Entity(int x, int y);
	~Entity();
	// Functions
	void displayStats();
	// Variables
	Position position;
	int health;
	int relics;
	int constitution;
	int dexterity;
	int wisdom;
	int conItems;
	int dexItems;
	int wisItems;

};

