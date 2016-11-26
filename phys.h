//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_PHYS_H
#define SKILLS_PHYS_H


#include "skill.h"

class phys : public skill{
protected:
    int damage;
public:
    phys(int dmg, string nam, string clas);
};


#endif //SKILLS_PHYS_H
