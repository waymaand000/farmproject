#include <iostream>
#include "animal.h"
#include "farmanimals.h"
#include "pets.h"
#include <raylib.h>
#include <vector>
using namespace std;

int main(void){
    int choice = 0;
    bool pink = false;
    const int screen_width = 1920;
    const int screen_height = 1080;

    vector<Animal*> animals;
    vector<Texture2D*> textures;
    //Animal test("name", 20, 30, "sound", 20, "loot");
    //cout << test.name;
    Farmanimal cow("beth", 8, 5, "moo", 8,"beef", 0, 20, "assests/cow.png",0, "milk", "leather");
    Farmanimal sheep("barry",6, 5, "bah",6, "mutton", screen_width-250, 20, "assests/sheep.png",1,"wool", "wool");
    Farmanimal chicken("buckbeak", 4, 3, "cluck", 4,"chicken",screen_width-350, screen_height-400,"assests/chicken.png",3, "egg", "feather");
    Farmanimal pig("ruben ", 8,5, "oink", 8, "pork",  0, screen_height-500, "assests/pig.png", 3, "none", "none");
    Pet dog("rufus", 10, 3, "bark", 10, "none", screen_width/2-250, 20, "assests/dog.png",  4,true, 10);
    Pet cat("kitty", 10, 3, "meow", 10, "string", (screen_width/2)-300, screen_height/2, "assests/cat.png",5, true, 10);

    animals.push_back(&cow);
    animals.push_back(&sheep);
    animals.push_back(&chicken);
    animals.push_back(&pig);
    animals.push_back(&dog);
    animals.push_back(&cat);
    

    InitWindow(screen_width,screen_height,"Minecraft Farm");

    SetTargetFPS(60);
    Texture2D Cow = LoadTexture("assests/cow.png");
    Texture2D Sheep = LoadTexture("assests/sheep.png");
    Texture2D Pig = LoadTexture("assests/pig.png");
    Texture2D Chicken= LoadTexture("assests/chicken.png");
    Texture2D Dog = LoadTexture("assests/dog.png");
    Texture2D Cat = LoadTexture("assests/cat.png");
    Texture2D PSheep = LoadTexture("assests/pinksheep.png");

    textures.push_back(&Cow);//0
    textures.push_back(&Sheep);//1
    textures.push_back(&Pig);//2
    textures.push_back(&Chicken);
    textures.push_back(&Dog);
    textures.push_back(&Cat);
    textures.push_back(&PSheep);
    //string info = "test";
    
    
     while(!WindowShouldClose()){
        
        BeginDrawing();
            string COW = cow.print_info()+" | "+ cow.makeSound();
            string SHEEP = sheep.print_info()+" | "+ sheep.makeSound();
            string PIG = pig.print_info()+" | "+ pig.makeSound();
            string CHICKEN = chicken.print_info()+" "+ chicken.makeSound();
            string DOG = dog.print_info()+" | "+ dog.makeSound();
            string CAT = cat.print_info()+" | "+ cat.makeSound();
            ClearBackground(WHITE);
            /*DrawTexture(Cow, 0, 20, WHITE);
            if (pink){
                DrawTexture(PSheep, screen_width-400, 20, WHITE);
            } else {
                DrawTexture(Sheep, screen_width-250, 20, WHITE);
            }
            
            DrawTexture(Pig, 0, screen_height-500, WHITE);
            DrawTexture(Chicken, screen_width-350, screen_height-400, WHITE);
            DrawTexture(Dog, screen_width/2-250, 20, WHITE);
            DrawTexture(Cat, (screen_width/2)-300, screen_height/2, WHITE);*/

            for (Animal* animal: animals){
                //Texture2D ani_texture = LoadTexture((animal->get_image_path()).c_str());
                //textures.push_back(&ani_texture);
                DrawTexture(*textures[animal->imagenumber], animal->getx(), animal->gety(), WHITE);
                //UnloadTexture(ani_texture);
            }
           
           
            

            if (IsMouseButtonPressed(0)){
                
                 
                if ((GetMouseX() < screen_width/3) && (GetMouseY() < screen_height/2)){
                        choice = 1;
                        if (cow.health>0){
                        cow.health-=1;}
                } else if ((GetMouseX() < screen_width*2/3) && (GetMouseX() > screen_width/3) && (GetMouseY() < screen_height/2)){
                        choice = 2;
                        if (dog.health>0){
                        dog.health-=1;}
                } else if ((GetMouseX() > screen_width*2/3) && (GetMouseY() < screen_height/2)){
                        choice = 3;
                        if (sheep.health>0){
                        sheep.health-=1;} else if(sheep.health<=0){
                            sheep.imagenumber = 6;
                            sheep.setx(screen_width-400);
                            sheep.name= "pink_barry";
                            sheep.product = "pink_wool";
                            sheep.special_drop = "pink_wool";
                            sheep.health=1000;
                        }
                } else if ((GetMouseX() < screen_width/3) && (GetMouseY() > screen_height/2)){
                        choice = 4;
                        if (pig.health>0){
                        pig.health-=1;}
                } else if ((GetMouseX() < screen_width*2/3) && (GetMouseX() > screen_width/3) && (GetMouseY() > screen_height/2)){
                        choice = 5;
                        if (cat.health>0){
                        cat.health-=1;}
                } else if ((GetMouseX() > screen_width*2/3) && (GetMouseY() > screen_height/2)){
                        choice = 6;
                        if (chicken.health>0){
                        chicken.health-=1;}
                }
            }
            if (choice==1){
                DrawText(COW.c_str(), screen_width/2-500, screen_height/2-150, 30, BLACK);
            } else if (choice==3){
                DrawText(SHEEP.c_str(), screen_width/2-500, screen_height/2-150, 30, BLACK);
            } else if (choice==4){
                DrawText(PIG.c_str(), screen_width/2-500, screen_height/2-150, 30, BLACK);
            } else if (choice==6){
                DrawText(CHICKEN.c_str(), screen_width/2-500, screen_height/2-150, 30, BLACK);
            } else if (choice==2){
                DrawText(DOG.c_str(), screen_width/2-500, screen_height/2-150, 30, BLACK);
            } else if (choice==5){
                DrawText(CAT.c_str(), screen_width/2-500, screen_height/2-150, 30, BLACK);
            } 



        EndDrawing();  
        
     }
      for (Texture2D* text : textures){
                UnloadTexture(*text);
            }
     /*UnloadTexture(Cow);
     UnloadTexture(Sheep);
     UnloadTexture(Pig);
     UnloadTexture(Chicken);
     UnloadTexture(Dog);
     UnloadTexture(Cat);*/
     CloseWindow();
     
    return 0;

}