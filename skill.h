//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_SKILL_H
#define SKILLS_SKILL_H

#include <iostream>

using namespace std;

class skill {
    //string name;
protected:
    string name;
    string forClass;

public:
    skill(string nam, string clas);
    //skill(){};
    string writeName();
};


#endif //SKILLS_SKILL_H
