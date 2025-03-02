#include "Game.h"
#include <iostream>
#include "Game.h"

Game::Game(int level)
{
	this->level = level;
	difficulty = 4;
	emptyChance = 4;
	dangerChance = 4;
	wellChance = 1;
	relicChance = 1;
	disboard = World(emptyChance, dangerChance, wellChance, relicChance, Position(0, 0));
	player = Entity(0, 0);
	enemy = Entity(4, 4);
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
	switch (level)
	{
	case 1:
		std::cout << "Welcome to Oasis of Sands!" << std::endl;
		printSeparator();
		std::cout << "In the heart of a vast, unforgiving desert lies an ancient land shrouded in mystery." <<
			std::endl << "This is the Arid Expanse, where the wind whispers of forgotten civilizations," <<
			std::endl << "and the sands hide relics of long - lost empires." <<
			std::endl << "For centuries, travelers have sought the legenary Oasis of the Sands," <<
			std::endl << "a fabled haven said to grant unimaginable power to those who find it." <<
			std::endl << "But few have returned, and those who do speak only in hushed tones of strange creatures," <<
			std::endl << "treacherous terrain, and the unforgiving forces that guard the desert." <<
			std::endl << "Now, you find yourself on a journey into this desolate land," <<
			std::endl << "armed with nothing but your wits, your will, and the hope of uncovering the truth buried beneath the dunes." << std::endl;
		printSeparator();
		std::cout << "Press ENTER to continue..." << std::endl;
		std::cin.get();
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
		printSeparator();
		std::cout << "Press ENTER to continue..." << std::endl;
		std::cin.get();
		break;
	case 3:
		std::cout << "Welcome to Mirage of Fate!" << std::endl;
		printSeparator();
		std::cout << "The deert stretches beyond sight, an endless ocean of sand where time and truth waver like a distant mirage." <<
			std::endl << "The relics, long buried beneath the shifting dunes, whisper of an ancient fate - one that binds you to this cursed expanse." << std::endl <<
			std::endl << "Survival is no longer a matter of endurance alone. The desert itself weighs your strength, your resolve, your cunning." <<
			std::endl << "Each step through teh scorching wasteland may test a different facet of your being." <<
			std::endl << "Danger does not merely lurk in the shadows - it judges you, forcing you to prove your worth." << std::endl <<
			std::endl << "But fate is not without mercy. The wells, rare and precious, may yield gifts to tip the scales in your favor." <<
			std::endl << "Relics, once mer echoes of the past, now hold the key to navigating the perils ahead." << std::endl <<
			std::endl << "Yet, with every cycle, the desert awakens anew. The trials grow harsher, the mirage ever more elusive" <<
			std::endl << "How long will you last before the sands claim as their own?" << std::endl;
		printSeparator();
		std::cin.get();
		break;
	}
	run();
}

void Game::increaseDifficulty()
{
	dangerChance++;
	difficulty++;
}

void Game::displayGame()
{
	if (level > 1)
	{
		disboard.displayWorld(player.position.x, player.position.y, enemy.position.x, enemy.position.y);
	}
	else {
		disboard.displayWorld(player.position.x, player.position.y);
	}
	printSeparator();
	std::cout << "Player Stats:" << std::endl;
	player.displayStats();
	printSeparator();
}

void Game::run()
{
	system("cls");
	if (level == 1)
	{
		std::cout << "The sun beats down, and the sands stretch endlessly before you..." << std::endl;
	}
	else if (level == 2)
	{
		std::cout << "The wind whispers, and the echoes of the dunes call out..." << std::endl;
	}
	else if (level == 3)
	{
		std::cout << "The mirage shimmers, and the sands shift beneath your feet..." << std::endl;
	}
	enemy.position.x = 4;
	enemy.position.y = 4;
	do
	{
		if ((player.relics == disboard.totalRelics && level == 1) || (player.position.x == enemy.position.x && player.position.y == enemy.position.y && level > 1) || player.health <= 0)
		{
			endGame();
		}
		else if (disboard.totalRelics == 0 && level > 1)
		{
			increaseDifficulty();
			disboard = World(emptyChance, dangerChance, wellChance, relicChance, disboard.previousPosition);
		}
		//disboard.displayTileTypes();
		printSeparator();
		displayGame();
		movePlayer();
		system("cls");
		if (level > 1)
		{
			moveEnemy();
		}
		evaluateField();
		printSeparator();
		disboard.previousPosition = player.position;
		
	} while (player.health > 0);
	endGame();
}

