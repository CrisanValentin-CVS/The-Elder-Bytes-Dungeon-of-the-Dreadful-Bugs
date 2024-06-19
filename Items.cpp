// Items.cpp
#include "Items.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <map>

std::vector<std::string> Items::getWarriorItems() {
    return { "Sword", "Axe", "Hammer", "Heavy Armor", "Helmet", "Shield" };
}

std::vector<std::string> Items::getWizardItems() {
    return { "Fire Staff", "Frost Staff", "Earth Staff", "Robe", "Wizard Hat" };
}

std::vector<std::string> Items::getArcherItems() {
    return { "Short Bow", "Long Bow", "Javelin", "Cape", "Light Armor" };
}

std::string Items::getRandomItemName(Player::HeroClass heroClass) {
    std::vector<std::string> items;
    switch (heroClass) {
    case Player::HeroClass::Warrior:
        items = getWarriorItems();
        break;
    case Player::HeroClass::Wizard:
        items = getWizardItems();
        break;
    case Player::HeroClass::Archer:
        items = getArcherItems();
        break;
    }
    int randIndex = std::rand() % items.size();
    return items[randIndex];
}

std::map<std::string, int> Items::getItemStats(const std::string& itemName) {
    std::map<std::string, int> stats;
    if (itemName == "Sword" || itemName == "Axe" || itemName == "Hammer") {
        stats["Attack"] = 10;
    }
    else if (itemName == "Heavy Armor" || itemName == "Helmet" || itemName == "Shield") {
        stats["Defense"] = 5;
    }
    else if (itemName == "Fire Staff" || itemName == "Frost Staff" || itemName == "Earth Staff") {
        stats["Magic"] = 10;
    }
    else if (itemName == "Robe" || itemName == "Wizard Hat") {
        stats["MagicDefense"] = 5;
    }
    else if (itemName == "Short Bow" || itemName == "Long Bow" || itemName == "Javelin") {
        stats["Attack"] = 8;
    }
    else if (itemName == "Cape" || itemName == "Light Armor") {
        stats["Agility"] = 5;
    }
    return stats;
}
