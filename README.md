# Arid Expanse
"Arid Expanse" is a trilogy of 2D dungeon crawler games written in C++. In this game, the player explores a randomly generated world, collecting relics while avoiding dangers. The first game is won by finding all relics and lost if the character runs out of health points. The second and third games are played in survival mode, meaning that there is no winning condition.

## Table of Contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Features](#features) <!-- \n* [Screenshots](#screenshots) --><!-- \n* [Setup](#setup) -->
* [Usage](#usage)
* [Project Status](#project-status)
* [Room for Improvement](#room-for-improvement) <!-- \n* [Acknowledgements](#acknowledgements) -->
* [Contact](#contact)
* [License](#license)


## General Information
This project is a university project and serves to solidify my understanding of classes and objects.
<!-- You don't have to answer all the questions - just the ones relevant to your project. -->


## Technologies Used
- C++


## Features
- Randomly generated 5x5 game world with different field types:  
  - **Empty Fields**: Nothing happens.  
  - **Dangers**: May cause damage to the character.  
  - **Wells**: Restore health points.  
  - **Relics**: Collect to win the game.
  - **Hunter**: An enemy hunting down the character.
- Player character with:  
  - Health points (starting at 5).  
  - Relic points (starting at 0).
  - 3 addition attributes (to be determined).  
  - Movable on the grid with user input.  
- Console-based visualization of the game world and character position.  
- Endgame conditions:  
  - Win by collecting all relics. (Game 1)
  - Lose by losing all health points.
  - Lose by getting caught by the Hunter.

## Planned Features
- Enemies that chase the player.
- Increasing difficulty as relics are collected.
- Additional character atrributes and items for enhanced gameplay.


<!-- ## Screenshots -->
<!-- ![Example screenshot](./img/screenshot.png) -->
<!-- If you have screenshots you'd like to share, include them here. -->


<!--
## Setup
What are the project requirements/dependencies? Where are they listed? A requirements.txt or a Pipfile.lock file perhaps? Where is it located?

Proceed to describe how to install / setup one's local environment / get started with the project.
-->

## Usage
- Use the keyboard (WASD) to move the character around the grid.
- Avoid dangers and collect all relics to win.
- Rest at wells to regain health points.
- Avoid the Hunter to not die.

## Project Status
Project is: _in progress_.


## Room for Improvement
<!--
Include areas you believe need improvement / could be improved. Also add TODOs for future development.
-->
<!--
Room for improvement:
- Improvement to be done 1
- Improvement to be done 2
-->
To do:
- Develop 'Stufe 3'
- Merge all three games into one.
- Create a menu in main() to select between the three games.


<!--
## Acknowledgements
Give credit here.
- This project was inspired by...
- This project was based on [this tutorial](https://www.example.com).
- Many thanks to...
-->

## Contact
Created by [@emubi50](https://www.github.com/emubi50/) - feel free to contact me!


<!-- Optional -->
## License
Default copyright laws apply. All rights are retained and the reproduction, distribution, or creation of derivative works from this project are forbidden.
<!-- This project is open source and available under the [... License](). -->

<!-- You don't have to include all sections - just the one's relevant to your project -->
