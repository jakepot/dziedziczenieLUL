//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_DAMAGE_H
#define SKILLS_DAMAGE_H


#include "offence.h"

class damage : public offence{
    int spellDmg;
public:
    damage(int dmg, int targ, int mana, string nam, string clas);
    void details();
    void fillDetails();
    void modify();
    void fillModify();
    void writeFile(fstream &file);
    void fillFile(fstream &file);
};


#endif //SKILLS_DAMAGE_H
