//
// Created by Jakub on 25.11.2016.
//

#include "phys.h"

phys::phys(int dmg, string nam, string clas) : skill(nam, clas){
    damage = dmg;
}