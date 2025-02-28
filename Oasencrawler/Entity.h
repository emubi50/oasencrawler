#pragma once
#include "Position.h"

class Entity
{
public:
	// Constructor and Destructor
	Entity();
	~Entity();
	// Functions
	void displayStats();
	// Variables
	Position position;
	int health;
	int relics;

};

