//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_PHYS_H
#define SKILLS_PHYS_H


#include "skill.h"

class phys : public skill{
    int damage;
public:
    phys(int dmg, string nam, string clas);
    void details();
    void modify();
    void writeFile(fstream &file);
};


#endif //SKILLS_PHYS_H
