//
// Created by Jakub on 25.11.2016.
//

#include "heal.h"

heal::heal(int hp, bool self, int mana, string nam, string clas) : defence(self, mana, nam, clas){
    hpGain = hp;
}