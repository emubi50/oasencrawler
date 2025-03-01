#pragma once
#include "Field.h"
#include "Position.h"

class World
{
public:
	// Constructor and Destructor
	World();
	World(int emptyChance, int dangerChance, int wellChance, int relicChance, Position prev);
	~World();
	// Functions
	void displayWorld(int px, int py, int ex, int ey);
	void displayTileTypes();
	// Variables
	Field world[5][5];
	Position previousPosition;
	int totalRelics;
};

