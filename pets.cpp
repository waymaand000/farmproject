#include "pets.h"
#include "animal.h"
#include <string>
using namespace std;

Pet::Pet(string n, int hp, int exp, string s, int max_hp, string l, int x, int y,string path, int imagenumber , bool t,  int lv) : Animal(n,hp,exp,s,max_hp,l,x,y,path, imagenumber), tamed(t), love(lv){
    
}
int Pet::get_xp(){
        return xp;
    }
    std::string Pet::get_sound(){
        return sound;
    }
    int Pet::get_max_hp(){
        return max_health;
    }
    std::string Pet::get_loot(){
        return loot;
    }
string Pet::print_info(){
    string info = "Info: Name: " + name + " Health: " + to_string(health) + " Experience: " + to_string(get_xp()) +" Sound: " + get_sound()+ "\n\nMax HP: " + to_string(get_max_hp()) 
    + " Loot: " + get_loot() + " Is tamed: " + to_string(tamed) + " Level of Love: " + to_string(love);
    return info;
}
Pet::~Pet(){}