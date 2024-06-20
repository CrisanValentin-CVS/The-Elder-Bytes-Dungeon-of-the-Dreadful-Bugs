#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>

class Player {
public:
    enum class HeroClass {
        Warrior, Archer, Wizard
    };

    Player(const std::string& name, int health, int level, HeroClass heroClass);

    std::string getName() const;
    int getHealth() const;
    int getLevel() const;
    HeroClass getHeroClass() const;

    bool isDead() const;
    void takeDamage(int damage);
    void display() const;
    void addItem(const std::string& itemName);
    void applyItemStats(const std::map<std::string, int>& itemStats);
    void replenishHealth(int amount);

private:
    std::string name;
    int health;
    int level;
    HeroClass heroClass;
    std::map<std::string, int> stats;
};

#endif