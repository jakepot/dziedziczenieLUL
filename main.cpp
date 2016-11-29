#include <iostream>
#include <map>
#include <vector>
#include <fstream>

#include "skill.h"
#include "melee.h"
#include "ranged.h"
#include "debuff.h"
#include "buff.h"
#include "aoe.h"
#include "single.h"
#include "drain.h"

using namespace std;

vector<melee> meleeList;
vector<ranged> rangedList;
vector<debuff> debuffList;
vector<buff> buffList;
vector<aoe> aoeList;
vector<single> singleList;
vector<drain> drainList;

bool drainWasPrinted = 0;

void tree(){
    cout << "                       skill" << endl;
    cout << "                         +" << endl;
    cout << "                         |" << endl;
    cout << "         phys<-----------+---------->magic" << endl;
    cout << "          +                            +" << endl;
    cout << "          |                            |" << endl;
    cout << "melee<----+--->ranged        offence<--+-->defence" << endl;
    cout << "                               +              +" << endl;
    cout << "                               |              +------+" << endl;
    cout << "                               |                     |" << endl;
    cout << "                     debuff<---+->damage       heal<-+->buff" << endl;
    cout << "                                   +           + " << endl;
    cout << "                         +---------+--------+  |" << endl;
    cout << "                         v         v        v  v" << endl;
    cout << "                        aoe      single     drain" << endl;
}

void saveToFile(){
    fstream plik;
    plik.open("file.txt", ios::out);
    if(plik.good())
    {
        plik << meleeList.size() << endl;
        for (auto it = meleeList.begin(); it != meleeList.end(); it++){
            it->writeFile(plik);
        }
        plik << rangedList.size() << endl;
        for (auto it = rangedList.begin(); it != rangedList.end(); it++){
            it->writeFile(plik);
        }
        plik << debuffList.size() << endl;
        for (auto it = debuffList.begin(); it != debuffList.end(); it++){
            it->writeFile(plik);
        }
        plik << buffList.size() << endl;
        for (auto it = buffList.begin(); it != buffList.end(); it++){
            it->writeFile(plik);
        }
        plik << aoeList.size() << endl;
        for (auto it = aoeList.begin(); it != aoeList.end(); it++){
            it->writeFile(plik);
        }
        plik << singleList.size() << endl;
        for (auto it = singleList.begin(); it != singleList.end(); it++){
            it->writeFile(plik);
        }
        plik << drainList.size() << endl;
        for (auto it = drainList.begin(); it != drainList.end(); it++){
            it->writeFile(plik);
        }
    } else cout << "Dostep do pliku zostal zabroniony!" << endl;
    plik.close();
}

void loadFromFile(){
    string name, clas;
    int i, n;
    fstream plik;
    plik.open("file.txt", ios::in);
    if(plik.good()){
        plik >> n;
        if (n > 0){
            string wpn;
            int crit, dmg;
            for (i = 0; i < n; i++){
                plik >> name >> clas >> dmg >> wpn >> crit;
                meleeList.emplace_back(wpn, crit, dmg, name, clas);
            }
        }
        plik >> n;
        if (n > 0){
            string ammo;
            int rng, dmg;
            for (i = 0; i < n; i++){
                plik >> name >> clas >> dmg >> rng >> ammo ;
                rangedList.emplace_back(rng, ammo, dmg, name, clas);
            }
        }
        plik >> n;
        if (n > 0){
            string stat;
            int time, targ, mana;
            for (i = 0; i < n; i++){
                plik >> name >> clas >> mana >> targ >> stat >> time;
                debuffList.emplace_back(stat, time, targ, mana, name, clas);
            }
        }
        plik >> n;
        if (n > 0){
            string stat;
            int time, mana;
            bool self;
            for (i = 0; i < n; i++) {
                plik >> name >> clas >> mana >> self >> stat >> time;
                buffList.emplace_back(stat, time, self, mana, name, clas);
            }
        }
        plik >> n;
        if (n > 0){
            int rad, dmg, targ, mana;
            for (i = 0; i < n; i++){
                plik >> name >> clas >> mana >> targ >> dmg >> rad;
                aoeList.emplace_back(rad, dmg, targ, mana, name, clas);
            }
        }
        plik >> n;
        if (n > 0){
            string type;
            int dmg, targ, mana;
            for (i = 0; i < n; i++){
                plik >> name >> clas >> mana >> targ >> dmg >> type;
                singleList.emplace_back(type, dmg, targ, mana, name, clas);
            }
        }
        plik >> n;
        if (n > 0){
            int time, dmg, targ, hp, mana;
            bool self;
            for (i = 0; i < n; i++){
                plik >> name >> clas >> mana >> self >> hp >> targ >> dmg >> time;
                drainList.emplace_back(time, dmg, targ, hp, self, mana, name, clas);
            }
        }
    } else cout << "Dostep do pliku zostal zabroniony!" << endl;
    plik.close();
}

