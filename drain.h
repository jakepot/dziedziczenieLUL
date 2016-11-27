//
// Created by Jakub on 26.11.2016.
//

#ifndef SKILLS_DRAIN_H
#define SKILLS_DRAIN_H


#include "damage.h"
#include "heal.h"

class drain : public damage, public heal{
    int time;
public:
    drain(int tim, int dmg, int targ, int hp, bool self, int mana, string nam, string clas);
    void modify();
    void details();
};

#endif //SKILLS_DRAIN_H

//! ! ! ! ! ! ! ! ! NEEDS VIRTUAL INHERITANCE