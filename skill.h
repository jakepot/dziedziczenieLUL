//
// Created by Jakub on 25.11.2016.
//

#ifndef SKILLS_SKILL_H
#define SKILLS_SKILL_H

#include <iostream>
#include <fstream>

using namespace std;

class skill {
    //string name;
protected:
    string name;
    string forClass;

public:
    skill(string nam, string clas);
    string writeName();
    virtual void details();
    virtual void modify();
    virtual void writeFile(fstream &file);
};


#endif //SKILLS_SKILL_H
