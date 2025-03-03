#include "Entity.h"
#include <iostream>

Entity::Entity()
{
    position.x = 0;
    position.y = 0;
    health = 5;
    relics = 0;
    constitution = 10;
    dexterity = 10;
    wisdom = 10;
    conItems = 0;
    dexItems = 0;
    wisItems = 0;
    npc = true;
}

Entity::Entity(int x, int y, bool npc)
{
    position.x = x;
    position.y = y;
    health = 5;
    relics = 0;
    constitution = 10;
    dexterity = 10;
    wisdom = 10;
    conItems = 0;
    dexItems = 0;
    wisItems = 0;
    this -> npc = npc;
}

Entity::~Entity()
{
}

void Entity::displayStats()
{
    std::cout << "Position: (" << position.x << ", " << position.y << ")" << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Relics: " << relics << std::endl;
    std::cout << "CON: " << constitution << " / Scorched Desert Cloaks found: " << conItems << std::endl;
    std::cout << "DEX: " << dexterity << " / Whips of the Desert Nomad found: " << dexItems << std::endl;
    std::cout << "WIS: " << wisdom << " / Ancient Sandscrolls found: " << wisItems << std::endl;
}

Position Entity::getPosition()
{
    return position;
}

void Entity::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

bool Entity::alive()
{
    return ((health > 0) ? true : false);
}

void Entity::heal()
{
    health++;
}

void Entity::takeDamage()
{
    health--;
}

bool Entity::rollSavingThrow(int difficultyClass, int rollType, int items)
{
    int roll;
    int advantageRoll;
    int modifier;
    switch (rollType)
    {
    case 0:
        modifier = (constitution - 10) / 2;
        break;
    case 1:
        modifier = (dexterity - 10) / 2;
        break;
    case 2:
        modifier = (wisdom - 10) / 2;
        break;
    }
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "DC: " << difficultyClass << std::endl;
    std::cout << "Press ENTER to roll a saving throw..." << std::endl;
    std::cin.get();
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Rolling saving throw..." << std::endl;
    roll = rand() % 20 + 1;
    std::cout << "Rolled: " << roll;
    std::cout << " + " << modifier;
    roll += modifier;
    std::cout << " = " << roll << std::endl;
    std::cout << "Advantage roll? ";
    if (items > 0)
    {
        std::cout << "yes" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Press ENTER to roll a saving throw..." << std::endl;
        std::cin.get();
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Rolling saving throw..." << std::endl;
        advantageRoll = rand() % 20 + 1;
        std::cout << "Rolled: " << advantageRoll;
        std::cout << " + " << modifier;
        roll += modifier;
        std::cout << " = " << advantageRoll << std::endl;
    }
    else
    {
        std::cout << "no" << std::endl;
        advantageRoll = roll;
    }
    if (roll >= difficultyClass || advantageRoll >= difficultyClass)
    {
        std::cout << "You have passed the saving throw!" << std::endl;
        std::cout << "Press ENTER to continue..." << std::endl;
        std::cin.get();
        return true;
    }
    else
    {
        std::cout << "You have failed the saving throw!" << std::endl;
        std::cout << "Press ENTER to continue..." << std::endl;
        std::cin.get();
        takeDamage();
        return false;
    }
}

bool Entity::move(char command)
{
    switch (command)
    {
    case 'w':
    case 'W':
        if (position.y > 0)
        {
            position.y--;
            return true;
        }
        else
        {
            std::cout << "You can't move there!" << std::endl;
            return false;
        }
        break;
    case 'a':
    case 'A':
        if (position.x > 0)
        {
            position.x--;
            return true;
        }
        else
        {
            std::cout << "You can't move there!" << std::endl;
            return false;
        }
        break;
    case 's':
    case 'S':
        if (position.y < 4)
        {
            position.y++;
            return true;
        }
        else
        {
            std::cout << "You can't move there!" << std::endl;
            return false;
        }
        break;
    case 'd':
    case 'D':
        if (position.x < 4)
        {
            position.x++;
            return true;
        }
        else
        {
            std::cout << "You can't move there!" << std::endl;
            return false;
        }
        break;
    default:
        std::cout << "Invalid command!" << std::endl;
        return false;
        break;
    }
}

void Entity::addItems(int itemType)
{
    switch (itemType)
    {
    case 0:
        conItems++;
        constitution = 10 + (conItems % 2);
        break;
    case 1:
        dexItems++;
        dexterity = 10 + (dexItems % 2);
        break;
    case 2:
        wisItems++;
        wisdom = 10 + (wisItems % 2);
    }
}

int Entity::useItems(int itemType)
{
    switch (itemType)
    {
    case 0:
        return conItems;
        break;
    case 1:
        return dexItems;
        break;
    case 2:
        return wisItems;
    default:
        return 0;
    }
}

int Entity::relicsObtained()
{
    return relics;
}

void Entity::takeRelic()
{
    relics++;
}

int Entity::getAttribute(int attributeType)
{
    switch (attributeType)
    {
    case 0:
        return constitution;
        break;
    case 1:
        return dexterity;
        break;
    case 2:
        return wisdom;
    }
    return 0;
}

bool Entity::isNpc()
{
    return npc;
}
