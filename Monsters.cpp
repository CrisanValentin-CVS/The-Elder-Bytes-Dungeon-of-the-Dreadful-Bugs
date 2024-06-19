#include "Monsters.h"

Monster::Monster(const std::string& name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {}

void Monster::display() const {
    std::cout << "Monster: " << name << ", Health: " << health << std::endl;
}

void Monster::attack(Player& player) const {
    std::cout << name << " attacks the player for " << attackPower << " damage!" << std::endl;
    player.takeDamage(attackPower);
}

void Monster::takeDamage(int damage) {
    health -= damage;
}

bool Monster::isDead() const {
    return health <= 0;
}

Goblin::Goblin() : Monster("Goblin", 20, 3) {}

Barbarian::Barbarian() : Monster("Barbarian", 30, 5) {}

Scorpion::Scorpion() : Monster("Scorpion", 40, 10) {}

Soldier::Soldier() : Monster("Soldier", 50, 15) {}

Dragon::Dragon() : Monster("Dragon", 100, 20) {}
