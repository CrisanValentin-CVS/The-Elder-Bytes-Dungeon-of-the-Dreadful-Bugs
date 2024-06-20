// The Elder Bytes Dungeon of the Dreadful Bugs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//First Functional Version
//Not yet done, need to add graphics,
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
    std::cout << "\033[2J\033[1;1H";
}

void pause() {
    std::cout << "Press Enter to continue...";
    std::cin.get();
}

void playSceneMusic(Crossroads::Scene scene) {
    std::string sceneSound;
    switch (scene) {
    case Crossroads::Scene::Forest:
        sceneSound = "Intro.wav";
        break;
    case Crossroads::Scene::Village:
        sceneSound = "Village.wav";
        break;
    case Crossroads::Scene::Cave:
        sceneSound = "Cave.wav";
        break;
    }
    GameAudio::playSound(sceneSound);
}

void playMonsterIntroAndBattleMusic(Monster* monster) {
    std::string introSound;
    std::string battleSound;

    if (dynamic_cast<Goblin*>(monster)) {
        introSound = "GoblinIntro.wav";
        battleSound = "GoblinBattle.wav";
    }
    else if (dynamic_cast<Barbarian*>(monster)) {
        introSound = "BarbarianIntro.wav";
        battleSound = "BarbarianBattle.wav";
    }
    else if (dynamic_cast<Dragon*>(monster)) {
        introSound = "DragonIntro.wav";
        battleSound = "DragonBattle.wav";
    }
    else if (dynamic_cast<Scorpion*>(monster)) {
        introSound = "ScorpionIntro.wav";
        battleSound = "ScorpionBattle.wav";
    }
    else if (dynamic_cast<Soldier*>(monster)) {
        introSound = "SoldierIntro.wav";
        battleSound = "SoldierBattle.wav";
    }

    GameAudio::playSound(introSound);
    Sleep(3000); // Wait for the intro sound to finish (adjust time as needed)
    GameAudio::playSound(battleSound);
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
    int randIndex = std::rand() % 5;
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
bool startGame() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed random number generator

    // Intro
    GameAudio::playSound("Intro.wav");

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

    pause();
    clearScreen();

    Crossroads crossroads;
    int battleCount = 0;

    GameAudio::stopSound();

    while (crossroads.continueJourney()) {
        crossroads.explore();

        // Randomly decide whether to show the chest scene or monster battle scene
        int scene = std::rand() % 2;
        if (scene == 0) {
            // Chest scene
            playSceneMusic(crossroads.getCurrentScene());
            std::cout << "\nYou found a chest! Opening it...\n";
            std::string itemName = Items::getRandomItemName(player.getHeroClass());
            player.addItem(itemName);
            player.display();

            pause();
            clearScreen();
        }

        else {
            // Monster battle scene
            Monster* monster = getRandomMonster();
            monster->display();
            playMonsterIntroAndBattleMusic(monster);

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
                GameAudio::playSound("PlayerDies.wav");
                std::cout << "\nPlayer has been defeated!\n";
                delete monster;
                break;
            }
            else {
                GameAudio::playSound("MonsterDies.wav");
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
            GameAudio::playSound("BossIntro.wav");
            std::cout << "\nA powerful enemy appears!\n";
            Boss boss;
            GameAudio::playSound("BossBattle.wav");
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
                GameAudio::playSound("PlayerDies.wav");
                std::cout << playerName << " has been defeated by Your Manager!\n";
                break;
            }
            else {
                GameAudio::playSound("ManagerDies.wav");
                std::cout << "\nYour Manager has been defeated!\n";
            }

            GameAudio::stopSound();

            pause();
            clearScreen();
        }
    }

    std::cout << "Your journey ends here. Thank you for playing!\n";
    return true;
}

int main() {
    do {
        clearScreen();
    } while (startGame() && askToContinue());

    std::cout << "Thank you for playing!\n";
    return 0;
}