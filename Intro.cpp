#include "Intro.h"

void Intro::displayIntroStory() const {
    std::cout << "Welcome to The Elder Bytes: Dungeon of the Dreadful Bugs!";
    std::cin.get();
    std::cout << "\033[2J\033[1;1H"; //clear screen
    std::cout << "You are a software developer who has fallen asleep trying to find the boss of the bugs in your code";
    std::cin.get();
    std::cout << "\033[2J\033[1;1H"; //clear screen
    std::cout << "While your colleagues are unavailable on their Teams chat";
    std::cin.get();
    std::cout << "\033[2J\033[1;1H"; //clear screen
    std::cout << "And your managers are continuing to forge new projects for you from the depths of Hell.";
    std::cin.get();
    std::cout << "\033[2J\033[1;1H"; //clear screen
    std::cout << "Then, you've suddenly awakened into an unknown world";
    std::cin.get();
    std::cout << "\033[2J\033[1;1H"; //clear screen
    std::cout << "And this...";
    std::cin.get();
    std::cout << "\033[2J\033[1;1H"; //clear screen
    std::cout << "Is where your journey begins...";
    std::cin.get();
    std::cout << "\033[2J\033[1;1H"; //clear screen
}
