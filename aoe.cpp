//
// Created by Jakub on 26.11.2016.
//

#include "aoe.h"

aoe::aoe(int rad, int dmg, int targ, int mana, string nam, string clas) : damage(dmg, targ, mana, nam, clas){
    radius = rad;
}

void aoe::modify() {
    cout << "Format: name class #mana_cost #max_targets #damage #radius" << endl;
    damage::modify();
    cin >> radius;
}

void aoe::details() {
    damage::details();
    cout << "Radius: " << radius << endl;
}

void aoe::writeFile(fstream &file) {
    damage::writeFile(file);
    file << radius << endl;
}