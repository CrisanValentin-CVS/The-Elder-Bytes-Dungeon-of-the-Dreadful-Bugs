// The Elder Bytes Dungeon of the Dreadful Bugs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//First Functional Version
//Not yet done, need to add more music/sounds and graphics,
//modify crossroads and balance stats

#define NOMINMAX
#include <windows.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <string>

#include "Intro.h"
#include "GameAudio.h"
#include "Player.h"
#include "Crossroads.h"
#include "Items.h"
#include "Monsters.h"
#include "BossBattle.h"

void clearScreen() {
    system("cls");
}

void pause() {
    std::cout << "Press Enter to continue...";
    std::cin.get();
}

bool askToContinue() {
    char choice;
    std::cout << "Do you want to continue? (Y/N): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the buffer
    return (choice == 'Y' || choice == 'y');
}

Player::HeroClass chooseHeroClass() {
    int choice;
    std::cout << "Choose a hero class:\n"
        << "1. Warrior\n"
        << "2. Archer\n"
        << "3. Wizard\n"
        << "Enter the number of your choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the buffer

    switch (choice) {
    case 1:
        return Player::HeroClass::Warrior;
    case 2:
        return Player::HeroClass::Archer;
    case 3:
        return Player::HeroClass::Wizard;
    default:
        std::cout << "Invalid choice, defaulting to Warrior.\n";
        return Player::HeroClass::Warrior;
    }
}

Monster* getRandomMonster() {
    int randIndex = std::rand() % 3;
    switch (randIndex) {
    case 0: return new Goblin();
    case 1: return new Barbarian();
    case 2: return new Dragon();
    case 3: return new Scorpion();
    case 4: return new Soldier();
    default: return new Goblin(); // Default case
    }
}

 //GameAudio::playSound("C:/Users/Crisan Valentine/Documents/ProgrammingProjects/The Elder Bytes Dungeon of the Dreadful Bugs/Exploring.wav"); // Example for exploring forest
int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed random number generator

    // Intro
    GameAudio::playSound("C:/Users/Crisan Valentine/Documents/ProgrammingProjects/The Elder Bytes Dungeon of the Dreadful Bugs/Forest.wav");

    Intro intro;
    intro.displayIntroStory();

    if (!askToContinue()) {
        std::cout << "Thank you for playing!\n";
        return 0;
    }

    std::string playerName;
    int playerHealth = 100;
    int playerLevel = 1;

    std::cout << "Enter player name: ";
    std::getline(std::cin, playerName);

    Player::HeroClass heroClass = chooseHeroClass();
    Player player(playerName, playerHealth, playerLevel, heroClass);
    player.display();

    Crossroads crossroads;
    int battleCount = 0;

    GameAudio::stopSound();

    while (crossroads.continueJourney()) {
        crossroads.explore();

        // Randomly decide whether to show the chest scene or monster battle scene
        int scene = std::rand() % 2;
        if (scene == 0) {
            // Chest scene
            GameAudio::playSound("C:\\Path\\To\\Your\\Sounds\\forest.wav"); // Example for exploring forest
            std::cout << "\nYou found a chest! Opening it...\n";
            std::string itemName = Items::getRandomItemName(player.getHeroClass());
            player.addItem(itemName);
            player.display();
        }
        else {
            // Monster battle scene
            GameAudio::playSound("C:\\Path\\To\\Your\\Sounds\\battle.wav");
            Monster* monster = getRandomMonster();
            monster->display();

            std::cout << "\nBattle begins!\n";

            while (!player.isDead() && !monster->isDead()) {
                monster->takeDamage(15);
                monster->display();

                if (!monster->isDead()) {
                    monster->attack(player);
                    player.display();
                }
            pause();
            clearScreen();
            }

            if (player.isDead()) {
                GameAudio::playSound("C:\\Path\\To\\Your\\Sounds\\player_dies.wav");
                std::cout << "\nPlayer has been defeated!\n";
                delete monster;
                break;
            }
            else {
                GameAudio::playSound("C:\\Path\\To\\Your\\Sounds\\monster_dies.wav");
                std::cout << "\nMonster has been defeated!\n";
                battleCount++;
            }

            delete monster;

            pause();
            clearScreen();
        }
        GameAudio::stopSound();

        // Trigger boss battle after 5 battles
        if (battleCount == 5) {
            GameAudio::playSound("C:\\Path\\To\\Your\\Sounds\\boss_battle.wav");
            std::cout << "\nA powerful enemy appears!\n";
            Boss boss;
            boss.display();

            while (!player.isDead() && !boss.isDead()) {
                boss.takeDamage(15);
                boss.display();

                if (!boss.isDead()) {
                    boss.attack(player);
                    player.display();
                }

                pause();
                clearScreen();

            }

            if (player.isDead()) {
                GameAudio::playSound("C:\\Path\\To\\Your\\Sounds\\player_dies.wav");
                std::cout << "\nPlayer has been defeated by Your Manager!\n";
                break;
            }
            else {
                GameAudio::playSound("C:\\Path\\To\\Your\\Sounds\\boss_dies.wav");
                std::cout << "\nYour Manager has been defeated!\n";
            }

            GameAudio::stopSound();

            pause();
            clearScreen();
        }
    }

    std::cout << "Your journey ends here. Thank you for playing!\n";
    return 0;
}