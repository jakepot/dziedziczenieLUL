//
// Created by Jakub on 26.11.2016.
//

#include "single.h"

single::single(string typ, int dmg, int targ, int mana, string nam, string clas) : damage(dmg, targ, mana, nam, clas){
    type = typ;
}

void single::modify() {
    cout << "Format: name class #mana_cost #max_targets #damage type" << endl;
    damage::modify();
    cin >> type;
}

void single::details() {
    damage::details();
    cout << "Type: " << type << endl;
}

void single::writeFile(fstream &file) {
    damage::writeFile(file);
    file << type << endl;
}
