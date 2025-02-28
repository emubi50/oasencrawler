#pragma once
#include "World.h"
#include "Entity.h"

class Game
{
public:
	// Constructor and Destructor
	Game();
	~Game();

	// Functions
	void displayGame();
	void run();
	void printSeparator();
	char readPrompt();
	void movePlayer(char command);
	void evaluateField();

	// Variables
	World disboard;
	Entity player;
};

