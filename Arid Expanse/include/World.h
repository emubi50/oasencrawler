#ifndef WORLD_H
#define WORLD_H



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
    void printWorld(int px, int py, int ex, int ey);
    void printWorld(int px, int py);
    void displayTileTypes();
    Field getTileType(int x, int y);
    void clearTile(int x, int y);
    int getTotalRelics();
    void relicTaken();
    Position getPreviousPosition();
    void setPreviousPosition(Position prevPos);

private:
    // Variables
    Field world[5][5];
    Position previousPosition;
    int totalRelics;
};



#endif // WORLD_H
