#include "Game.h"
#include <iostream>

Game::Game()
{
	system("cls");
	std::cout << "The Arid Expanse - an Oasis-Crawler" << std::endl;
	std::cout << "Press ENTER to start the game..." << std::endl;
	std::cin.get();
	run();
}

Game::~Game()
{
}

void Game::displayGame()
{
	disboard.displayWorld(player.position.x, player.position.y);
	printSeparator();
	std::cout << "Player Stats:" << std::endl;
	player.displayStats();
}

void Game::run()
{
	system("cls");
	std::cout << "In the heart of a vast, unforgiving desert lies an ancient land shrouded in mystery." <<
		std::endl << "This is the Arid Expanse, where the wind whispers of forgotten civilizations," <<
		std::endl << "and the sands hide relics of long - lost empires." <<
		std::endl << "For centuries, travelers have sought the legenary Oasis of the Sands," <<
		std::endl << "a fabled haven said to grant unimaginable power to those who find it." <<
		std::endl << "But few have returned, and those who do speak only in hushed tones of strange creatures," <<
		std::endl << "treacherous terrain, and the unforgiving forces that guard the desert." <<
		std::endl << "Now, you find yourself on a journey into this desolate land," <<
		std::endl << "armed with nothing but your wits, your will, and the hope of uncovering the truth buried beneath the dunes." << std::endl;
	std::cout << "Press ENTER to continue..." << std::endl;
	std::cin.get();
	system("cls");
	std::cout << "The sun is relentless, and the desert waits..." << std::endl;
	do
	{
		printSeparator();
		displayGame();
		char command = readPrompt();
		movePlayer(command);
		system("cls");
		evaluateField();
		disboard.previousPosition = player.position;
	} while (player.health > 0 && player.relics < disboard.totalRelics);
}

void Game::printSeparator()
{
	std::cout << "----------------------------------------" << std::endl;
}

char Game::readPrompt()
{
	std::cout << "Use WASD to move: ";
	char command;
	std::cin.get(command);
	std::cin.ignore(1000, '\n');
	return command;
}

void Game::movePlayer(char command)
{
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
		}
		break;
	case 's':
	case 'S':
		if (player.position.y < 4)
		{
			player.position.y++;
		}
		else
		{
			std::cout << "You can't move there!" << std::endl;
		}
		break;
	case 'd':
	case 'D':
		if (player.position.x < 4)
		{
			player.position.x++;
		}
		else
		{
			std::cout << "You can't move there!" << std::endl;
		}
		break;
	default:
		break;
	}
}

