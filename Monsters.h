#ifndef MONSTERS_H
#define MONSTERS_H

#include <string>
#include <iostream>
#include "Player.h"

class Monster {
public:
    Monster(const std::string& name, int health, int attackPower);
    virtual ~Monster() = default;

    virtual void display() const;
    virtual void attack(Player& player) const;
    virtual void takeDamage(int damage);
    virtual bool isDead() const;

protected:
    std::string name;
    int health;
    int attackPower;
};

class Goblin : public Monster {
public:
    Goblin();
};

class Barbarian : public Monster {
public:
    Barbarian();
};

class Scorpion : public Monster {
public:
    Scorpion();
};

class Soldier : public Monster {
public:
    Soldier();
};

class Dragon : public Monster {
public:
    Dragon();
};

#endif // MONSTER_H
