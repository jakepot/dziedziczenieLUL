//
// Created by Jakub on 25.11.2016.
//

#include "magic.h"

magic::magic(int mana, string nam, string clas) : skill(nam, clas){
    manaCost = mana;
}

void magic::details() {
    skill::details();
    cout << "Mana_cost: " << manaCost << endl;
}

void magic::modify() {
    skill::modify();
    cin >> manaCost;
}

void magic::writeFile(fstream &file) {
    skill::writeFile(file);
    file << manaCost << endl;
}