void Game::evaluateField()
{
	Field currentField = disboard.world[player.position.y][player.position.x];
	if (player.position.x == disboard.previousPosition.x && player.position.y == disboard.previousPosition.y)
	{
		switch (rand() % 3)
		{
		case 0:
			std::cout << "You step forward, but the desert's edge looms ahead." <<
				std::endl << "The scorching wind howls in your ears, and the sand stretches endlessly into a vast nothingness." <<
				std::endl << "There is no path here... only an empty, unforgiving void" <<
				std::endl << "that serves as a reminder of the boundaries of the known world." <<
				std::endl << "You can't go that way." << std::endl;
			break;
		case 1:
			std::cout << "The desert sands shift around you, but the horizon ahead is a barren wasteland." <<
				std::endl << "There's nothing beyond, just an endless stretch of emptiness and silence." <<
				std::endl << "A warning in the air tells you that this is not a place to venture." <<
				std::endl << "You can't go any further." << std::endl;
			break;
		case 2:
			std::cout << "You take a step beyond the familiar sands, but the ground crumbles beneath your feet," <<
				std::endl << "and a sudden gust of wind seems to push you back." <<
				std::endl << "The desert is unforgiving to those who stray too far" <<
				std::endl << "You turn back, knowing you can't go that way." << std::endl;
		}
		return;
	}
	switch (currentField.type)
	{
	case Field::FieldType::EMPTY:
		switch (rand() % 3)
		{
			case 0:
				std::cout << "The vast desert stretches endlessly around you." <<
					std::endl << "The heat is oppressive, and the silence is broken only by the occasional gust of wind sweeping through the dunes." << std::endl;
				break;
			case 1:
				std::cout << "The barren sands shift beneath your feet." <<
					std::endl << "There's nothing but the scorching sun and the emptiness of the desert surrounding you." << std::endl;
				break;
			case 2:
				std::cout << "You stand in a lonely patch of sand, with no signs of life in sight." <<
					std::endl << "The horizon seems distant, and the sun beats down relentlessly." << std::endl;
		}
		break;
	case Field::FieldType::DANGER:
		if (rand() % 6 == 0)
		{
			switch (rand() % 3)
			{
			case 0:
				std::cout << "A sudden roar erupts from the ground as a venomous desert serpent strikes!" <<
					std::endl << "You try to dodge, but it sinks its fangs into your leg," <<
					std::endl << "and you feel a sharp pain as venom courses through your veins." << std::endl;
				break;
			case 1:
				std::cout << "The ground beneath you gives way, and you fall into a hidden trap!" <<
					std::endl << "You land hard, your body aching from the fall," <<
					std::endl << "as you hear the hiss of hidden creatures stirring nerby." << std::endl;
				break;
			case 2:
				std::cout << "A sandstorm hits with brutal force, and as you try to shield yourself," <<
					std::endl << "a sharp rock cuts across your arm." <<
					std::endl << "The sting is fierce, and the blood flows, but you press on." << std::endl;
			}
			player.health--;
		}
		else {
			switch (rand() % 3)
			{
			case 0:
				std::cout << "As you tread carefully through the rocky desert, the ground suddenly shifts, and a hidden pit opens beneath you!" <<
					std::endl << "But you leap back just in time, narrowly avoiding a dangerous fall." << std::endl;
				break;
			case 1:
				std::cout << "The air crackles with tension as a sandstorm begins to whip around you." <<
					std::endl << "You manage to shield your eyes just in time, but the storm's fury is relentless." << std::endl;
				break;
			case 2:
				std::cout << "The sands beneath you seem to come alive as you encounter quicksand." <<
					std::endl << "You leap to the side just as the ground shifts, narrowly escaping its grasp." << std::endl;
			}
		}
		break;
	case Field::FieldType::WELL:
		switch (rand() % 3)
		{
		case 0:
			std::cout << "You've found a rare oasis in the desert," <<
				std::endl << "the cool water of the well offering a moment of peace in the scorching heat." <<
				std::endl << "You take a moment to rest and recover." << std::endl;
			break;
		case 1:
			std::cout << "The well offers some much-needed respite." <<
				std::endl << "You drink deeply, the water cool and refreshing," <<
				std::endl << "before sitting to regain your strength." << std::endl;
			break;
		case 2:
			std::cout << "The well stands as a rare symbol of life in the desert." <<
				std::endl << "The water offers a brief moment of comfort in this unforgiving land." <<
				std::endl << "You take a deep breath and rest." << std::endl;
		}
		player.health++;
		break;
	case Field::FieldType::RELIC:
		switch (rand() % 3)
		{
		case 0:
			std::cout << "You stumble upon a relic half-buried in the sand." <<
				std::endl << "It's a weathered artifact, its mysterious symbols almost glowing in the sunlight." <<
				std::endl << "Could this be an ancient treasure?" << std::endl;
			break;
		case 1:
			std::cout << "A hidden relic catches your eye, its surface etched with forgotton runes." <<
				std::endl << "You can feel its power, faint but undeniable, calling you to take it." << std::endl;
			break;
		case 2:
			std::cout << "Among the dunes, you uncover an ancient relic, a symbol of a long-lost civilization." <<
				std::endl << "The air feels charged as you lay your hands upon it, and you wonder what secrets it holds." << std::endl;
		}
		player.relics++;
		break;
	default:
		break;
	}
	disboard.world[player.position.y][player.position.x].type = Field::FieldType::EMPTY;
	if (player.health <= 0)
	{
		printSeparator();
		std::cout << "The desert has claimed you." <<
			std::endl << "After counteless of battles against the harsh terrain and it's dangers," <<
			std::endl << "your strength has finally been exhausted. The sun, relentless and unyielding," <<
			std::endl << "burns the last remnants of your will as the sands swallow you whole." <<
			std::endl << "The Oasis of the Sands remains beyond your reach... for now." << std::endl;
		printSeparator();
		std::cout << "You died!" << std::endl;
		std::cout << "You found " << player.relics << " relics." << std::endl;
		std::cout << "Game Over!" << std::endl;
		exit(0);
	}
	if (player.relics >= disboard.totalRelics)
	{
		printSeparator();
		std::cout << "Against all odds, you stand victorious amidst the endless dunes." <<
			std::endl << "The relics, long hidden by time and the shifting sands, are now yours." <<
			std::endl << "The power they hold flows through you," <<
			std::endl << "granting you insight into the lost civilization that once ruled these lands." <<
			std::endl << "You've unlocked the secrets of the desert and discovered the true legacy of the Oasis of the sands." <<
			std::endl << "The desert may be ast, but you have conquered it." << std::endl;
		printSeparator();
		std::cout << "You found all relics!" << std::endl;
		std::cout << "You win!" << std::endl;
		std::cout << "Congratulations!" << std::endl;
		exit(0);
	}
}