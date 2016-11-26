//
// Created by Jakub on 25.11.2016.
//

#include "skill.h"

skill::skill(string nam, string clas) {
    name = nam;
    forClass = clas;
}

string skill::writeName() {
    return name;
}
