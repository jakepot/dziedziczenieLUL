//
// Created by Jakub on 26.11.2016.
//

#include "aoe.h"

aoe::aoe(int rad, int dmg, int targ, int mana, string nam, string clas) : damage(dmg, targ, mana, nam, clas){
    radius = rad;
}