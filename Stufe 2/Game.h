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
	void intro();
	void run();
	void increaseDifficulty();
	void printSeparator();
	char readPrompt();
	void movePlayer(char command);
	void moveEnemy();
	void evaluateField();
	void endGame();

	// Variables
	World disboard;
	Entity player;
	Entity enemy;
	int difficulty;
	int emptyChance;
	int dangerChance;
	int wellChance;
	int relicChance;
};

