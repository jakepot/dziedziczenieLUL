//
// Created by Jakub on 25.11.2016.
//

#include "melee.h"

melee::melee(string wpn, int crit, int dmg, string nam, string clas) : phys(dmg, nam, clas){
    weapon = wpn;
    critChance = crit;
}

void melee::details() {
    cout << "Name: " << name << endl;
    cout << "Class: " << forClass << endl;
    cout << "Damage: " << damage << endl;
    cout << "Weapon: " << weapon << endl;
    cout << "Crit_chance: " << critChance << endl;
}

void melee::modify() {
    cout << "Format: name class #damage weapon #crit_chance" << endl;
    cin >> this->name >> this->forClass >> this->damage
        >> this->weapon >> this->critChance;

}
