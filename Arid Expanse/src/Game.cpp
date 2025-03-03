#include "Game.h"
#include <iostream>
#include "Game.h"

Game::Game(int stage)
{
    //initialize the game and
    this->stage = stage;
    difficulty = 4;
    emptyChance = 4;
    dangerChance = 4;
    wellChance = 1;
    relicChance = 1;
    disboard = World(emptyChance, dangerChance, wellChance, relicChance, Position(0, 0));
    player = Entity(0, 0, false);
    enemy = Entity(4, 4, true);
}

Game::~Game()
{
}

void Game::printSeparator()
{
    std::cout << "----------------------------------------" << std::endl;
}

void Game::startGame()
{
    system("cls");
    switch (stage)
    {
    case 1:
        std::cout << "Welcome to Oasis of Sands!" << std::endl;
        printSeparator();
        std::cout << "In the heart of a vast, unforgiving desert lies an ancient land shrouded in mystery." <<
                  std::endl << "This is the Arid Expanse, where the wind whispers of forgotten civilizations," <<
                  std::endl << "and the sands hide relics of long - lost empires." << std::endl <<
                  std::endl << "For centuries, travelers have sought the legendary Oasis of the Sands," <<
                  std::endl << "a fabled haven said to grant unimaginable power to those who find it." <<
                  std::endl << "But few have returned, and those who do speak only in hushed tones of strange creatures," <<
                  std::endl << "treacherous terrain, and the unforgiving forces that guard the desert." << std::endl <<
                  std::endl << "Now, you find yourself on a journey into this desolate land," <<
                  std::endl << "armed with nothing but your wits, your will, and the hope of uncovering the truth buried beneath the dunes." << std::endl;
        break;
    case 2:
        std::cout << "Welcome to Echoes of Dunes!" << std::endl;
        printSeparator();
        std::cout << "The Arid Expanse stretches endlessly before you, a vast and merciless wilderness where time itself is swallowed by the shifting sands." <<
                  std::endl << "Once, civilizations thrived here, but now only echoes remain - whispers carried by the wind, etched into the dunes like fading memories." <<
                  std::endl << "Scattered across the wasteland lie relics of untold power, remnants of a forgotten age waiting to be unearthed." << std::endl <<
                  std::endl << "But the desert does not surrender its secrets without consequence." <<
                  std::endl << "With each relic reclaimed, the very fabric of the Expanse stirs, reshaping itself in unpredictable ways." <<
                  std::endl << "And in the silence between the howling winds, something watches - something bound to the echoes of the dunes." <<
                  std::endl << "The path ahead is uncertain, and the deeper you venture, the more the desert shifts against you." << std::endl <<
                  std::endl << "Step forward, if you dare. The Arid Expanse remembers all who walk its sands..." <<
                  std::endl << "and it does not forget easily." << std::endl;
        break;
    case 3:
        std::cout << "Welcome to Mirage of Fate!" << std::endl;
        printSeparator();
        std::cout << "The desert stretches beyond sight, an endless ocean of sand where time and truth waver like a distant mirage." <<
                  std::endl << "The relics, long buried beneath the shifting dunes, whisper of an ancient fate - one that binds you to this cursed expanse." << std::endl <<
                  std::endl << "Survival is no longer a matter of endurance alone. The desert itself weighs your strength, your resolve, your cunning." <<
                  std::endl << "Each step through the scorching wasteland may test a different facet of your being." <<
                  std::endl << "Danger does not merely lurk in the shadows - it judges you, forcing you to prove your worth." << std::endl <<
                  std::endl << "But fate is not without mercy. The wells, rare and precious, may yield gifts to tip the scales in your favor." <<
                  std::endl << "Relics, once mer echoes of the past, now hold the key to navigating the perils ahead." << std::endl <<
                  std::endl << "Yet, with every cycle, the desert awakens anew. The trials grow harsher, the mirage ever more elusive" <<
                  std::endl << "How long will you last before the sands claim as their own?" << std::endl;
        break;
    }
    printSeparator();
    std::cout << "Press ENTER to continue..." << std::endl;
    std::cin.ignore(1000, '\n');
    std::cin.get();
    run();
}

