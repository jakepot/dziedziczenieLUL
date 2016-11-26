//
// Created by Jakub on 25.11.2016.
//

#include "defence.h"

defence::defence(bool self, int mana, string nam, string clas) : magic(mana, nam, clas){
    selfcast = self;
}