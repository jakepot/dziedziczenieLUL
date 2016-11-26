//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_MELEE_H
#define SKILLS_MELEE_H


#include "phys.h"

class melee : public phys{
private:
    string weapon;
    int critChance;
public:
    melee(string wpn, int crit, int dmg, string nam, string clas);
    void details();
};


#endif //SKILLS_MELEE_H
