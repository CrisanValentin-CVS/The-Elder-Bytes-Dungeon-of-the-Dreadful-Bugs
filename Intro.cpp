#include "Intro.h"

void Intro::displayIntroStory() const {
    std::cout << "Welcome to The Elder Bytes: Dungeon of the Dreadful Bugs!\n\n";
    std::cin.get();
    std::cout << "\033[2J\033[1;1H";
    std::cout << "You are a software developer who has fallen asleep trying to find the boss of the bugs in your code while your colleagues are unavailable on their Teams chat and your managers are continuing to forge new projects for you from the depths of Hell. Then, you've suddenly awakened into an unknown world, and this..." << std::endl;
    std::cin.get();
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Is where your journey begins...";
    std::cin.get();
    std::cout << "\033[2J\033[1;1H";
}
