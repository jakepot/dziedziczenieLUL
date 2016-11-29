//
// Created by Jakub on 25.11.2016.
//

#include "heal.h"

heal::heal(int hp, bool self, int mana, string nam, string clas) : defence(self, mana, nam, clas){
    hpGain = hp;
}

void heal::details() {
    defence::details();
    cout << "Heal: " << hpGain << endl;
}

void heal::modify() {
    defence::modify();
    cin >> hpGain;
}

void heal::writeFile(fstream &file) {
    defence::writeFile(file);
    file << hpGain << endl;
}
