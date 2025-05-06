#include "animal.h"
#include <string>
using namespace std;

Animal::Animal(string n, int hp, int exp, string s, int max_hp, string l, int x, int y, string path, int imagenumber) : 
name(n), health(hp), xp(exp), sound(s), max_health(max_hp), loot(l), x(x), y(y), path(path) ,imagenumber(imagenumber){
    x=100; 
    y=100;
}
string Animal::makeSound(){
    return "This animals makes the sound: " + sound;
}

int Animal::getx(){return x;}
void Animal::setx(int num){x = num;}

int Animal::gety(){return y;}

string Animal::print_info(){
    return name;
}


Animal::~Animal(){}

string Animal::get_image_path(){
    return path;
}

void Animal::set_path(string p){
    path = p;
}