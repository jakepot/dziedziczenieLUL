//
// Created by Jakub on 25.11.2016.
//

#include "skill.h"

skill::skill(string nam, string clas) {
    name = nam;
    forClass = clas;
}

string skill::writeName() {
    return name;
}

void skill::details() {
    cout << "Name: " << name << endl;
    cout << "Class: " << forClass << endl;
}

void skill::modify() {
    cin >> name >> forClass;
}

void skill::writeFile(fstream &file) {
    file << name << endl << forClass << endl;
}
