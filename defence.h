//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_DEFENCE_H
#define SKILLS_DEFENCE_H


#include "magic.h"

class defence : public magic{
    bool selfcast;
public:
    defence(bool self, int mana, string nam, string clas);
    void details();
    void modify();
    void writeFile(fstream &file);
};


#endif //SKILLS_DEFENCE_H
