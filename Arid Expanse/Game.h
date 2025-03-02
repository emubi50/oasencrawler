#pragma once
#include "World.h"
#include "Entity.h"

class Game
{
public:
	// Constructor and Destructor
	Game(int level);
	~Game();

	// Functions
	void printSeparator();
	void startGame();
	void increaseDifficulty(); // Only for level 2 or 3
	void run();
	void displayGame();
	void movePlayer();
	void moveEnemy();
	void evaluateField();
	void printFieldMessage(Field::FieldType type);
	bool rollSavingThrow(int difficultyClass, bool hasAdvantage);
	void endGame();
	

	// Variables
	World disboard;
	Entity player;
	Entity enemy;
	int level;
	int difficulty;
	int emptyChance;
	int dangerChance;
	int wellChance;
	int relicChance;
};

