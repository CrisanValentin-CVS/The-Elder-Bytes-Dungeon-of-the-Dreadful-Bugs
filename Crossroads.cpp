#include "Crossroads.h"
#include "Items.h"
#include "Monsters.h"
#include "Player.h"
#include <iostream>
#include <limits>
#include <cstdlib>

Crossroads::Crossroads() : currentScene(Scene::Forest) {}

bool Crossroads::continueJourney() {
    char choice;
    std::cout << "Do you want to continue your journey? (Y/N): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the buffer
    return (choice == 'Y' || choice == 'y');
}

void Crossroads::explore() {
    int choice;
    std::cout << "You have reached a crossroads. Where do you want to go?\n"
        << "1. Forest\n"
        << "2. Village\n"
        << "3. Cave\n"
        << "Enter the number of your choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the buffer

    switch (choice) {
    case 1:
        currentScene = Scene::Forest;
        std::cout << "You are now exploring the forest.\n";
        break;
    case 2:
        currentScene = Scene::Village;
        std::cout << "You are now exploring the village.\n";
        break;
    case 3:
        currentScene = Scene::Cave;
        std::cout << "You are now exploring the cave.\n";
        break;
    default:
        std::cout << "Invalid choice, staying in the current scene.\n";
    }
}

Crossroads::Scene Crossroads::getCurrentScene() const {
    return currentScene;
}
