//
// Created by Jakub on 25.11.2016.
//

#include "melee.h"

melee::melee(string wpn, int crit, int dmg, string nam, string clas) : phys(dmg, nam, clas){
    weapon = wpn;
    critChance = crit;
}

void melee::details() {
    phys::details();
    cout << "Weapon: " << weapon << endl;
    cout << "Crit_chance: " << critChance << endl;
}

void melee::modify() {
    cout << "Format: name class #damage weapon #crit_chance" << endl;
    phys::modify();
    cin >> weapon >> critChance;
}

void melee::writeFile(fstream &file) {
    phys::writeFile(file);
    file << weapon << endl << critChance << endl;
}
