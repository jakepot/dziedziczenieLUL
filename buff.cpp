//
// Created by Jakub on 26.11.2016.
//

#include "buff.h"

buff::buff(string stat, int tim, bool self, int mana, string nam, string clas) : defence(self, mana, nam, clas){
    statistic = stat;
    time = tim;
}
