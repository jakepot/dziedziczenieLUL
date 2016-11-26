//
// Created by Jakub on 25.11.2016.
//

#include "ranged.h"

ranged::ranged(int rng, string amm, int dmg, string nam, string clas) : phys(dmg, nam, clas){
    range = rng;
    ammo = amm;
}