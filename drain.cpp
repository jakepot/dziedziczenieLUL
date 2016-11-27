//
// Created by Jakub on 26.11.2016.
//

#include "drain.h"

drain::drain(int tim, int dmg, int targ, int hp, bool self, int mana, string nam, string clas)
        : heal(hp, self, mana, nam, clas), damage(dmg, targ, mana, nam, clas) {
    time = tim;
}

void drain::modify() {
    cout << "Format: name clas #mana_cost #damage #heal_value #duration selfcast(1/0) #max_targets" << endl;
    cin >> this->heal::name >> this->heal::forClass >> this->heal::manaCost
        >> this->spellDmg >> this->hpGain >> this->time >> this->selfcast
        >> this->maxTargets;
}

void drain::details() {
    cout << "Name: " << heal::name << endl;
    cout << "Class: " << heal::forClass << endl;
    cout << "Mana: " << heal::manaCost << endl;
    cout << "Damage: " << spellDmg << endl;
    cout << "Heal_value: " << hpGain << endl;
    cout << "Duration: " << time << endl;
    cout << "Selfcast: " << selfcast << endl;
    cout << "Max_targets: " << maxTargets << endl;
}
