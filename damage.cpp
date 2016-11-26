//
// Created by Jakub on 25.11.2016.
//

#include "damage.h"

damage::damage(int dmg, int targ, int mana, string nam, string clas) : offence(targ, mana, nam, clas){
    spellDmg = dmg;
}
