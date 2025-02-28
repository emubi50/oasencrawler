#pragma once
#include "Field.h"
#include "Position.h"

class World
{
public:
	// Constructor and Destructor
	World();
	~World();
	// Functions
	void displayWorld(int x, int y);
	// Variables
	Field world[5][5];
	Position previousPosition;
	int totalRelics;
};

