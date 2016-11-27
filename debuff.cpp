//
// Created by Jakub on 25.11.2016.
//

#include "debuff.h"

debuff::debuff(string st, int tim, int targ, int mana, string nam, string clas) : offence(targ, mana, nam, clas){
    state = st;
    time = tim;
}

void debuff::modify() {
    cout << "Format: name class #mana_cost state #duration #max_targets" << endl;
    cin >> this->name >> this->forClass >> this->manaCost
        >> this->state >> this->time >> this->maxTargets;
}
