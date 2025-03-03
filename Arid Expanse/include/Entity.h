#ifndef ENTITY_H
#define ENTITY_H

#include "Position.h"

class Entity
{
public:
    // Constructor and Destructor
    Entity();
    Entity(int x, int y, bool npc);
    ~Entity();
    // Functions
    void displayStats();
    Position getPosition();
    void setPosition(int x, int y);
    bool alive();
    void heal();
    void takeDamage();
    bool rollSavingThrow(int difficultyClass, int rollType, int items);
    bool move(char command);
    void addItems(int itemType);
    int useItems(int itemType);
    int relicsObtained();
    void takeRelic();
    int getAttribute(int attributeType);
    bool isNpc();

private:
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
    bool npc;
};


#endif // ENTITY_H
