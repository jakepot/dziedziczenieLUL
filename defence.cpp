//
// Created by Jakub on 25.11.2016.
//

#include "defence.h"

defence::defence(bool self, int mana, string nam, string clas) : magic(mana, nam, clas){
    selfcast = self;
}

void defence::details() {
    magic::details();
    cout << "Selfcast: " << selfcast << endl;
}

void defence::modify() {
    magic::modify();
    cin >> selfcast;
}

void defence::writeFile(fstream &file) {
    magic::writeFile(file);
    file << selfcast << endl;
}
