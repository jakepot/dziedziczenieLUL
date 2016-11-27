//
// Created by Jakub on 26.11.2016.
//

#include "buff.h"

buff::buff(string stat, int tim, bool self, int mana, string nam, string clas) : defence(self, mana, nam, clas){
    statistic = stat;
    time = tim;
}

void buff::modify() {
    cout << "Format: name clas #mana_cost state selftcast(1/0) #duration" << endl;
    cin >> this->name >> this->forClass >> this->manaCost >> this->statistic
        >> this->selfcast >> this->time;
}
