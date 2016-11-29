//
// Created by Jakub on 25.11.2016.
//

#include "offence.h"

offence::offence(int targ, int mana, string nam, string clas) : magic(mana, nam, clas){
    maxTargets = targ;
}

void offence::details() {
    magic::details();
    cout << "Max_targets: " << maxTargets << endl;
}

void offence::modify() {
    magic::modify();
    cin >> maxTargets;
}

void offence::writeFile(fstream &file) {
    magic::writeFile(file);
    file << maxTargets << endl;
}

int offence::getmaxTargets() {
    return maxTargets;
}

void offence::setmaxTargets(int a) {
    maxTargets = a;
}
