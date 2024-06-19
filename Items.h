// Items.h
#ifndef ITEMS_H
#define ITEMS_H

#include <string>
#include <vector>
#include <map>
#include "Player.h"

class Items {
public:
    enum class ItemType {
        Sword, Axe, Hammer, HeavyArmor, Helmet, Shield, // Warrior items
        FireStaff, FrostStaff, EarthStaff, Robe, WizardHat, // Wizard items
        ShortBow, LongBow, Javelin, Cape, LightArmor // Archer items
    };

    static std::string getRandomItemName(Player::HeroClass heroClass);
    static std::map<std::string, int> getItemStats(const std::string& itemName);

private:
    static std::vector<std::string> getWarriorItems();
    static std::vector<std::string> getWizardItems();
    static std::vector<std::string> getArcherItems();
};

#endif // ITEMS_H
