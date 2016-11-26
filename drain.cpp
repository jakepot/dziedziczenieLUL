//
// Created by Jakub on 26.11.2016.
//

#include "drain.h"

drain::drain(int tim, int dmg, int targ, int hp, bool self, int mana, string nam, string clas)
        : heal(hp, self, mana, nam, clas), damage(dmg, targ, mana, nam, clas) {
    time = tim;
}