void Game::increaseDifficulty()
{
    dangerChance++;
    difficulty++;
}

void Game::displayGame()
{
    if (stage > 1)
    {
        disboard.printWorld(player.getPosition().x, player.getPosition().y, enemy.getPosition().x, enemy.getPosition().y);
    }
    else
    {
        disboard.printWorld(player.getPosition().x, player.getPosition().y);
    }
    printSeparator();
    std::cout << "Player Stats:" << std::endl;
    player.displayStats();
    printSeparator();
}

void Game::run()
{
    system("cls");
    if (stage == 1)
    {
        std::cout << "The sun beats down, and the sands stretch endlessly before you..." << std::endl;
    }
    else if (stage == 2)
    {
        std::cout << "The wind whispers, and the echoes of the dunes call out..." << std::endl;
    }
    else if (stage == 3)
    {
        std::cout << "The mirage shimmers, and the sands shift beneath your feet..." << std::endl;
    }
    enemy.setPosition(4, 4);
    do
    {
        if (disboard.getTotalRelics() == 0 && stage == 1)
        {
            endGame(0);
        }
        else if (player.alive() == false)
        {
            endGame(1);
        }
        else if (player.getPosition().x == enemy.getPosition().x && player.getPosition().y == enemy.getPosition().y && stage > 1)
        {
            endGame(2);
        }
        else if (disboard.getTotalRelics() == 0 && stage > 1)
        {
            increaseDifficulty();
            disboard = World(emptyChance, dangerChance, wellChance, relicChance, disboard.getPreviousPosition());
        }
        /* DEBUG: SEE TILE TYPES AND OTHER VARIABLES RELEVANT FOR GAME LOGIC
        disboard.displayTileTypes();
        std::cout << "Tile Type: " << disboard.getTileType(player.getPosition().x, player.getPosition().y).type << std::endl;
        std::cout << "Total Relics on the map: " << disboard.getTotalRelics() << std::endl;
        std::cout << "Player Relics: " << player.relicsObtained() << std::endl;
        std::cout << "Items (CON/DEX/WIS): " << player.getAttribute(0) << "/" << player.getAttribute(1) << "/" << player.getAttribute(2) << std::endl;
        */
        printSeparator();
        displayGame();
        move(player);
        system("cls");
        if (stage > 1)
        {
            move(enemy);
            system("cls");
        }
        evaluateField();
        disboard.setPreviousPosition(player.getPosition());
    }
    while (player.alive() == true);
}

void Game::move(Entity& entity)
{
    bool moved = false;
    do
    {
        char command;
        if(entity.isNpc() == false)
        {
            std::cout << "USE WASD to move: ";
            std::cin.get(command);
            std::cin.ignore(1000, '\n');
        }
        else
        {
            char movement[4] = { 'w', 'a', 's', 'd' };
            command = movement[rand() % 4];
        }
        moved = entity.move(command);
    }
    while(moved == false);

}

void Game::evaluateField()
{
    if (player.getPosition().x != disboard.getPreviousPosition().x || player.getPosition().y != disboard.getPreviousPosition().y)
    {
        if (disboard.getTotalRelics() == 0 && stage == 1)
        {
            endGame(0);
        }
        else if (player.alive() == false)
        {
            endGame(1);
        }
        else if(player.getPosition().x == enemy.getPosition().x && player.getPosition().y == enemy.getPosition().y && stage > 1)
        {
            endGame(2);
        }
        else
        {
            printFieldMessage(disboard.getTileType(player.getPosition().x, player.getPosition().y).type);
            disboard.clearTile(player.getPosition().x, player.getPosition().y);
        }
    }
    else
    {
        switch (rand() % 3)
        {
        case 0:
            std::cout << "The sands shift beneath your feet as you try to move beyond the dunes." <<
                      std::endl << "You realize your path is blocked by an invisible force." << std::endl;
            break;
        case 1:
            std::cout << "Your footsteps falter as you attempt to cross the edge of the desert." <<
                      std::endl << "The way forward is closed off, and you must turn back." << std::endl;
            break;
        case 2:
            std::cout << "The harsh wind blows against your face as you try to step into the unknown." <<
                      std::endl << "A wave of frustration rises as the desert refuses your advance." << std::endl;
        }
    }
}

