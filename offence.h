//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_OFFENCE_H
#define SKILLS_OFFENCE_H


#include "magic.h"

class offence : public magic{
    int maxTargets;
public:
    offence(int targ, int mana, string nam, string clas);
    void details();
    void modify();
    void writeFile(fstream &file);
    int getmaxTargets();
    void setmaxTargets(int a);
};


#endif //SKILLS_OFFENCE_H
