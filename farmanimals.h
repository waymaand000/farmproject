#ifndef FARMANIMALS_H
#define FARMANIMALS_H
#include <string>
#include "animal.h"
class Farmanimal : public Animal{
    public:
    std::string product;
    std::string special_drop;
    std::string print_info() override;
    Farmanimal(std::string n, int hp, int exp, std::string s, int max_hp, std::string l, int x, int y, std::string path, int imagenumber, std::string p, std::string sd);
    int get_xp();
    std::string get_sound();
    int get_max_hp();
    std::string get_loot();
    ~Farmanimal();
    
};

#endif