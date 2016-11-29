//
// Created by Jakub on 25.11.2016.
//

#include "debuff.h"

debuff::debuff(string st, int tim, int targ, int mana, string nam, string clas) : offence(targ, mana, nam, clas){
    state = st;
    time = tim;
}

void debuff::modify() {
    cout << "Format: name class #mana_cost #max_targets state #duration" << endl;
    offence::modify();
    cin >> this->state >> this->time;
}

void debuff::details() {
    offence::details();
    cout << "State: " << state << endl;
    cout << "Duration: " << time << endl;
}

void debuff::writeFile(fstream &file) {
    offence::writeFile(file);
    file << state << endl << time << endl;
}