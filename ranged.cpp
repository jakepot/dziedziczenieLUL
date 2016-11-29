//
// Created by Jakub on 25.11.2016.
//

#include "ranged.h"

ranged::ranged(int rng, string amm, int dmg, string nam, string clas) : phys(dmg, nam, clas){
    range = rng;
    ammo = amm;
}

void ranged::modify() {
    cout << "Format: name class #damage #range ammo_type" << endl;
    phys::modify();
    cin >> range >> ammo;
}

void ranged::details() {
    phys::details();
    cout << "Range: " << range << endl;
    cout << "Ammo: " << ammo << endl;
}

void ranged::writeFile(fstream &file) {
    phys::writeFile(file);
    file << range << endl << ammo << endl;
}