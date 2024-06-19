#include "Crossroads.h"
#include "Items.h"
#include "Monsters.h"
#include "Player.h"
#include <iostream>
#include <limits>

void Crossroads::choosePath() const {
    int choice;
    std::cout << "Choose a path:\n"
        << "1. Forest\n"
        << "2. Village\n"
        << "3. Cave\n"
        << "Enter the number of your choice: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the buffer

    switch (choice) {
    case 1:
        std::cout << "You venture into the forest...\n";
        break;
    case 2:
        std::cout << "You head towards the village...\n";
        break;
    case 3:
        std::cout << "You descend into the cave...\n";
        break;
    default:
        std::cout << "Invalid choice, defaulting to forest.\n";
        std::cout << "You venture into the forest...\n";
        break;
    }
}

bool Crossroads::continueJourney() const {
    char choice;
    std::cout << "Do you want to continue your journey to another crossroads? (Y/N): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the buffer
    return (choice == 'Y' || choice == 'y');
}

void Crossroads::explore() {
    choosePath();

    // Randomly decide whether to show the chest scene or monster battle scene
    int scene = std::rand() % 2;
    if (scene == 0) {
        // Chest scene
        std::cout << "You found a chest! Opening it...\n";
    }
    else {
        // Monster battle scene
        std::cout << "You encounter a monster!\n";
    }
}
