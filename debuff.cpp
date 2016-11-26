//
// Created by Jakub on 25.11.2016.
//

#include "debuff.h"

debuff::debuff(string st, int tim, int targ, int mana, string nam, string clas) : offence(targ, mana, nam, clas){
    state = st;
    time = tim;
}