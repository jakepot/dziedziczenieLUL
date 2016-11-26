//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_DEFENCE_H
#define SKILLS_DEFENCE_H


#include "magic.h"

class defence : public magic{
protected:
    bool selfcast;
public:
    defence(bool self, int mana, string nam, string clas);
};


#endif //SKILLS_DEFENCE_H
