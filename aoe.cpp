//
// Created by Jakub on 26.11.2016.
//

#include "aoe.h"

aoe::aoe(int rad, int dmg, int targ, int mana, string nam, string clas) : damage(dmg, targ, mana, nam, clas){
    radius = rad;
}

void aoe::modify() {
    cout << "Format: name class #mana_cost #damage #radius #max_targets" << endl;
    cin >> this->name >> this->forClass >> this->manaCost
        >> this->spellDmg >> this->radius >> this->maxTargets;
}

void aoe::details() {
    cout << "Name: " << name << endl;
    cout << "Class: " << forClass << endl;
    cout << "Mana: " << manaCost << endl;
    cout << "Damage: " << spellDmg << endl;
    cout << "Radius: " << radius << endl;
    cout << "Max_targets: " << maxTargets << endl;
}
