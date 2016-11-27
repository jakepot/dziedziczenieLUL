//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_DEBUFF_H
#define SKILLS_DEBUFF_H


#include "offence.h"

class debuff : public offence{
protected:
    string state;
    int time;
public:
    debuff(string st, int tim, int targ, int mana, string nam, string clas);
    void modify();
};


#endif //SKILLS_DEBUFF_H