void Game::printFieldMessage(Field::FieldType type)
{
    switch (type)
    {
    case Field::FieldType::EMPTY:
        switch (rand() % 3)
        {
        case 0:
            std::cout << "You stand in a lonely patch of sand, with no signs of life in sight." <<
                      std::endl << "The horizon seems distant, and the sun beats down relentlessly." << std::endl;
            break;
        case 1:
            std::cout << "The desert stretches endlessly before you, a vast and unforgiving wasteland." <<
                      std::endl << "The wind whispers through the dunes, carrying with it the echoes of forgotten times." << std::endl;
            break;
        case 2:
            std::cout << "The sands shift beneath your feet, and the sun beats down mercilessly." <<
                      std::endl << "The Arid Expanse is a harsh and unforgiving land, where only the strong survive." << std::endl;
            break;
        }
        break;
    case Field::FieldType::DANGER:
        if (stage < 3)
        {
            //danger attacks player
            if (rand() % 24 > difficulty)
            {
                //safe from danger -> -0 hp
                switch (rand() % 3)
                {
                case 0:
                    std::cout << "A faint rumble echoes beneath the dry sands, but nothing seems to follow." <<
                              std::endl << "The desert remains still, and you take another careful step forward." << std::endl;
                    break;
                case 1:
                    std::cout << "The ground shifts slightly beneath your feet, as though the dunes themselves are alive." <<
                              std::endl << "Yet, nothing emerges, and you press onward with cautious relief." << std::endl;
                    break;
                case 2:
                    std::cout << "A gust of hot wind sweeps across the barren landscape, but no threat appears." <<
                              std::endl << "You recover your balance and continue, alert but unscathed." << std::endl;
                }
            }
            else
            {
                //not safe from danger -> -1 hp
                switch (rand() % 3)
                {
                case 0:
                    std::cout << "Suddenly, the sands beneath you crack open, and a sharp thorn-like spike juts out from the ground." <<
                              std::endl << "You feel a sharp sting as it grazes your side, leaving a painful mark." << std::endl;
                    break;
                case 1:
                    std::cout << "Out of nowhere, the desert floor erupts with a violent surge of sand, throwing you back." <<
                              std::endl << "You stagger, your chest tightening from the force of the impact." << std::endl;
                    break;
                case 2:
                    std::cout << "A fierce sandstorm swirls toward you from the horizon, slamming into your body with a brutal gust." <<
                              std::endl << "The sting of sand cuts into your skin, and you struggle to steady yourself against the onslaught." << std::endl;
                    break;
                }
                std::cout << "[-1 hp]" << std::endl;
                player.takeDamage();
                if(player.alive() == false)
                {
                    endGame(1);
                }
            }
        }
        else
        {
            //danger attacks specific attribute -> saving throw
            switch (rand() % 3)
            {
            case 0:
                //danger attacks constitution -> constitution saving throw
                std::cout << "The scorching heat beats down on you, sapping your strength with every step" <<
                          std::endl << "Your vision blurs as exhaustion threatens to overwhelm you." <<
                          std::endl << "Roll a Constitution Saving Throw!" << std::endl;
                if (player.rollSavingThrow((20 - player.getAttribute(0)) + (difficulty - 4), 0, player.useItems(0)))
                {
                    system("cls");
                    std::cout << "You grit your teeth and push forward, drawing on sheer willpower to endure the relentless sun." << std::endl;
                }
                else
                {
                    system("cls");
                    std::cout << "Your legs give way, and you collapse to your knees, the desert greedily stealing your breath as your body weakens." << std::endl;
                    std::cout << "[-1 hp]" << std::endl;
                    player.takeDamage();
                    if(player.alive() == false)
                    {
                        endGame(1);
                    }
                }
                break;
            case 1:
                //danger attacks dexterity -> dexterity saving throw
                std::cout << "A sudden tremor shifts the sand beneath your feet, revealing a hidden sinkhole." <<
                          std::endl << "Before you can react, the ground starts to pull you downward." <<
                          std::endl << "Roll a Dexterity Saving Throw!" << std::endl;
                if (player.rollSavingThrow((20 - player.getAttribute(1)) + (difficulty - 4), 1, player.useItems(1)))
                {
                    system("cls");
                    std::cout << "You leap to solid ground just in time, landing with a stumble but unharmed." << std::endl;
                }
                else
                {
                    system("cls");
                    std::cout << "The sand engulfs your legs, dragging you down as you desperately struggle to escape." << std::endl;
                    std::cout << "[-1 hp]" << std::endl;
                    player.takeDamage();
                    if(player.alive() == false)
                    {
                        endGame(1);
                    }
                }
                break;
            case 2:
                //danger attacks wisdom -> wisdom saving throw
                std::cout << "A distant shimmer on the horizon promises water, but something feels off." <<
                          std::endl << "The desert is known for its cruel mirages, and one wrong turn could lead you further from salvation." <<
                          std::endl << "Roll a Wisdom Saving Throw!" << std::endl;
                if (player.rollSavingThrow((20 - player.getAttribute(2)) + (difficulty - 4), 2, player.useItems(2)))
                {
                    system("cls");
                    std::cout << "You trust your instincts and change course, avoiding a deadly wasteland." << std::endl;
                }
                else
                {
                    system("cls");
                    std::cout << "You chase the illusion, only to find yourself lost and disoriented in the endless dunes." << std::endl;
                    std::cout << "[-1 hp]" << std::endl;
                    player.takeDamage();
                    if(player.alive() == false)
                    {
                        endGame(1);
                    }
                }
                break;
            }
        }
        break;
    case Field::FieldType::WELL:
        std::cout << "You see a well." << std::endl;
        if (stage < 3)
        {
            //possibility of obtaining an item
            if (rand() % 100 >= 70)
            {
                //item found
                switch (rand() % 3)
                {
                case 0:
                    std::cout << "As you draw closer to the well, something catches your eye at the edge. Beneath the surface," <<
                              std::endl << "you discover a scorched desert cloak woven from thick desert plans and animal hides, whethered by the sun's relentless heat." << std::endl;
                    std::cout << "[SCORCHED DESERT CLOAK (CON) added to Inventory]" << std::endl;
                    player.addItems(0);
                    break;
                case 1:
                    std::cout << "As you approach the well, you feel a faint breeze. When you peer inside," <<
                              std::endl << "you find a flexible and durable whip made from a mix of hardened leather and desert vines." << std::endl;
                    std::cout << "[WHIP OF THE DESERT NOMAD (DEX) added to Inventory]" << std::endl;
                    player.addItems(1);
                    break;
                case 2:
                    std::cout << "As you kneel by the well, you notice a scroll lying on the ground. Upon further inspection," <<
                              std::endl << "you find the ancient scroll to contain knowledge passed down through generations, written in fading ink but still legible." << std::endl;
                    std::cout << "[SCORCHED DESERT CLOAK (CON) added to Inventory]" << std::endl;
                    player.addItems(2);
                }
            }
        }
        if (rand() % 24 > difficulty || stage == 1)
        {
            //well is good -> +1 hp
            switch (rand() % 3)
            {
            case 0:
                std::cout << "You have found a well, hidden beneath the sands of the Arid Expanse." <<
                          std::endl << "The water is cool and refreshing, a welcome respite from the scorching heat." << std::endl;
                break;
            case 1:
                std::cout << "A well rises before you, its waters clear and inviting." <<
                          std::endl << "You drink deeply, feeling strength and vitality return to your weary limbs." << std::endl;
                break;
            case 2:
                std::cout << "The well before you is a rare sight in the desert, a precious oasis in the endless dunes." <<
                          std::endl << "You drink from its waters, feeling the desert's thirst quenched and your spirit renewed." << std::endl;
                break;
            }
            std::cout << "[+1 relic]" << std::endl;
            player.heal();
        }
        else
        {
            //something is wrong with the well -> +0 hp
            switch (rand() % 3)
            {
            case 0:
                std::cout << "The well before you is a mirage, a cruel trick of the desert to lure the unwary." <<
                          std::endl << "You reach for the water, only to find it slipping through your fingers like sand." << std::endl;
                break;
            case 1:
                std::cout << "The well is dry, its waters long since vanished beneath the shifting sands." <<
                          std::endl << "You search in vain for a drop of moisture, but find only emptiness." << std::endl;
                break;
            case 2:
                std::cout << "The well is poisoned, its waters tainted by some unseen force." <<
                          std::endl << "You recoil in horror, realizing too late the danger that lies hidden in the depths." << std::endl;
                break;
            }
        }
        break;
    case Field::FieldType::RELIC:
        std::cout << "Something buried in the ground catches the glimpse of your eye." << std::endl;
        if (stage == 3)
        {
            //possibility of obtaining an item
            if (rand() % 100 >= 70)
            {
                //item found
                std::cout << "As you reach to grab the item in the sand, you feel something else and pull it out." <<
                          std::endl << "It appears to be";
                switch (rand() % 3)
                {
                case 0:
                    std::cout << "a scorched desert cloak woven from thick desert plans and animal hides, whethered by the sun's relentless heat." << std::endl;
                    std::cout << "[SCORCHED DESERT CLOAK (CON) added to Inventory]" << std::endl;
                    player.addItems(0);
                    break;
                case 1:
                    std::cout << "a flexible and durable whip made from a mix of hardened leather and desert vines." << std::endl;
                    std::cout << "[WHIP OF THE DESERT NOMAD (DEX) added to Inventory]" << std::endl;
                    player.addItems(1);
                    break;
                case 2:
                    std::cout << "an ancient scroll to contain knowledge passed down through generations, written in fading ink but still legible." << std::endl;
                    std::cout << "[ANCIENT SANDSCROLL (WIS) added to Inventory]" << std::endl;
                    player.addItems(2);
                    break;
                }
            }
        }
        switch (rand() % 3)
        {
        //relic found -> +1 relic
        case 0:
            std::cout << "As you brush away the loose sand, your fingers strike something solid - an ancient artifact, half-buried and forgotten by time." <<
                      std::endl << "The moment you lift it, a faint whisper of wind stirs around you, as if the desert itself acknowledges your discovery." << std::endl;
            break;
        case 1:
            std::cout << "Resting atop a sun-bleached stone, a relic glows faintly in the shifting light, untouched by time." <<
                      std::endl << "As you reach for it, a strange sensation washes over you - memories not your own, lingering like echoes in the dunes." << std::endl;
            break;
        case 2:
            std::cout << "A sudden gust of wind parts the sand, revealing the faint glint of something hidden beneath the surface. As you dig," <<
                      std::endl << "your hands close around a relic, its surface warm from the sun, its presence a silent testament to the forgotten ones who walked this land before you." << std::endl;
            break;
        }
        std::cout << "[+1 relic]" << std::endl;
        player.takeRelic();
        disboard.relicTaken();
        break;
    }
}

