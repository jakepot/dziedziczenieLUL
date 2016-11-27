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
    cin >> this->name >> this->forClass >> this->damage
        >> this->range >> this->ammo;
}

void ranged::details() {
    cout << "Name: " << name << endl;
    cout << "Class: " << forClass<< endl;
    cout << "Damage: " << damage << endl;
    cout << "Range: " << range << endl;
    cout << "Ammo: " << ammo << endl;
}
