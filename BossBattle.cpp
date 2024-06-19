#include "BossBattle.h"
#include <iostream>

Boss::Boss() : Monster("Your Manager", 200, 20) { }

void Boss::attack(Player& player) const {
    std::cout << "Your Manager attacks with a performance review!\n";
    player.takeDamage(20); //Boss Attack
}
