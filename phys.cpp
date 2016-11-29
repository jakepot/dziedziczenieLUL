//
// Created by Jakub on 25.11.2016.
//

#include "phys.h"

phys::phys(int dmg, string nam, string clas) : skill(nam, clas){
    damage = dmg;
}

void phys::details() {
    skill::details();
    cout << "Damage: " << damage << endl;
}

void phys::modify() {
    skill::modify();
    cin >> damage;
}

void phys::writeFile(fstream &file) {
    skill::writeFile(file);
    file << damage << endl;
}
