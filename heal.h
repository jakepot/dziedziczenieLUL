//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_HEAL_H
#define SKILLS_HEAL_H


#include "defence.h"

class heal : public defence{
    int hpGain;
public:
    heal(int hp, bool self, int mana, string nam, string clas);
    void details();
    void modify();
    void writeFile(fstream &file);
};


#endif //SKILLS_HEAL_H
