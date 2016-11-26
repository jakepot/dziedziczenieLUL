//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_MAGIC_H
#define SKILLS_MAGIC_H


#include "skill.h"

class magic : public skill{
protected:
    int manaCost;
public:
    magic(int mana, string nam, string clas);
};


#endif //SKILLS_MAGIC_H