void makeObject(string dir, string name){
    string clas;
    cout << "All #numbers are integers." << endl;
    if (dir == "melee"){
        cout << "Format: class #damage weapon #crit_chance" << endl;
        string wpn;
        int crit, dmg;
        cin >> clas >> dmg >> wpn >> crit;
        meleeList.emplace_back(wpn, crit, dmg, name, clas);
    }
    else if (dir == "ranged"){
        cout << "Format: class #damage #range ammo_type" << endl;
        string ammo;
        int dmg, range;
        cin >> clas >> dmg >> range >> ammo;
        rangedList.emplace_back(range, ammo, dmg, name, clas);
    }
    else if (dir == "debuff"){
        cout << "Format: class #mana_cost state #duration #max_targets" << endl;
        int mana, time, max;
        string state;
        cin >> clas >> mana >> state >> time >> max;
        debuffList.emplace_back(state, time, max, mana, name, clas);
    }
    else if (dir == "aoe"){
        cout << "Format: class #mana_cost #damage #radius #max_targets" << endl;
        int mana, dmg, rad, max;
        cin >> clas >> mana >> dmg >> rad >> max;
        aoeList.emplace_back(rad, dmg, max, mana, name, clas);
    }
    else if (dir == "single"){
        cout << "Format: class #mana_cost #damage type #max_targets" << endl;
        int mana, dmg, max;
        string type;
        cin >> clas >> mana >> dmg >> type >> max;
        singleList.emplace_back(type, dmg, max, mana, name, clas);
    }
    else if (dir == "drain"){
        cout << "Format: clas #mana_cost #damage #heal_value #duration selfcast(1/0) #max_targets" << endl;
        int mana, dmg, heal, time, max;
        bool self;
        cin >> clas >> mana >> dmg >> heal >> time >> self >> max;
        drainList.emplace_back(time, dmg, max, heal, self, mana, name, clas);
    }
    else if (dir == "buff"){
        cout << "Format: clas #mana_cost state selftcast(1/0) #duration" << endl;
        int mana, time;
        bool self;
        string stat;
        cin >> clas >> mana >> stat >> self >> time;
        buffList.emplace_back(stat, time, self, mana, name, clas);
    }
}

void deleteObject(string dir, string name){
    if (dir == "melee"){
        for (auto it = meleeList.begin(); it != meleeList.end(); it++){
            if (it->writeName() == name){
                meleeList.erase(it);
                break;
            }
        }
    }
    else if (dir == "ranged"){
        for (auto it = rangedList.begin(); it != rangedList.end(); it++){
            if (it->writeName() == name){
                rangedList.erase(it);
                break;
            }
        }
    }
    else if (dir == "debuff"){
        for (auto it = debuffList.begin(); it != debuffList.end(); it++){
            if (it->writeName() == name){
                debuffList.erase(it);
                break;
            }
        }
    }
    else if (dir == "buff"){
        for (auto it = buffList.begin(); it != buffList.end(); it++){
            if (it->writeName() == name){
                buffList.erase(it);
                break;
            }
        }
    }
    else if (dir == "aoe"){
        for (auto it = aoeList.begin(); it != aoeList.end(); it++){
            if (it->writeName() == name){
                aoeList.erase(it);
                break;
            }
        }
    }
    else if (dir == "single"){
        for (auto it = singleList.begin(); it != singleList.end(); it++){
            if (it->writeName() == name){
                singleList.erase(it);
                break;
            }
        }
    }
    else if (dir == "drain"){
        for (auto it = drainList.begin(); it != drainList.end(); it++){
            if (it->heal::writeName() == name){
                drainList.erase(it);
                break;
            }
        }
    }
}

void modifyObject(string dir,string name){
    if (dir == "melee"){
        for (auto it = meleeList.begin(); it != meleeList.end(); it++){
            if (it->writeName() == name){
                it->modify();
                break;
            }
        }
    }
    else if (dir == "ranged"){
        for (auto it = rangedList.begin(); it != rangedList.end(); it++){
            if (it->writeName() == name){
                it->modify();
                break;
            }
        }
    }
    else if (dir == "debuff"){
        for (auto it = debuffList.begin(); it != debuffList.end(); it++){
            if (it->writeName() == name){
                it->modify();
                break;
            }
        }
    }
    else if (dir == "buff"){
        for (auto it = buffList.begin(); it != buffList.end(); it++){
            if (it->writeName() == name){
                it->modify();
                break;
            }
        }
    }
    else if (dir == "aoe"){
        for (auto it = aoeList.begin(); it != aoeList.end(); it++){
            if (it->writeName() == name){
                it->modify();
                break;
            }
        }
    }
    else if (dir == "single"){
        for (auto it = singleList.begin(); it != singleList.end(); it++){
            if (it->writeName() == name){
                it->modify();
                break;
            }
        }
    }
    else if (dir == "drain"){
        for (auto it = drainList.begin(); it != drainList.end(); it++){
            if (it->heal::writeName() == name){
                it->modify();
                break;
            }
        }
    }

}

