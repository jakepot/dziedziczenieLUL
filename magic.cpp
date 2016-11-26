//
// Created by Jakub on 25.11.2016.
//

#include "magic.h"

magic::magic(int mana, string nam, string clas) : skill(nam, clas){
    manaCost = mana;
}