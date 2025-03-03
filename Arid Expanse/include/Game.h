#ifndef GAME_H
#define GAME_H
#include "World.h"
#include "Entity.h"

class Game
{
public:
    // Constructor and Destructor
    Game(int stage);
    ~Game();

    // Functions
    void printSeparator();
    void startGame();
    void increaseDifficulty(); // Only for stage 2 or 3
    void run();
    void displayGame();
    void move(Entity& entity);
    void evaluateField();
    void printFieldMessage(Field::FieldType type);
    void endGame(int ending);



private:
    // Variables
    World disboard;
    Entity player;
    Entity enemy;
    int stage;
    int difficulty;
    int emptyChance;
    int dangerChance;
    int wellChance;
    int relicChance;

};

#endif // GAME_H
