//
// Created by Jakub on 26.11.2016.
//

#include "buff.h"

buff::buff(string stat, int tim, bool self, int mana, string nam, string clas) : defence(self, mana, nam, clas){
    statistic = stat;
    time = tim;
}

void buff::modify() {
    cout << "Format: name clas #mana_cost selftcast(1/0) state #duration" << endl;
    defence::modify();
    cin >> time;
}

void buff::details() {
   defence::details();
    cout << "State: " << statistic << endl;
    cout << "Duration: " << time << endl;
}

void buff::writeFile(fstream &file) {
    defence::writeFile(file);
    file << statistic << endl << time << endl;
}