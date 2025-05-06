#include "farmanimals.h"
#include "animal.h"
#include <string>
using namespace std;

Farmanimal::Farmanimal(string n, int hp, int exp, string s, int max_hp, string l, int x, int y, string path, int imagenumber, string p,  string sd) : Animal(n,hp,exp,s,max_hp,l,x,y,path, imagenumber), product(p), special_drop(sd){

}
    int Farmanimal::get_xp(){
        return xp;
    }
    std::string Farmanimal::get_sound(){
        return sound;
    }
    int Farmanimal::get_max_hp(){
        return max_health;
    }
    std::string Farmanimal::get_loot(){
        return loot;
    }
string Farmanimal::print_info(){
    string info = "Info: Name: " + name + " Health: " + to_string(health) + " Experience: " + to_string(get_xp()) +" Sound: " + get_sound()+ "\n\nMax HP: " + to_string(get_max_hp()) 
    + " Loot: " + get_loot() + " Product: " + product + " Special Drop: " + special_drop;
    return info;
}

Farmanimal::~Farmanimal(){}