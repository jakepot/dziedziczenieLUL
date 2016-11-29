//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_MELEE_H
#define SKILLS_MELEE_H


#include "phys.h"

class melee : public phys{
    string weapon;
    int critChance;
public:
    melee(string wpn, int crit, int dmg, string nam, string clas);
    void modify();
    void details();
    void writeFile(fstream &file);
};


#endif //SKILLS_MELEE_H