void showDetails(string dir,string name){
    if (dir == "melee"){
        for (auto it = meleeList.begin(); it != meleeList.end(); it++){
            if (it->writeName() == name){
                it->details();
                break;
            }
        }
    }
    else if (dir == "ranged"){
        for (auto it = rangedList.begin(); it != rangedList.end(); it++){
            if (it->writeName() == name){
                it->details();
                break;
            }
        }
    }
    else if (dir == "debuff"){
        for (auto it = debuffList.begin(); it != debuffList.end(); it++){
            if (it->writeName() == name){
                it->details();
                break;
            }
        }
    }
    else if (dir == "buff"){
        for (auto it = buffList.begin(); it != buffList.end(); it++){
            if (it->writeName() == name){
                it->details();
                break;
            }
        }
    }
    else if (dir == "aoe"){
        for (auto it = aoeList.begin(); it != aoeList.end(); it++){
            if (it->writeName() == name){
                it->details();
                break;
            }
        }
    }
    else if (dir == "single"){
        for (auto it = singleList.begin(); it != singleList.end(); it++){
            if (it->writeName() == name){
                it->details();
                break;
            }
        }
    }
    else if (dir == "drain"){
        for (auto it = drainList.begin(); it != drainList.end(); it++){
            if (it->heal::writeName() == name){
                it->details();
                break;
            }
        }
    }
}

void meleeShow(){
    for (auto it = meleeList.begin(); it != meleeList.end(); it++)
        cout << it->writeName() << endl;
}

void rangedShow(){
    for (auto it = rangedList.begin(); it != rangedList.end(); it++)
        cout << it->writeName() << endl;
}

void debuffShow(){
    for (auto it = debuffList.begin(); it != debuffList.end(); it++)
        cout << it->writeName() << endl;
}

void aoeShow(){
    for (auto it = aoeList.begin(); it != aoeList.end(); it++)
        cout << it->writeName() << endl;
}

void singleShow(){
    for (auto it = singleList.begin(); it != singleList.end(); it++)
        cout << it->writeName() << endl;
}

void drainShow(){
    for (auto it = drainList.begin(); it != drainList.end(); it++)
        cout << it->heal::writeName() << endl;
}

void buffShow(){
    for (auto it = buffList.begin(); it != buffList.end(); it++)
        cout << it->writeName() << endl;
}

void traverse(string currentDir, map<string,vector<string> > dirs) {
    std::vector<string>::iterator it1 = dirs.find(currentDir)->second.begin();
    if (dirs[currentDir].size() == 0)
        if (currentDir == "drain" && drainWasPrinted == 1){}
        else
        cout << "dir:" << currentDir << endl;

    if (dirs.find(currentDir)->second.size() == 0){
        if (currentDir == "melee")
            meleeShow();
        else if (currentDir == "ranged")
            rangedShow();
        else if (currentDir == "debuff")
            debuffShow();
        else if (currentDir == "aoe")
            aoeShow();
        else if (currentDir == "single")
            singleShow();
        else if (currentDir == "drain") {
            if (drainWasPrinted == 0) {
                drainShow();
                drainWasPrinted = 1;
            }
        }
        else if (currentDir == "buff")
            buffShow();
    }

    for (; it1 != dirs.find(currentDir)->second.end(); ++it1)
        traverse(*it1, dirs);
}

int main() {

    string currentDir = "skill";

    map<string,vector<string> > map{
            {"skill",{"phys", "magic"}},
            {"phys",{"melee", "ranged"}},
            {"magic",{"offence", "defence"}},
            {"offence",{"debuff", "damage"}},
            {"defence",{"heal", "buff"}},
            {"damage",{"aoe", "single", "drain"}},
            {"heal",{"drain"}},
            {"melee",{}},
            {"ranged",{}},
            {"debuff",{}},
            {"aoe",{}},
            {"single",{}},
            {"drain",{}},
            {"buff",{}}
    };


    while(true){
        string com;
        cin >> com;
        if (com == "DIR") {
            traverse(currentDir, map);
            drainWasPrinted = 0;
        }
        if (com == "CD")
            cin >> currentDir;
        if (com == "TREE"){
            tree();
        }
        if (com == "MO"){
            string name;
            cin >> name;
            if (map.find(currentDir)->second.size() == 0)
                makeObject(currentDir, name);
            else
                cout << "Nie jestes w lisciu" << endl;
        }
        if (com == "DO"){
            string name;
            cin >> name;
            if (map[currentDir].size() == 0)
                deleteObject(currentDir, name);
            else
                cout << "Nie jestes w lisciu" << endl;
        }
        if (com == "MDO"){
            string name;
            cin >> name;
            if (map[currentDir].size() == 0)
                modifyObject(currentDir, name);
            else
                cout << "Nie jestes w lisciu" << endl;
        }
        if (com == "SHOW"){
            string name;
            cin >> name;
            if (map[currentDir].size() == 0)
                showDetails(currentDir, name);
            else
                cout << "Nie jestes w lisciu" << endl;
        }
        if (com == "SAVE"){
            saveToFile();
        }
        if (com == "LOAD"){
            loadFromFile();
        }
        if (com == "EXIT")
            break;

    }
    return 0;
}