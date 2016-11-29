//
// Created by Jakub on 26.11.2016.
//

#include "drain.h"

drain::drain(int tim, int dmg, int targ, int hp, bool self, int mana, string nam, string clas)
        : heal(hp, self, mana, nam, clas), damage(dmg, targ, mana, nam, clas) {
    time = tim;
}

void drain::modify() {
    cout << "Format: name clas #mana_cost selfcast(1/0) #heal_value #max_targets #damage #duration" << endl;
    heal::modify();
    damage::fillModify();
    cin >> time;
}

void drain::details() {
    heal::details();
    damage::fillDetails();
    cout << "Duration: " << time << endl;
}

void drain::writeFile(fstream &file) {
    heal::writeFile(file);
    damage::fillFile(file);
    file << time << endl;
}
