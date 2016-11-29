//
// Created by Jakub on 25.11.2016.
//

#include "damage.h"

damage::damage(int dmg, int targ, int mana, string nam, string clas) : offence(targ, mana, nam, clas){
    spellDmg = dmg;
}

void damage::details() {
    offence::details();
    cout << "Damage: " << spellDmg << endl;
}

void damage::fillDetails() { // dla drain
    cout << "Damage: " << spellDmg << endl;
    cout << "Max_targets: " << offence::getmaxTargets()<< endl;
}

void damage::modify() {
    offence::modify();
    cin >> spellDmg;
}

void damage::fillModify() {
    int trg;
    cin >> trg >> spellDmg;
    offence::setmaxTargets(trg);
}

void damage::writeFile(fstream &file) {
    offence::writeFile(file);
    file << spellDmg << endl;
}

void damage::fillFile(fstream &file) {
    file << offence::getmaxTargets() << endl << spellDmg << endl;
}