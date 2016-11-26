//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_OFFENCE_H
#define SKILLS_OFFENCE_H


#include "magic.h"

class offence : public magic{
protected:
    int maxTargets;
public:
    offence(int targ, int mana, string nam, string clas);
};


#endif //SKILLS_OFFENCE_H
