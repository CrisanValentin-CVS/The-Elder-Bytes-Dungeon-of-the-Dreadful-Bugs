#ifndef BOSSBATTLE_H
#define BOSSBATTLE_H

#include "Player.h"
#include "Monsters.h"

class Boss : public Monster {
public:
    Boss();
    void attack(Player& player) const override;
};

#endif // BOSS_H
