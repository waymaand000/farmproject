#ifndef PETS_H
#define PETS_H
#include <string>
#include "animal.h"

class Pet : public Animal{
    public:
    bool tamed;
    int love;
    Pet(std::string n, int hp, int exp, std::string s, int max_hp, std::string l, int x, int y, std::string path, int imagenumber, bool t,  int lv);
    int get_xp();
    std::string get_sound();
    int get_max_hp();
    std::string get_loot();
    std::string print_info() override;
    ~Pet();

};

#endif