void Game::movePlayer()
{
	std::cout << "Use WASD to move: ";
	char command;
	std::cin.get(command);
	std::cin.ignore(1000, '\n');
	switch (command)
	{
	case 'w':
	case 'W':
		if (player.position.y > 0)
		{
			player.position.y--;
		}
		else
		{
			std::cout << "You can't move there!" << std::endl;
		}
		break;
	case 'a':
	case 'A':
		if (player.position.x > 0)
		{
			player.position.x--;
		}
		else
		{
			std::cout << "You can't move there!" << std::endl;
		}break;
	case 's':
	case 'S':
		if (player.position.y < 4)
		{
			player.position.y++;
		}
		else
		{
			std::cout << "You can't move there!" << std::endl;
		}break;
	case 'd':
	case 'D':
		if (player.position.x < 4)
		{
			player.position.x++;
		}
		else
		{
			std::cout << "You can't move there!" << std::endl;
		}break;
	default:
		std::cout << "Invalid command!" << std::endl;
		break;
	}
}

void Game::moveEnemy()
{
	switch (rand() % 4)
	{
	case 0:
		if (enemy.position.y > 0)
		{
			enemy.position.y--;
		}
		else
		{
			moveEnemy();
		}
		break;
	case 1:
		if (enemy.position.x > 0)
		{
			enemy.position.x--;
		}
		else
		{
			moveEnemy();
		}
		break;
	case 2:
		if (enemy.position.y < 4)
		{
			enemy.position.y++;
		}
		else
		{
			moveEnemy();
		}
		break;
	case 3:
		if (enemy.position.x < 4)
		{
			enemy.position.x++;
		}
		else
		{
			moveEnemy();
		}break;
	default:
		moveEnemy();
		break;
	}
}