void Game::endGame(int ending)
{
    system("cls");
    if (ending == 0)
    {
        std::cout << "The shifting sand whisper your triumph as the final relic rests in your hands." <<
                  std::endl << "Yet, the desert is ever-changing - winds reshape the dunes, and new echoes stir beneath the sun-scorched expanse." <<
                  std::endl << "Your journey does not end; it merely begins anew." << std::endl;
        printSeparator();
        std::cout << "Congratulations! You have found all the relics!" << std::endl;

    }
    else if (ending == 1)
    {
        std::cout << "The heat weighs heave, each step slower than the last." <<
                  std::endl << "As strength fades and the desert swallows your weary form," <<
                  std::endl << "the relics slip from your grasp, lost once more to time and sand." << std::endl;

        printSeparator();
        std::cout << "Game Over! You have perished in the desert." << std::endl;

    }
    else if (ending == 2)
    {
        std::cout << "A fleeting shadow, then a rush of movement - too fast to escape." <<
                  std::endl << "The last thing you see is the dunes stretching endlessly before you," <<
                  std::endl << "the echoes of past wanderers fading into the wind as you become one of them." << std::endl;
        printSeparator();
        std::cout << "Game Over! You have been caught by the desert's guardian." << std::endl;

    }
    printSeparator();
    std::cout << "Thank you for playing!" << std::endl;
    std::cout << "Press ENTER to exit..." << std::endl;
    std::cin.get();
    exit(0);
}
