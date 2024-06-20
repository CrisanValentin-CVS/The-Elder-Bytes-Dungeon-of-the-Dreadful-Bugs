#include "Player.h"
#include "Items.h"
#include <iostream>
#include <string>

Player::Player(const std::string& name, int health, int level, HeroClass heroClass)
    : name(name), health(health), level(level), heroClass(heroClass) {
    stats["Attack"] = 10;
    stats["Defense"] = 15;
    stats["Magic"] = 5;
    stats["MagicDefense"] = 3;
    stats["Agility"] = 2;
}

std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getLevel() const {
    return level;
}

Player::HeroClass Player::getHeroClass() const {
    return heroClass;
}

bool Player::isDead() const {
    return health <= 0;
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

void Player::display() const {
    std::cout << "Player: " << name << "\nHealth: " << health << "\nLevel: " << level << "\n";
    std::cout << "Stats:\n";
    for (const auto& stat : stats) {
        std::cout << stat.first << ": " << stat.second << "\n";
    }
    std::cout << std::endl;
}

void Player::addItem(const std::string& itemName) {
    std::cout << "You received a " << itemName << "!\n";
    std::map<std::string, int> itemStats = Items::getItemStats(itemName);
    applyItemStats(itemStats);
}

void Player::applyItemStats(const std::map<std::string, int>& itemStats) {
    for (const auto& stat : itemStats) {
        stats[stat.first] += stat.second;
    }
}
