//
// Created by Jakub on 26.11.2016.
//

#include "single.h"

single::single(string typ, int dmg, int targ, int mana, string nam, string clas) : damage(dmg, targ, mana, nam, clas){
    type = typ;
}
