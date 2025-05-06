#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
    class Animal{
            public:
                std::string name;
                int health;
                virtual std::string print_info();
                Animal(std::string n, int hp, int exp, std::string s, int max_hp, std::string l, int x, int y, std::string path, int imagenumber);
                virtual ~Animal();
                int getx();
                void setx(int num);
                int gety();
                std::string get_image_path();
                void set_path(std::string p);
                int imagenumber;
                std::string makeSound();

            protected:
                int x;
                int y;
                int xp;
                std::string sound;
                int max_health;
                std::string loot;
              
                std::string path;
                

    };



#endif