void Game::evaluateField()
{
	if (player.relics == disboard.totalRelics && level == 1)
	{
		endGame();
	}
	else if (player.health <= 0)
	{
		endGame();
	}
	else if(player.position.x == enemy.position.x && player.position.y == enemy.position.y)
	{
		endGame();
	}
	else
	{
		printFieldMessage(disboard.world[player.position.y][player.position.x].type);
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
		if (level < 3)
		{
			//danger attacks player
			if (rand() % 24 < difficulty)
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
					player.health--;
					break;
				case 1:
					std::cout << "Out of nowhere, the desert floor erupts with a violent surge of sand, throwing you back." <<
						std::endl << "You stagger, your chest tightening from the force of the impact." << std::endl;
					player.health--;
					break;
				case 2:
					std::cout << "A fierce sandstorm swirls toward you from the horizon, slamming into your body with a brutal gust." <<
						std::endl << "The sting of sand cuts into your skin, and you struggle to steady yourself against the onslaught." << std::endl;
					player.health--;
					break;
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
				if (rollSavingThrow(dangerChance, (player.conItems) ? true : false))
				{
					std::cout << "You grit your teeth and push forward, drawing on sheer willpower to endure the relentless sun." << std::endl;
                }
				else
				{
					std::cout << "Your legs give way, and you collapse to your knees, the desert greedily stealing your breath as your body weakens." << std::endl;
					player.health--;
				}
				break;
			case 1:
				//danger attacks dexterity -> dexterity saving throw
				std::cout << "A sudden tremor shifts the sand beneath your feet, revealing a hidden sinkhole." <<
					std::endl << "Before you can react, the ground starts to pull you downward." <<
					std::endl << "Roll a Dexterity Saving Throw!" << std::endl;
				if (rollSavingThrow(dangerChance, (player.dexItems > 0) ? true : false))
				{
					std::cout << "You leap to solid ground just in time, landing with a stumble but unharmed." << std::endl;
				}
				else
				{
					std::cout << "The sand engulfs your legs, dragging you down as you desperately struggle to escape." << std::endl;
					player.health--;
				}
				break;
			case 2:
				//danger attacks wisdom -> wisdom saving throw
				std::cout << "A distant shimmer on the horizon promises water, but something feels off." <<
					std::endl << "The desert is known for its cruel mirages, and one wrong turn could lead you further from salvation." <<
					std::endl << "Roll a Wisdom Saving Throw!" << std::endl;
				if (rollSavingThrow(dangerChance, (player.wisItems > 0) ? true : false))
				{
					std::cout << "You trust your instincts and change course, avoiding a deadly wasteland." << std::endl;
				}
				else
				{
					std::cout << "You chase the illusion, only to find yourself lost and disoriented in the endless dunes." << std::endl;
					player.health--;
				}
				break;
			}
		}
		break;
	case Field::FieldType::WELL:
		std::cout << "You see a well." << std::endl;
		if (level < 3)
		{
			//possibility of obtaining an item
			if (rand() % 100 >= 70)
			{
				//item found
				switch (rand() % 3)
				{
				case 0:
					std::cout << "As you draw closer to the well, something catches your eye at the edge. Beneath the surface," <<
						std::endl << "you discover a scorched desert cloack woven from thick desert plans and animal hides, whethered by the sun's relentless heat." << std::endl;
					player.conItems++;
					break;
				case 1:
					std::cout << "As you approach the well, you feel a faint breeze. When you peer inside," <<
						std::endl << "you find a flexible and durable whip made from a mix of hardened leather and desert vines." << std::endl;
					player.dexItems++;
					break;
				case 2:
					std::cout << "As you kneel by the well, you notice a scroll lying on the ground. Upon further inspection," <<
						std::endl << "you find the ancient scroll to contain knowledge passed down through generations, written in fading ink but still legible." << std::endl;
					player.wisItems++;
				}
			}
		}
		if (rand() % 24 > difficulty)
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
			player.health++;
		}
		else {
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
		if (level < 3)
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
					std::cout << "a scorched desert cloack woven from thick desert plans and animal hides, whethered by the sun's relentless heat." << std::endl;
					player.conItems++;
					break;
				case 1:
					std::cout << "a flexible and durable whip made from a mix of hardened leather and desert vines." << std::endl;
					player.dexItems++;
					break;
				case 2:
					std::cout << "an ancient scroll to contain knowledge passed down through generations, written in fading ink but still legible." << std::endl;
					player.wisItems++;
					break;
				}
			}
		}
	}
}
bool Game::rollSavingThrow(int difficultyClass, bool hasAdvantage)
{
	int roll;
	int advantageRoll;
	system("cls");
	std::cout << "Press ENTER to roll a saving throw..." << std::endl;
	std::cin.get();
	printSeparator();
	std::cout << "Rolling saving throw..." << std::endl;
	roll = rand() % 20 + 1;
	std::cout << "Rolled: " << roll << std::endl;

	if (hasAdvantage)
	{
		advantageRoll = rand() % 20 + 1;
		std::cout << "Advantage Roll: " << advantageRoll << std::endl;
	}
	if (roll >= difficultyClass || advantageRoll >= difficultyClass)
	{
		std::cout << "You have passed the saving throw!" << std::endl;
		return true;
	}
	else
	{
		std::cout << "You have failed the saving throw!" << std::endl;
		return false;
	}
}


void Game::endGame()
{
	system("cls");
	if (player.relics == disboard.totalRelics)
	{
		std::cout << "Congratulations! You have found all the relics!" << std::endl;

	}
	else if (player.health == 0)
	{
		std::cout << "Game Over! You have perished in the desert." << std::endl;

	}
	else if (player.position.x == enemy.position.x && player.position.y == enemy.position.y)
	{
		std::cout << "Game Over! You have been caught by the desert's guardian." << std::endl;

	}
	printSeparator();
	std::cout << "Thank you for playing!" << std::endl;
	std::cout << "Press ENTER to exit..." << std::endl;
	std::cin.get();
	exit(0);
}