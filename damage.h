//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_DAMAGE_H
#define SKILLS_DAMAGE_H


#include "offence.h"

class damage : public offence{
protected:
    int spellDmg;
public:
    damage(int dmg, int targ, int mana, string nam, string clas);
};


#endif //SKILLS_DAMAGE_H
