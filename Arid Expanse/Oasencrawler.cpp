// Oasencrawler.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.  
//  

#include <iostream>  
#include <stdlib.h>  
#include <time.h>  
#include "Game.h"  

int main()  
{  
   srand((unsigned int)time(NULL));  
   int level = 0;  
   do  
   {  
       system("cls");  
       std::cout << "The Arid Expanse Trilogy" << std::endl;  
       std::cout << "Select Game:" << std::endl;  
       std::cout << "1. Oasis of Sands" << std::endl;  
       std::cout << "2. Echoes of Dunes" << std::endl;  
       std::cout << "3. Mirage of Fate" << std::endl;  
       std::cout << "Enter Number (1/2/3) of Game:" << std::endl;  
       std::cin >> level;  

   } while (level < 1 || level > 3);  
   Game game(level);  
   game.startGame();
}  

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"  
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"  

// Tipps für den Einstieg:  
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.  
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.  
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.  
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.  
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.  
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
