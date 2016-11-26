//
// Created by Jakub on 25.11.2016.
//

#include "offence.h"

offence::offence(int targ, int mana, string nam, string clas) : magic(mana, nam, clas){
    maxTargets = targ;
}
