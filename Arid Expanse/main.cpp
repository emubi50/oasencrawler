#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Game.h"


int main()
{
    srand(time(NULL));
    int stage = 0;
    do
    {
        system("cls");
        std::cout << "The Arid Expanse Trilogy" << std::endl;
        std::cout << "Select Game:" << std::endl;
        std::cout << "1. Oasis of Sands" << std::endl;
        std::cout << "2. Echoes of Dunes" << std::endl;
        std::cout << "3. Mirage of Fate" << std::endl;
        std::cout << "Enter Number (1/2/3) of Game:" << std::endl;
        std::cin >> stage;
        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

    }
    while (stage < 1 || stage > 3);
    Game game(stage);
    game.startGame();
    return 0;
}
